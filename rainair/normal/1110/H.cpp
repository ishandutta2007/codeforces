#include <algorithm>
#include <iostream>
#include <cstring>
#include <climits>
#include <cstdlib>
#include <cstdio>
#include <bitset>
#include <vector>
#include <cmath>
#include <ctime>
#include <queue>
#include <stack>
#include <map>
#include <set>

#define fi first
#define se second
#define U unsigned
#define P std::pair<int,int>
#define LL long long
#define pb push_back
#define MP std::make_pair
#define all(x) x.begin(),x.end()
#define CLR(i,a) memset(i,a,sizeof(i))
#define FOR(i,a,b) for(int i = a;i <= b;++i)
#define ROF(i,a,b) for(int i = a;i >= b;--i)
#define DEBUG(x) std::cerr << #x << '=' << x << std::endl

const int MAXN = 30000 + 5;
const int MAXM = 2000 + 5;

int ch[MAXN][10],fail[MAXN];
int g[MAXN][MAXM];
int tot = 1,rt = 1;
int n;
char L[MAXN],R[MAXN];
std::vector<int> G[MAXN];

inline int get(int x,int y){
	if(!ch[x][y]) ch[x][y] = ++tot;
	return ch[x][y];
}

inline void build(){
	int lenL = strlen(L+1),lenR = strlen(R+1);
	int u = 1,v = 1;
	if(lenL == lenR){
		FOR(i,1,lenL){
			if(u == v){
				FOR(k,L[i]-'0'+1,R[i]-'0'-1) g[get(u,k)][lenL-i]++;
				u = get(u,L[i]-'0');
				v = get(v,R[i]-'0');
			}
			else{
				FOR(k,L[i]-'0'+1,9) g[get(u,k)][lenL-i]++;
				u = get(u,L[i]-'0');
				FOR(k,i==1,R[i]-'0'-1) g[get(v,k)][lenR-i]++;
				v = get(v,R[i]-'0');
			}
		}
		g[u][0]++;if(u != v) g[v][0]++;
	}
	else{
		FOR(i,1,lenL){
			FOR(k,L[i]-'0'+1,9) g[get(u,k)][lenL-i]++;
			u = get(u,L[i]-'0');
		}
		FOR(i,1,lenR){
			FOR(k,i==1,R[i]-'0'-1) g[get(v,k)][lenR-i]++;
			v = get(v,R[i]-'0');
		}
		FOR(i,lenL+1,lenR-1) FOR(j,1,9) g[get(rt,j)][i-1]++;
		g[u][0]++;g[v][0]++;
	}
	// ~~~
	std::queue<int> q;
	FOR(i,0,9){
		if(ch[rt][i]) fail[ch[rt][i]] = rt,q.push(ch[rt][i]);
		else ch[rt][i] = rt;
	}
	while(!q.empty()){
		int v = q.front();q.pop();
		FOR(i,0,n) g[v][i] += g[fail[v]][i];
		FOR(i,0,9){
			if(ch[v][i]){
				fail[ch[v][i]] = ch[fail[v]][i],q.push(ch[v][i]);
			}
			else ch[v][i] = ch[fail[v]][i];
		}
	}
	FOR(i,1,tot) FOR(j,1,n) g[i][j] += g[i][j-1];
	FOR(i,1,tot) FOR(j,0,9) G[ch[i][j]].pb(i);
}

int f[MAXM][MAXN],ans;
bool use[MAXM][MAXN];
//  i  j 

inline void bfs(){
	std::queue<P> q;
	FOR(i,1,tot) if(f[n][i] == ans) q.push(MP(n,i)),use[n][i] = 1;
	while(!q.empty()){
		P v = q.front();q.pop();
		if(!v.fi) continue;
		for(auto x:G[v.se]){
			if(f[v.fi-1][x]+g[v.se][n-v.fi] == f[v.fi][v.se] && !use[v.fi-1][x]){
				q.push(MP(v.fi-1,x));use[v.fi-1][x] = 1;
			}
		}
	}
}

int main(){
	scanf("%s%s%d",L+1,R+1,&n);
	build();
	FOR(i,0,n) FOR(v,1,tot) f[i][v] = -1e9;
	f[0][1] = 0;
	FOR(i,0,n-1){
		FOR(v,1,tot){
			if(f[i][v] < 0) continue;
			FOR(k,0,9){
				if(!ch[v][k]) continue;
				f[i+1][ch[v][k]] = std::max(f[i+1][ch[v][k]],f[i][v]+g[ch[v][k]][n-i-1]);
			}
		}
	}
	ans = -1e9;
	FOR(v,1,tot) ans = std::max(ans,f[n][v]);
	printf("%d\n",ans);
	bfs();
	int now = 1;
	FOR(i,0,n-1){
		FOR(j,0,9){
			if(use[i+1][ch[now][j]] && f[i+1][ch[now][j]] == f[i][now]+g[ch[now][j]][n-i-1]){
				printf("%d",j);
				now = ch[now][j];break;
			}
		}
	}
	puts("");
	return 0;
}
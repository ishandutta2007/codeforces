#include <bits/stdc++.h>

#define fi first
#define se second
#define db double
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

const int MAXN = 4e5 + 5;
int k;
char str[MAXN];
int ch[MAXN][14],fail[MAXN],tot = 1,rt = 1;
int sm[MAXN];

inline void insert(char str[],int val){
	int len = strlen(str+1);int v = rt;
	FOR(i,1,len){
		if(!ch[v][str[i]-'a']) ch[v][str[i]-'a'] = ++tot;
		v = ch[v][str[i]-'a'];
	}
	sm[v] += val;
}

std::vector<int> G[MAXN];

inline void dfs(int v){
	for(auto x:G[v]){
		sm[x] += sm[v];
		dfs(x);
	}
}

inline void build(){
	std::queue<int> q;
	FOR(i,0,13){
		if(ch[rt][i]) q.push(ch[rt][i]),fail[ch[rt][i]] = rt;
		else ch[rt][i] = rt;
	}
	while(!q.empty()){
		int v = q.front();q.pop();
		FOR(i,0,13){
			if(ch[v][i]) q.push(ch[v][i]),fail[ch[v][i]] = ch[fail[v]][i];
			else ch[v][i] = ch[fail[v]][i];
		}
	}
	FOR(i,1,tot) G[fail[i]].pb(i);
	dfs(1);
}

LL f[2][(1<<14)+3][1005];
int to[MAXN];LL val[MAXN];

inline void trans(int l,int r){
	FOR(i,1,tot){
		to[i] = i;val[i] = 0;
		FOR(j,l,r){
			to[i] = ch[to[i]][str[j]-'a'];
			val[i] += sm[to[i]];
		}
	}
}

inline void upmax(LL &x,LL y){
	if(x < y) x = y;
}

int main(){
	scanf("%d",&k);
	FOR(i,1,k){
		scanf("%s",str+1);int v;scanf("%d",&v);
		insert(str,v);
	}
	build();
	scanf("%s",str+1);int n = strlen(str+1);
	int las = 1,now = 0;int t = 0;CLR(f,~0x3f);f[now=0][0][rt] = 0;
	FOR(i,1,n){
		if(str[i] != '?') continue;
		CLR(f[now^1],~0x3f);
		trans(las,i-1);
		FOR(S,0,(1<<14)-1){
			if(__builtin_popcount(S) != t) continue;
			FOR(c,0,13){
				if((S>>c)&1) continue;
				FOR(v,1,tot){
					upmax(f[now^1][S|(1<<c)][ch[to[v]][c]],f[now][S][v]+val[v]+sm[ch[to[v]][c]]);
				}
			}
		}
		now ^= 1;las = i+1;++t;
	}
	if(las <= n){
		CLR(f[now^1],~0x3f);
		trans(las,n);
		FOR(S,0,(1<<14)-1){
			FOR(v,1,tot){
				upmax(f[now^1][S][v],f[now][S][v]+val[v]);
			}
		}
		now ^= 1;las = n+1;
	}
	LL ans = -1e18;
	FOR(S,0,(1<<14)-1) FOR(v,1,tot) ans = std::max(ans,f[now][S][v]);
	printf("%lld\n",ans);
	return 0;
}
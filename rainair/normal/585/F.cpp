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
#define P std::pair
#define LL long long
#define pb push_back
#define MP std::make_pair
#define all(x) x.begin(),x.end()
#define CLR(i,a) memset(i,a,sizeof(i))
#define FOR(i,a,b) for(int i = a;i <= b;++i)
#define ROF(i,a,b) for(int i = a;i >= b;--i)
#define DEBUG(x) std::cerr << #x << '=' << x << std::endl

const int MAXN = 1e5 + 5;
const int MAXM = 9;
const int ha = 1e9 + 7;

int ch[MAXN][MAXM+1],fail[MAXN],flag[MAXN],d;
int tot = 1,rt = 1;

inline void insert(char str[]){
	int v = rt;
	FOR(i,1,d/2){
		int x = str[i]-'0';
		if(!ch[v][x]) ch[v][x] = ++tot;
		v = ch[v][x];
	}
	flag[v] = 1;
}

inline void build(){
	std::queue<int> q;
	FOR(i,0,MAXM) 
		if(ch[rt][i]) fail[ch[rt][i]] = rt,q.push(ch[rt][i]);
		else ch[rt][i] = rt;
	while(!q.empty()){
		int v = q.front();q.pop();
		FOR(i,0,MAXM){
			if(ch[v][i]) fail[ch[v][i]] = ch[fail[v]][i],q.push(ch[v][i]);
			else ch[v][i] = ch[fail[v]][i];
		}
	}
}

int f[100][MAXN][2];
char opt[MAXN];
//  i , j 

int p[MAXN][2];// i~d  

inline int calc(){
	p[d+1][0] = p[d+1][1] = 1;
	ROF(i,d,1){
		p[i][0] = 10ll*p[i+1][0]%ha;
		p[i][1] = (1ll*(opt[i]-'0')*p[i+1][0]%ha+p[i+1][1])%ha;
	}
	CLR(f,0);
	f[0][1][1] = 1;
	FOR(i,0,d-1){
		FOR(j,1,tot){
			if(flag[j]) continue;
			FOR(k,0,9){
				(f[i+1][ch[j][k]][0] += f[i][j][0])%=ha;
				if(k < (opt[i+1]-'0')) (f[i+1][ch[j][k]][0] += f[i][j][1])%=ha;
				if(k == (opt[i+1]-'0')) (f[i+1][ch[j][k]][1] += f[i][j][1])%=ha;
			}
		}
	}
	int ans = 0;
	FOR(i,1,d){
		FOR(j,1,tot){
			if(flag[j]) (ans += 1ll*f[i][j][0]*p[i+1][0]%ha+1ll*f[i][j][1]*p[i+1][1]%ha) %= ha;
		}
	}	
	return ans;
}

char A[MAXN],B[MAXN],C[MAXN];

int main(){
	scanf("%s%s%s",A+1,B+1,C+1);
	int n = strlen(A+1);d = strlen(B+1);
	int k = d;
	while(B[k] == '0') B[k--] = '9';B[k]--;
	FOR(i,1,n-d/2+1) insert(A+i-1);
	build();
	FOR(i,1,d) opt[i] = B[i];
	int l = calc();
	FOR(i,1,d) opt[i] = C[i];
	int r = calc();
	// DEBUG(l);DEBUG(r);
	printf("%d\n",(ha+r-l)%ha);
	return 0;
}
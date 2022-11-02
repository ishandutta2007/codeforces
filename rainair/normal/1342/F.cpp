#include <bits/stdc++.h>

#define fi first
#define se second
#define db double
#define P std::pair<int,int>
#define LL long long
#define pb push_back
#define MP std::make_pair
#define all(x) x.begin(),x.end()
#define CLR(i,a) memset(i,a,sizeof(i))
#define FOR(i,a,b) for(int i = a;i <= b;++i)
#define ROF(i,a,b) for(int i = a;i >= b;--i)
#define DEBUG(x) std::cerr << #x << '=' << x << std::endl

const int MAXN = 16+1;

int f[MAXN][MAXN][(1<<MAXN)+3];
P g[MAXN][MAXN][(1<<MAXN)+3];
int n,a[MAXN];
int sm[(1<<MAXN)+3];
int id[MAXN];

inline void Solve(){
	scanf("%d",&n);
	FOR(i,0,n-1) scanf("%d",a+i);
	FOR(i,0,n) FOR(j,0,n+1) FOR(S,0,(1<<n)-1) f[i][j][S] = 1e9,g[i][j][S] = MP(-1,-1);
	f[0][0][0] = 0;int U = (1<<n)-1;
	FOR(S,0,(1<<n)-1){
		sm[S] = 0;
		FOR(i,0,n-1){
			if((S>>i)&1) sm[S] += a[i];
		}
	}
	FOR(i,0,n-1){
		FOR(j,0,n){
			FOR(S,0,(1<<n)-1){
				if(f[i][j][S] == 1e9) continue;
				int tt = U^S;
				for(int T = tt;T;T=(T-1)&tt){
					if(sm[T]<=f[i][j][S]) continue;
					if((T>>j) == 0) continue;
					int p = __builtin_ctz(T>>j)+j+1;
					if(j == p){
						DEBUG(j);DEBUG(p);
					}
					if(f[i+1][p][S|T] > sm[T]){
						f[i+1][p][S|T] = sm[T];
						g[i+1][p][S|T] = MP(j,S);
					}
				}
			}
		}
	}
	ROF(i,n,0){
		bool flag = 0;
		int nowi=-1,nowj=-1,nowk=-1;
		FOR(j,1,n) if(f[i][j][U] != 1e9){
			flag = 1;
			nowi = i;nowj = j;nowk = U;
			break;
		}
		if(flag){
			printf("%d\n",n-i);
			FOR(i,1,n) id[i] = i;
			while(nowi && nowj && nowk){
				int prei,prej,prek;
				prei = nowi-1;std::tie(prej,prek) = g[nowi][nowj][nowk];
				int T = nowk-prek;
				FOR(i,0,n-1){
					if((T>>i)&1){
						// printf("%d ",i+1);
						if(i != nowj-1){
							printf("%d %d\n",id[i+1],id[nowj]);
							id[i+1] = -1;
							FOR(j,i+1,n) if(id[j]!= -1) id[j]--;
						}
					}
				}
				// puts("");
				// 6 8
				// 2 5 7
				nowi = prei;nowj = prej;nowk = prek;
			};
			return;
		}
	}
}

int main(){
	int T;scanf("%d",&T);
	while(T--) Solve();
	return 0;
}
/*
f[i][j][S]:i,j,S 
T,,
O(n^2 3^n)
*/
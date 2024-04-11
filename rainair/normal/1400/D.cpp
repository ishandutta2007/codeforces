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

const int MAXN = 3000+5;
int a[MAXN],n;
int S[MAXN][MAXN];

inline void Solve(){
	scanf("%d",&n);FOR(i,1,n) scanf("%d",a+i);
	FOR(i,1,n) FOR(j,1,n) S[i][j] = 0;
	LL ans = 0;
	ROF(j,n,1){
		FOR(i,1,j-1){
			ans += S[a[i]][a[j]];
		}
		FOR(i,j+1,n) S[a[j]][a[i]]++; 
	}	
	printf("%lld\n",ans);
}

int main(){
	int T;scanf("%d",&T);
	while(T--) Solve();
	return 0;
}
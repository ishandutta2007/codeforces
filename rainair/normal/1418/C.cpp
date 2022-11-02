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

const int MAXN = 2e5 + 5;
int a[MAXN],n;
int f[MAXN][2];

inline void Solve(){
	scanf("%d",&n);
	FOR(i,1,n) scanf("%d",a+i),f[i][0] = f[i][1] = 1e9;
	f[0][0] = 1e9;f[0][1] = 0;//0=friend
	FOR(i,1,n){
		FOR(j,0,1){
			f[i][j] = std::min(f[i][j],f[i-1][j^1]+(j==0&&a[i]==1));
			if(i > 1) f[i][j] = std::min(f[i][j],f[i-2][j^1]+(j==0&&a[i]==1)+(j==0&&a[i-1]==1));
		}
	}
	printf("%d\n",std::min(f[n][0],f[n][1]));
}

int main(){
	int T;scanf("%d",&T);
	while(T--) Solve();
	return 0;
}
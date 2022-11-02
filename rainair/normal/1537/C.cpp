#include <bits/stdc++.h>

#define fi first
#define se second
#define DB double
#define U unsigned
#define P std::pair
#define LL long long
#define LD long double
#define pb emplace_back
#define MP std::make_pair
#define SZ(x) ((int)x.size())
#define all(x) x.begin(),x.end()
#define CLR(i,a) memset(i,a,sizeof(i))
#define FOR(i,a,b) for(int i = a;i <= b;++i)
#define ROF(i,a,b) for(int i = a;i >= b;--i)
#define DEBUG(x) std::cerr << #x << '=' << x << std::endl

const int MAXN = 2e5 + 5;

int n,a[MAXN];

inline void Solve(){
	scanf("%d",&n);
	FOR(i,1,n) scanf("%d",a+i);
	std::sort(a+1,a+n+1);
	if(n == 2){
		FOR(i,1,n) printf("%d ",a[i]);
		puts("");
		return;
	}
	int mn = 1e9;
	FOR(i,2,n) mn = std::min(mn,a[i]-a[i-1]);
	FOR(i,2,n){
		if(mn == a[i]-a[i-1]){
			FOR(j,i,n) printf("%d ",a[j]);
			FOR(j,1,i-1) printf("%d ",a[j]);
			return;
		}
	}
}

int main(){
	int T;scanf("%d",&T);
	while(T--) Solve();
	return 0;
}
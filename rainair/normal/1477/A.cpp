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

const int MAXN = 4e5 +5;
LL a[MAXN];

int main(){
	int T;scanf("%d",&T);
	while(T--){
		LL n,k;scanf("%lld%lld",&n,&k);
		bool flag = 0;
		FOR(i,1,n) scanf("%lld",a+i);
		std::sort(a+1,a+n+1);
		LL g = 0;
		FOR(i,2,n) g = std::__gcd(g,a[i]-a[i-1]);
		FOR(i,1,n) flag |= ((a[i]%g+g)%g == (k%g+g)%g);
		puts(!flag?"NO":"YES");
	}
	return 0;
}
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

const int MAXN = 3e5 + 5;
int n;
LL a[MAXN];

int main(){
	scanf("%d",&n);
	FOR(i,1,n) scanf("%lld",a+i);
	LL r = 0,ans = 0;
	FOR(i,1,n){
		LL t = std::min(a[i]/2,r);
		
		ans += t;r -= t;a[i] -= 2*t;
		
		ans += a[i]/3;a[i] %= 3;
		r += a[i];
	}
	printf("%lld\n",ans);
	return 0;
}
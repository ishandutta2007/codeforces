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

const int MAXN = 2000+5;

int n;LL k;
LL l[MAXN],r[MAXN],a[MAXN];
LL f[MAXN];

int main(){
	scanf("%d%lld",&n,&k);
	FOR(i,1,n) scanf("%lld%lld%lld",l+i,r+i,a+i);
	ROF(i,n,1){
		int x = a[i];
		if(r[i] == l[i+1]) x += f[i+1];
		if(x > (r[i]-l[i]+1)*k){
			puts("-1");
			return 0;
		}
		f[i] = std::max(0ll,x-(r[i]-l[i])*k);
	}
	LL ans = 0,now = k;
	FOR(i,1,n){
		if(now < f[i]){
			ans += now;
			now = k;
		}
		ans += a[i];
		now = (now-a[i]%k+k)%k;
	}
	printf("%lld\n",ans);
	return 0;
}
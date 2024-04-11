#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pp;
typedef pair<ll,ll> pll;
void read(int& x){ scanf("%d",&x); }
void read(ll& x){ scanf("%lld",&x); }
template<typename T,typename... Args>
void read(T& a,Args&... b){ read(a); read(b...); }
#define all(x) (x).begin(),(x).end()
#define pb push_back
#define eb emplace_back
#define x first
#define y second

ll p[300010];
int n;

ll p2[300010];
const ll mod = int(1e9) + 7;

int main()
{
	p2[0] = 1;
	read(n);
	for(int i=1; i<=n; ++i) read(p[i]), p2[i]=p2[i-1] * 2 % mod;
	sort(p+1, p+n+1);
	ll ans = 0;
	for(int i=1; i<n; ++i){
		(ans += (p2[i]-1) * 1ll * (p2[n-i]-1) % mod * (p[i+1]-p[i]) % mod) %= mod;
	}
	printf("%lld\n", ans);
	return 0;
}
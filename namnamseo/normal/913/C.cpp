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

ll d[50];
int n;
ll L;
ll mc[50];

ll Cost(ll x){
	ll ans = 0;
	for(int i=30; 0<=i; --i){
		if(1&(x>>i)){
			ans += mc[i];
		}
	}
	return ans;
}

int main()
{
    read(n, L);
	for(int i=0; i<n; ++i) read(d[i]);
	for(int i=0; i<=30; ++i){
		mc[i] = (1ll << 60);
		if(i < n) mc[i] = d[i];
		if(i >= 1){
			mc[i] = min(mc[i], mc[i-1]*2);
		}
	}
	ll ans = (1ll << 62);
	while(L < (1ll<<31)){
		ans = min(ans, Cost(L));
		L += (L & (-L));
	}
	printf("%lld\n", ans);
    return 0;
}
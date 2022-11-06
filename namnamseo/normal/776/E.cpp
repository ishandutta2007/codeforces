#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pp;
void read(int& x){ scanf("%d",&x); }
void read(ll& x){ scanf("%lld",&x); }
template<typename T,typename... Args>
void read(T& a,Args&... b){ read(a); read(b...); }
#define all(x) (x).begin(),(x).end()
#define pb push_back

ll n, k;

ll f(ll x){
	vector<ll> pdiv;
{
	ll tmp=x;
	for(ll i=2; i*i <= tmp; ++i){
		if(tmp % i == 0){
			pdiv.pb(i);
			while(tmp % i == 0) tmp/=i;
		}
	}
	if(tmp != 1) pdiv.pb(tmp);
}
	ll ret=x;
	for(ll p:pdiv) ret/=p, ret*=(p-1);
	return ret;
}

int main()
{
    read(n, k);
    while(k){
		if(k%2 == 1){
			n = f(n);
		}
		if(n == 1) break;
		--k;
    }
    printf("%lld\n", n % 1'000'000'007);
    return 0;
}
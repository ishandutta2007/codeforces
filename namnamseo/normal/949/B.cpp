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

ll at(ll n, ll x){
	if(x % 2 == 1){
		return (x+1)/2;
	}
	return x/2 + at(n-x/2, n-x/2);
}

int main()
{
	ll n, q;
	read(n, q);
	for(;q--;){
		ll x; read(x);
		printf("%lld\n", at(n, x));
	}
	return 0;
}
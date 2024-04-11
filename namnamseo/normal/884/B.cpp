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

int main()
{
	ll n, x; read(n, x);
	ll s=0;
	for(int i=0; i<n; ++i){
		ll t; read(t);
		s += t + !!i;
	}
	puts(s==x ? "YES": "NO");
	return 0;
}
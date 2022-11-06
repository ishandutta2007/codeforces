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

ll n, d, b;
ll a[100010];
ll s[100010];

ll uc[100010];

bool dekiru(ll X){
	if(n-X < X+1) return 1;
	ll ul=1, ur=n;
	for(int i=1; i<=n; ++i) uc[i]=a[i];
	for(int step=X+1;;++step){
		int pl = step, pr = n+1-step;
		if(pl > pr) break;
		
		ll cur = 0;
		ul = max(ul, pl-step*d);
		while(cur < b){
			if(ul>ur || pl+step*d < ul) return 0;
			if(uc[ul] >= b-cur){
				uc[ul] -= b-cur;
				cur = b;
				break;
			} else {
				cur += uc[ul];
				uc[ul]=0; ++ul;
			}
		}
		
		if(pr == pl) return 1;
		
		cur = 0;
		ur = min(ur, pr+step*d);
		while(cur < b){
			if(ul>ur || ur < pr-step*d) return 0;
			if(uc[ur] >= b-cur){
				uc[ur] -= b-cur;
				cur = b;
				break;
			} else {
				cur += uc[ur];
				uc[ur]=0; --ur;
			}
		}
	}
	return 1;
}

int main()
{
	read(n, d, b);
	for(int i=1; i<=n; ++i) read(a[i]), s[i]=s[i-1]+a[i];
	
	ll l=-1, r=n+1;
	while(l+1 < r){
		ll mid=(l+r)/2;
		(dekiru(mid)?r:l) = mid;
	}
	printf("%lld\n", r);
	return 0;
}
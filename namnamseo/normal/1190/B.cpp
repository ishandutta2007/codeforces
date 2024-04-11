#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pp;
typedef pair<ll,ll> pll;
void read(int& x){ scanf("%d",&x); }
void read(ll& x){ scanf("%lld",&x); }
void read(pp& x){ scanf("%d%d",&x.first, &x.second); }
void read(pll& x){ scanf("%lld%lld",&x.first, &x.second); }
template<typename T,typename... Args>
void read(T& a,Args&... b){ read(a); read(b...); }
void cppio(){ ios_base::sync_with_stdio(0); cin.tie(0); }
#define all(x) (x).begin(),(x).end()
#define pb push_back
#define eb emplace_back
#define x first
#define y second
#define rep(i,n) for(int i = 0; i < (n); ++i)
#define rrep(i,n) for(int i = 1; i <= (n); ++i)
#define sz(x) (int)(x).size()
 
const int maxn = int(1e5) + 10;
 
int n;
ll a[maxn];
 
int main()
{
	cppio();
	cin >> n;
	rrep(i, n) cin >> a[i];
	sort(a+1, a+n+1);
 
	int sc = 0;
	for(int i=2; i<=n; ++i) if(a[i-1] == a[i]) ++sc;
	if(sc >= 2) { 
		cout << "cslnb" << endl;
		return 0;
	}
 
	if(sc == 0) {
		ll S = accumulate(a+1, a+n+1, 0ll);
		ll tg = (n-1) * 1ll * n / 2;
		if((S - tg) & 1) {
			cout << "sjfnb" << endl;
			return 0;
		} else {
			cout << "cslnb" << endl;
			return 0;
		}
	} else {
		int sp = 0;
		for(sp = 2; sp < n; ++sp) if(a[sp-1] == a[sp]) break;
		if(a[sp] == 0) {
			cout << "cslnb" << endl;
			return 0;
		}
		if(sp-2 >= 1 && a[sp-2] == a[sp] - 1) {
			cout << "cslnb" << endl;
			return 0;
		} else {
			ll S = accumulate(a+1, a+n+1, 0ll);
			ll tg = (n-1) * 1ll * n / 2;
			if((S - tg) & 1) {
				cout << "sjfnb" << endl;
				return 0;
			} else {
				cout << "cslnb" << endl;
				return 0;
			}
		}
	}
	return 0;
}
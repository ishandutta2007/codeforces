#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<ll> vl;
typedef vector<vl> vvl;
typedef pair<ll,ll> pll;
typedef vector<bool> vb;
const ll oo = 0x3f3f3f3f3f3f3f3f;
const double eps = 1e-9;
#define sz(c) ll((c).size())
#define all(c) begin(c), end(c)
#define FOR(i,a,b) for (ll i = (a); i < (b); i++)
#define FORD(i,a,b) for (ll i = (b)-1; i >= (a); i--)
#define mp make_pair
#define pb push_back
#define eb emplace_back
#define xx first
#define yy second
#define TR(X) ({ if(1) cerr << "TR: " << (#X) << " = " << (X) << endl; })

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	ll n, p;
	cin >> n >> p;

	vl a(n);
	FOR(i,0,n) cin >> a[i];
	sort(all(a));

	ll xmin, xmax;
	
	{
		auto check = [&](ll x) {
			ll i = 0;
			FOR(y,x,x+n) {
				while (i < n && a[i] <= y) i++;
				ll cur = i-(y-x);
				if (cur <= 0) return false;
			}
			return true;
		};

		ll lo = max(0LL,a[n-1]-n), hi = a[n-1]+1;

		while (hi-lo > 1) {
			ll x = (lo+hi)/2;
			if (!check(x)) lo = x; else hi = x;
		}

		xmin = lo+1;
	}

	{
		auto check = [&](ll x) {
			ll i = 0;
			FOR(y,x,x+n) {
				while (i < n && a[i] <= y) i++;
				ll cur = i-(y-x);
				if (cur >= p) return false;
			}
			return true;
		};

		ll lo = max(0LL,a[n-1]-n), hi = a[n-1]+1;

		while (hi-lo > 1) {
			ll x = (lo+hi)/2;
			if (check(x)) lo = x; else hi = x;
		}

		xmax = hi-1;
	}

	cout << max(0LL,xmax-xmin+1) << endl;
	FOR(x,xmin,xmax+1) cout << x << " ";
	cout << endl;
}
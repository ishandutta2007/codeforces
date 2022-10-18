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
	
	ll n, d, r;
	cin >> n >> d >> r;
	vl a(n);
	FOR(i,0,n) cin >> a[i];
	
	vl left(n), right(n);
	FOR(i,0,n) {
		if (i > 0) left[i] = left[i-1];
		while (left[i] < i && (i-left[i]+d-1)/d > left[i]+1) left[i]++;
	}
	FOR(i,0,n) right[i] = n-1-left[n-i-1];
	
	//FOR(i,0,n) cout << left[i] << " ";
	//cout << endl;

	ll xmin = -1, xmax = n/2;
	while (xmax-xmin > 1) {
		ll x = (xmin+xmax)/2;

		vl have = a;

		ll j = 0;
		bool ok = true;
		FOR(i,x,n-x) {
			ll need = r;
			while (need > 0) {
				while (j < n && right[j] < i) j++;
				while (j < n && have[j] == 0) j++;
				
				if (j == n || left[j] > i) {
					ok = false;
					break;
				}
				
				ll take = min(have[j],need);
				need -= take;
				have[j] -= take;
			}
		}
		
		if (ok) xmax = x; else xmin = x;
	}
	cout << xmax << endl;
}
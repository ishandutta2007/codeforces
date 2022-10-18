#include <bits/stdc++.h>
using namespace std;

typedef int ll;
typedef vector<ll> vl;
typedef vector<vl> vvl;
typedef pair<ll,ll> pll;
typedef vector<bool> vb;
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

struct stone {
	ll a, b, i;
};

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	ll n; cin >> n;
	vl a(n), b(n);
	FOR(i,0,n) cin >> a[i];
	FOR(i,0,n) cin >> b[i];

	vector<stone> v(n);
	FOR(i,0,n) v[i] = {a[i],-1,i};
	sort(all(v),[&](stone s, stone t) { return s.a < t.a; });
	sort(all(b));
	FOR(i,0,n) v[i].b = b[i];
	
	stack<stone> stk;
	vector<tuple<ll,ll,ll>> res;

	for (stone s: v) {
		if (s.a < s.b) {
			stk.push(s);
		} else {
			while (s.a > s.b) {
				if (stk.empty()) {
					cout << "NO" << endl;
					return 0;
				}
				stone t = stk.top();
				stk.pop();

				ll diff = min(s.a-s.b, t.b-t.a);
				s.a -= diff;
				t.a += diff;
				res.eb(t.i+1,s.i+1,diff);

				if (t.a != t.b) stk.push(t);
			}
		}
	}
	
	if (!stk.empty()) {
		cout << "NO" << endl;
		return 0;
	}

	cout << "YES" << endl;
	cout << sz(res) << endl;
	for (auto tp: res) {
		ll i, j, d;
		tie(i,j,d) = tp;
		cout << i << " " << j << " " << d << "\n";
	}
}
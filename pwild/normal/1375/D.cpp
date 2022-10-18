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

const ll N = 1010;
ll cnt[N];

ll mex(const vl &a) {
	for (ll x: a) cnt[x]++;

	ll res = 0;
	while (cnt[res]) res++;

	for (ll x: a) cnt[x]--;

	return res;
}

void solve(vl a) {
	ll n = sz(a);
	vl res;
	while (true) {
		ll m = mex(a);
		if (m < n) {
			a[m] = m;
			res.pb(m);
		} else {
			ll i = 0;
			while (i < n && a[i] == i) i++;
			if (i == n) break;
			a[i] = m;
			res.pb(i);
		}
	}
	assert(sz(res) <= 2*n);

	cout << sz(res) << endl;
	for (ll i: res) cout << i+1 << " ";
	cout << endl;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	/*
	FOR(k,0,1000000) {
		ll n = 3 + rand() % 5;
		vl a(n);
		FOR(i,0,n) a[i] = rand() % (n+1);
		solve(a);
	}
	*/

	ll tc; cin >> tc;
	while (tc--) {
		ll n; cin >> n;
		vl a(n);
		FOR(i,0,n) cin >> a[i];
		
		solve(a);
	}
}
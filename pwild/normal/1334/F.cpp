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

const ll N = 1e6 + 10;
ll seg[N], n;

void update(ll i, ll j, ll add) {
	i += n, j += n;
	for (; i < j; i /= 2, j /= 2) {
		if (i&1) seg[i++] += add;
		if (j&1) seg[--j] += add;
	}
}

ll query(ll i) {
	i += n;
	ll res = seg[i];
	for (i /= 2; i; i /= 2) res += seg[i];
	return res;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	ll n; cin >> n;
	vl a(n), p(n);
	FOR(i,0,n) cin >> a[i];
	FOR(i,0,n) cin >> p[i];
	ll m; cin >> m;
	vl b(m);
	FOR(i,0,m) cin >> b[i];
	
	::n = m+1;
	fill(seg+m+2, seg+2*m+2, oo);
	
	FOR(i,0,n) {
		ll j = lower_bound(all(b),a[i]) - begin(b);
		
		if (j < m && b[j] == a[i]) {
			ll cur = query(j);
			update(0, j+1, p[i]);
			update(j+1, m+1, min(p[i],0LL));
			ll prv = query(j+1);
			if (cur < prv) update(j+1, j+2, cur-prv);
		} else {
			update(0, j+1, p[i]);
			update(j+1, m+1, min(p[i],0LL));
		}
	}
	
	ll res = query(m);
	if (res < oo/2) cout << "YES\n" << res << endl;
	else cout << "NO" << endl;
}
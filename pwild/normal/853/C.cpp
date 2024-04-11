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
#define mt make_tuple
#define pb push_back
#define eb emplace_back
#define xx first
#define yy second
#define has(c,i) ((c).find(i) != end(c))
#define DBGDO(X) ({ if(1) cerr << "DBGDO: " << (#X) << " = " << (X) << endl; })

struct bit {
	ll n;
	vl a;

	bit (ll n): n(n), a(n+2) {}

	void add(ll i, ll v) {
		for (++i; i <= n+1; i += i & -i) a[i] += v;
	}

	ll get(ll i) {
		ll res = 0;
		for (; i; i -= i & -i) res += a[i];
		return res;
	}

	ll get(ll a, ll b) {
		return get(b) - get(a);
	}
};

struct query {
	ll r, u, i;
	bool operator<(const query &q) const { return u < q.u; }
};

ll n;

struct rectangle {
	ll l, r, d, u;
	void rotate() {
		tie(l,r,d,u) = mt(n-u,n-d,l,r);
	}
	bool operator<(const rectangle &r) const { return u < r.u; }
};

ll s(ll n) { return n*(n-1)/2; }

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	ll q; cin >> n >> q;

	vector<rectangle> p(n);
	FOR(i,0,n) {
		p[i].l = i, p[i].r = i+1;
		cin >> p[i].u;
		p[i].d = p[i].u-1;
	}

	vl res(q);
	
	vector<rectangle> r(q);
	FOR(i,0,q) {
		cin >> r[i].l >> r[i].d >> r[i].r >> r[i].u;
		r[i].l--, r[i].d--;
		
		res[i] = s(n);
		res[i] -= s(r[i].l) + s(r[i].d) + s(n-r[i].r) + s(n-r[i].u);
	}
	
	FOR(dir,0,4) {
		vector<query> qs(q);
		FOR(i,0,q) qs[i] = {r[i].l,r[i].d,i};
		sort(all(qs));
		sort(all(p));

		bit b(n);

		ll q_pnt = 0;
		FOR(i,0,n) {
			while (q_pnt < q && qs[q_pnt].u == i) {
				auto c = qs[q_pnt];
				res[c.i] += s(b.get(c.r));
				q_pnt++;
			}
			b.add(p[i].l,1);			
		}
		
		FOR(i,0,n) p[i].rotate();
		FOR(i,0,q) r[i].rotate();
	}
	FOR(i,0,q) cout << res[i] << "\n";
}
#include <bits/stdc++.h>
using namespace std;

typedef int ll;
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

struct obj {
	ll p, a = 0, i;
	bool operator<(const obj &s) const {
		if (p != s.p) return p > s.p;
		if (a != s.a) return a < s.a;
		return i < s.i;
	}
};

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	ll n, m; cin >> n >> m;
	vector<obj> pc(n), sk(m);
	FOR(i,0,n) cin >> pc[i].p, pc[i].i = i;
	FOR(i,0,m) cin >> sk[i].p, sk[i].i = i;
	
	vl a(m), b(n);
	ll c = 0, u = 0;
	
	sort(all(pc));
	set<obj> q(all(sk));
	for (const auto &x: pc) {
		if (q.empty()) break;
		auto y = *begin(q);
		while (y.p > x.p) {
			q.erase(begin(q));
			y.p = (y.p+1)/2;
			y.a++;
			q.insert(y);
			y = *begin(q);
		}
		if (y.p < x.p) continue;
		q.erase(begin(q));
		c++, u += y.a; 
		a[y.i] = y.a, b[x.i] = y.i+1;
	}
	cout << c << " " << u << "\n";
	FOR(i,0,m) cout << a[i] << " \n"[i+1 == m];
	FOR(i,0,n) cout << b[i] << " \n"[i+1 == n];
}
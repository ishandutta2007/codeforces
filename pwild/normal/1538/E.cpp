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

const string h = "haha";
const ll K = 3;

struct bstring {
	string s;
	ll len, cnt;

	bstring(string s = ""): s(s), len(sz(s)), cnt(0) {
		FOR(i,0,len) if (s.substr(i,4) == h) cnt++;
	}
};

bstring operator+(bstring a, bstring b) {
	string t = a.s + b.s;
	ll seam = 0;
	FOR(i,sz(a.s)-3,sz(a.s)) if (i >= 0 && i+4 <= sz(t)) {
		if (t.substr(i,4) == h) seam++;
	}
	if (sz(t) >= 2*K) t = t.substr(0,K) + t.substr(sz(t)-K);
	bstring c(t);
	c.len = a.len + b.len;
	c.cnt = a.cnt + b.cnt + seam;
	return c;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	ll tc; cin >> tc;
	while (tc--) {
		ll n; cin >> n;
		map<string,bstring> ctx;
			while (n--) {
			string v, op;
			cin >> v >> op;
			if (op == ":=") {
				string s; cin >> s;
				ctx[v] = bstring(s);
			} else {
				string a, b;
				cin >> a >> op >> b;
				bstring bs = ctx[a] + ctx[b];
				ctx[v] = bs;
			}
			if (n == 0) cout << ctx[v].cnt << endl;
		}
	}
}
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

struct slot {
	ll minl, maxl, i;
};

bool operator<(const slot &a, const slot &b) {
	return a.minl < b.minl;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	ll n, m; cin >> n >> m;
	vl l(n), r(n);
	FOR(i,0,n) cin >> l[i] >> r[i];
	vector<pll> b(m);
	FOR(i,0,m) cin >> b[i].xx, b[i].yy = i+1;

	vector<slot> s(n-1);
	FOR(i,0,n-1) {
		s[i] = {l[i+1]-r[i],r[i+1]-l[i],i};
	}

	vl res(n-1,-1);
	
	sort(all(b));
	sort(all(s));

	bool ok = true;

	set<pll> todo;
	ll j = 0;
	FOR(i,0,m) {
		while (j < n-1 && s[j].minl <= b[i].xx) {
			todo.insert(mp(s[j].maxl,s[j].i));
			j++;
		}
		if (!sz(todo)) continue;
		auto e = *begin(todo);
		if (e.xx < b[i].xx) {
			ok = false;
			break;
		}
		todo.erase(begin(todo));
		res[e.yy] = b[i].yy;
	}
	
	FOR(i,0,n-1) if (res[i] == -1) ok = false;

	if (ok) {
		cout << "Yes" << endl;
		FOR(i,0,n-2) cout << res[i] << " ";
		cout << res[n-2] << endl;
	} else {
		cout << "No" << endl;
	}


}
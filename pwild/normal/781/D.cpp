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

ll n;
bitset<500> ped[61][500], bik[61][500];

bool possible(ll len) {
	bitset<500> v;
	v[0] = true;
	
	bool is_ped = true;
	FORD(t,0,61) if (len & (1LL << t)) {
		bitset<500> w;
		FOR(i,0,n) if (v[i]) {
			FOR(j,0,n) {
				if (is_ped) {
					if (ped[t][i][j]) w[j] = true;
				} else {
					if (bik[t][i][j]) w[j] = true;
				}
			}
		}
		v = w;
		is_ped = !is_ped;
	}
	return v.any();
}

ll go() {
	if (possible(ll(1e18)+1)) return -1;
	
	ll lenmin = 0, lenmax = ll(1e18)+1;
	while (lenmax-lenmin > 1) {
		ll len = (lenmin+lenmax)/2;
		if (possible(len)) lenmin = len; else lenmax = len;
	}
	return lenmin;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	ll m; cin >> n >> m;
	
	while (m--) {
		ll a, b, t;
		cin >> a >> b >> t;
		a--, b--;
		if (t) bik[0][a][b] = 1; else ped[0][a][b] = 1;
	}
	
	auto transpose = [&](bitset<500> *a) {
		FOR(i,0,n) FOR(j,i+1,n) {
			bool tmp = a[i][j];
			a[i][j] = a[j][i];
			a[j][i] = tmp;
		}
	};

	FOR(t,1,61) {
		transpose(bik[t-1]);
		FOR(i,0,n) FOR(j,0,n) ped[t][i][j] = (ped[t-1][i] & bik[t-1][j]).any();
		transpose(bik[t-1]);
		
		transpose(ped[t-1]);
		FOR(i,0,n) FOR(j,0,n) bik[t][i][j] = (bik[t-1][i] & ped[t-1][j]).any();
		transpose(ped[t-1]);
	}
	cout << go() << endl;
}
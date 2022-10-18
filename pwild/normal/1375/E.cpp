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
	
	ll n; cin >> n;

	vector<pll> b(n);
	FOR(i,0,n) cin >> b[i].xx, b[i].yy = i;
	sort(all(b));

	vl a(n);
	FOR(i,0,n) a[b[i].yy] = i;

//	FOR(i,0,n) cerr << a[i] << " ";
//	cerr << endl;

	vl ai(n);
	FOR(i,0,n) ai[a[i]] = i;

	vector<pll> res;

	FOR(k,0,n) {
		ll i = ai[k];
		FORD(j,i+1,n) if (a[j] < a[i]) {
			res.eb(i,j);
			swap(a[i],a[j]);
			ai[a[i]] = i, ai[a[j]] = j;
		}
	}

	cout << sz(res) << endl;
	for (auto [i,j]: res) cout << i+1 << " " << j+1 << endl;
}
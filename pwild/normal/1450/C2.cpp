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

void solve() {
	ll n; cin >> n;
	vector<string> a(n);
	FOR(i,0,n) cin >> a[i];
	
	ll k = 0;

	vvl cnt(3, vl(2));
	FOR(i,0,n) FOR(j,0,n) if (a[i][j] != '.') {
		cnt[(i+j)%3][a[i][j] == 'X']++, k++;
	}
	
	FOR(p,0,3) FOR(q,0,3) if (p != q && cnt[p][0] + cnt[q][1] <= k/3) {
		FOR(i,0,n) FOR(j,0,n) if (a[i][j] != '.') {
			if ((i+j)%3 == p) a[i][j] = 'X';
			if ((i+j)%3 == q) a[i][j] = 'O';
		}
		FOR(i,0,n) cout << a[i] << endl;
		return;
	}
	assert(0);
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	ll tc; cin >> tc;
	while (tc--) solve();
}
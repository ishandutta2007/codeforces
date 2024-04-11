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
	ll n, x, y;
	cin >> n >> x >> y;
	if (x > y) swap(x,y);

	ll a = x+y+1-n;
	a = max(a,1LL);
	a = min(a,n);
	
	ll b = x+y-1;
	b = max(b,1LL);
	b = min(b,n);
	
	cout << a << " " << b << endl;
}

void brute(ll n) {
	vvl lo(n, vl(n,oo));
	vvl hi(n, vl(n,-oo));
	
	vl p(n);
	iota(all(p),0);
	
	do {
		vl sc(n);
		FOR(i,0,n) sc[i] = i+p[i];
		vl cur(n);
		FOR(i,0,n) FOR(j,0,n) if (sc[j] <= sc[i]) cur[i]++;
		FOR(i,0,n) {
			lo[i][p[i]] = min(lo[i][p[i]], cur[i]);
			hi[i][p[i]] = max(hi[i][p[i]], cur[i]);
		}
	} while (next_permutation(all(p)));
	
	FOR(i,0,n) FOR(j,0,n) cout << lo[i][j] << " \n"[j+1==n];
	cout << endl;
	FOR(i,0,n) FOR(j,0,n) cout << hi[i][j] << " \n"[j+1==n];
	cout << endl;

}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
//	FOR(n,1,10) brute(n);

	ll tc; cin >> tc;
	while (tc--) solve();
}
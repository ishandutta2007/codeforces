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

vvl ch;
vl p;
vl subsz;
vector<double> res;

ll dfs1(ll i) {
	subsz[i] = 1;
	for (ll j: ch[i]) subsz[i] += dfs1(j);
	return subsz[i];
}

void dfs2(ll i, double entry) {
	res[i] = entry+1;
	for (ll j: ch[i]) dfs2(j,entry + 1 + double(subsz[i]-1-subsz[j])/2);
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	ll n; cin >> n;
	ch.resize(n), p.resize(n,-1);
	subsz.resize(n), res.resize(n);
	FOR(i,1,n) {
		cin >> p[i], p[i]--;
		ch[p[i]].pb(i);
	}
	dfs1(0), dfs2(0,0);
	FOR(i,0,n) cout << fixed << setprecision(1) << res[i] << " \n"[i+1 == n];
}
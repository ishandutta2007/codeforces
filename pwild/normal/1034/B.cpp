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
#define TR(X) ({ if(1) cerr << "TR: " << (#X) << " = " << (X) << endl; })

struct matching {
	ll m, n;
	vvl adj;
	vl match;
	vb mark;

	matching(ll m, ll n): m(m), n(n), adj(m), match(n,-1) { }

	bool dfs(ll i) {
		if (i == -1) return true;
		if (mark[i]) return false;
		mark[i] = true;
		for (ll j: adj[i]) if (dfs(match[j])) {
			match[j] = i;
			return true;
		}
		return false;
	}
	
	ll max_match() {
		ll res = 0;
		FOR(i,0,m) {
			mark = vb(m);
			if (dfs(i)) res++;
		}
		return res;
	}
};

ll bruteforce(ll m, ll n) {
	if (m > n) swap(m,n);
	ll L = 0, R = 0;
	vvl id(m,vl(n));
	FOR(i,0,m) FOR(j,0,n) {
		if ((i+j)%2) id[i][j] = R++;
		else id[i][j] = L++;
	}

	matching M(L,R);
	FOR(i,0,m) FOR(j,0,n) {
		if ((i+j)%2) continue;
		FOR(di,-3,4) FOR(dj,-3,4) {
			if (abs(di)+abs(dj) != 3) continue;
			ll ni = i+di, nj = j+dj;
			if (ni < 0 || ni >= m || nj < 0 || nj >= n) continue;
			M.adj[id[i][j]].pb(id[ni][nj]);
		}
	}
	return 2*M.max_match();
}

ll full(ll m, ll n) {
	ll res = m*n;
	if (res%2) res--;
	return res;
}

ll f(ll m, ll n) {
	if (m > n) swap(m,n);

	if (m >= 3) return full(m,n);
	
	if (m == 2) {
		if (n >= 8) return full(m,n);
		return bruteforce(m,n);
	}
	
	vl offs = {0,0,0,0,2,4};
	return (n/6)*6 + offs[n%6];
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
//	ll N = 30;
//	FOR(m,1,N) FOR(n,m,N) {
//		assert(f(m,n) == bruteforce(m,n));
//	}
	ll m, n; cin >> m >> n;
	cout << f(m,n) << endl;

}
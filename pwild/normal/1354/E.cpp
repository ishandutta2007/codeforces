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

vvl adj;
vl col, comp;

void dfs(ll i) {
	for (ll j: adj[i]) {
		if (comp[j] == -1) {
			comp[j] = comp[i], col[j] = 1-col[i];
			dfs(j);
		}
		if (col[j] == col[i]) {
			cout << "NO" << endl;
			exit(0);
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	ll n, m;
	cin >> n >> m;

	vl k(3);
	FOR(i,0,3) cin >> k[i];

	adj.resize(n);
	while (m--) {
		ll a, b;
		cin >> a >> b;
		a--, b--;
		adj[a].pb(b);
		adj[b].pb(a);
	}
	
	col.resize(n,-1);
	comp.resize(n,-1);

	ll C = 0;
	FOR(i,0,n) if (comp[i] == -1) {
		comp[i] = C++, col[i] = 0;
		dfs(i);
	}

	vvl cnt(C,vl(2));
	FOR(i,0,n) cnt[comp[i]][col[i]]++;
	
	vector<bitset<5005>> dp(C+1);
	dp[0][0] = 1;

	FOR(c,0,C) {
		dp[c+1] = (dp[c] << cnt[c][0]) | (dp[c] << cnt[c][1]);
	}

	if (!dp[C][k[1]]) {
		cout << "NO" << endl;
		return 0;
	}
	
	cout << "YES" << endl;
	vl v(C);
	ll x = k[1];

	FORD(c,0,C) {
		assert(dp[c+1][x]);
		FOR(i,0,2) {
			if (x >= cnt[c][i] && dp[c][x-cnt[c][i]]) {
				x -= cnt[c][i];
				v[c] = i;
				break;
			}
		}
	}

	FOR(i,0,n) {
		if (v[comp[i]] == col[i]) {
			cout << '2';
		} else {
			cout << "13"[ k[2]-->0 ];
		}
	}
	cout << endl;
}
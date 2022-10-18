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

const ll N = 1e6 + 10;
ll T = 0;
ll ch[N][26], depth[N], dist[N], tin[N], tout[N], order[N];
bool is_node[N];

void dfs1(ll i) {
	dist[i] = depth[i];
	tin[i] = T;
	if (is_node[i]) {
		order[T++] = i;
	}

	FOR(c,0,26) {
		ll j = ch[i][c];
		if (j < 0) continue;
		depth[j] = depth[i] + 1;
		dfs1(j);
	}

	tout[i] = T;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	memset(ch,-1,sizeof ch);

	ll n; cin >> n;
	FOR(i,0,n) {
		ll p; cin >> p;
		char c; cin >> c;
		ch[p][c-'a'] = i+1;
	}

	ll k; cin >> k;
	vl a(k);
	FOR(i,0,k) cin >> a[i];

	FOR(i,0,k) is_node[a[i]] = 1;
	
	dfs1(0);
	
	vl seg(2*k, oo);

	auto query = [&](ll i) {
		i += k;
		ll res = seg[i];
		for (i /= 2; i; i /= 2) res = min(res, seg[i]);
		return res;
	};

	auto update = [&](ll i, ll j, ll x) {
		i += k, j += k;
		for (; i < j; i /= 2, j /= 2) {
			if (i&1) seg[i] = min(seg[i],x), i++;
			if (j&1) j--, seg[j] = min(seg[j],x);
		}
	};
	
	function<void(ll)> dfs2 = [&](ll i) {
		if (is_node[i]) {
			ll cur = query(tin[i]);
			dist[i] = min(dist[i], tin[i] + cur);
		}
		update(tin[i], tout[i], dist[i]+1-tin[i]);
		
		FOR(c,0,26) {
			ll j = ch[i][c];
			if (j < 0) continue;
			dist[j] = min(dist[j], dist[i]+1);
			dfs2(j);
		}
	};
	
	dfs2(0);
	
	FOR(i,0,k) cout << dist[a[i]] << " \n"[i+1==k];
}
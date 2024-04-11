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
	
	ll b, m;
	cin >> b >> m;
	
	ll n = 1010;
	vl cnt(n);
	while (m--) {
		ll x; cin >> x;
		cnt[x]++;
	}
	vl a;
	FOR(i,0,n) if (cnt[i]) a.pb(i-b);
	
	vl dist(n,oo);
	queue<ll> q;

	ll s = b+3;
	dist[s] = 0, q.push(s);

	ll res = oo;
	while (sz(q)) {
		ll i = q.front();
		q.pop();
	
		for (ll x: a) {
			ll j = i+x;
			if (j < 0 || j >= n) continue;
			if (j == s) res = min(res, dist[i]+1);
			if (dist[j] < oo) continue;
			dist[j] = dist[i]+1, q.push(j);
		}
	}
	if (res == oo) res = -1;
	cout << res << endl;
}
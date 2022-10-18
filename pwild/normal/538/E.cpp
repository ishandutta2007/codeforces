#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<ll> vi;
#define sz(c) ll((c).size())
#define FOR(i,a,b) for (ll i = (a); i < (b); i++)
#define pb push_back

const ll maxN = 200010;
vi ch[maxN];

ll f(ll i, bool isMin) {
	if (!sz(ch[i])) return 1;
	if (isMin) {
		ll res = LLONG_MAX;
		for (const ll &j: ch[i]) res = min(res,f(j,false));
		return res;
	} else {
		ll res = 0;
		for (const ll &j: ch[i]) res += f(j,true);
		return res;
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	ll n; cin >> n;
	FOR(i,1,n) {
		ll u, v; cin >> u >> v;
		ch[u].pb(v);
	}
	
	ll leaves = 0;
	FOR(i,1,n+1) if (!sz(ch[i])) leaves++;

	cout << leaves + 1 - f(1,true) << " " << f(1,false) << endl;

}
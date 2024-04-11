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

map<pll,ll> dp;
ll g(ll cnt, ll mask) {
	pll p(cnt,mask);
	if (has(dp,p)) return dp[p];
	
	set<ll> s;
	FOR(i,1,cnt+1) {
		if (mask & (1LL << i)) continue;
		s.insert(g(cnt-i, mask | (1LL << i)));
	}
	
	ll res = 0;
	while (has(s,res)) res++;

	return dp[p] = res;
}

ll G[] = {0,1,1,2,2,2,3,3,3,3,4,4,4,4,4,5,5,5,5,5,5,6,6,6,6,6,6,6,7,7,7,7,7,7,7,7,8,8,8,8,8,8,8,8,8,9,9,9,9,9,9,9,9,9,9,10,10,10,10,10,10};

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	//FOR(i,0,61) cout << g(i,0) << ",";
	//cout << endl;
	
	ll n; cin >> n;
	ll res = 0;
	FOR(i,0,n) {
		ll s; cin >> s;
		res = res ^ G[s];
	}
	cout << ((!res) ? "YES" : "NO") << endl;

}
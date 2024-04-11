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

	vl a(n);
	FOR(i,0,n) cin >> a[i];

	vvl dp(2,vl(n));

	FOR(dir,0,2) {
		stack<ll> st;
		FOR(i,0,n) {
			while (!st.empty() && a[st.top()] > a[i]) st.pop();
			if (st.empty()) {
				dp[dir][i] = (i+1) * a[i];
			} else {
				ll j = st.top();
				dp[dir][i] = (i-j)*a[i] + dp[dir][j];
			}
			st.push(i);
		}
		
		reverse(all(a));
	}
	
	reverse(all(dp[1]));
	
	auto val = [&](ll i) {
		return dp[0][i] + dp[1][i] - a[i];
	};

	ll bi = 0;
	FOR(i,0,n) if (val(i) > val(bi)) bi = i;
	
	vl res(n);
	res[bi] = a[bi];
	FORD(i,0,bi) res[i] = min(a[i],res[i+1]);
	FOR(i,bi+1,n) res[i] = min(a[i],res[i-1]);

	FOR(i,0,n) cout << res[i] << " \n"[i+1==n];
}
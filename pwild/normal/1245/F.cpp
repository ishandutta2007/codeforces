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

struct state {
	ll cnt[2][2][2][2] = {};
};

ll solve(ll c, ll d) {
	state dp;
	dp.cnt[0][0][0][0] = 1;
	
	FORD(i,0,32) {
		state ndp;
		ll ci = (c >> i) & 1, di = (d >> i) & 1;
		FOR(ai,0,2) FOR(bi,0,2) if (ai+bi <= 1) {
			FOR(agc,0,2) FOR(ald,0,2) FOR(bgc,0,2) FOR(bld,0,2) {
				if (!agc && ai < ci) continue;
				if (!bgc && bi < ci) continue;
				if (!ald && ai > di) continue;
				if (!bld && bi > di) continue;
				ll nagc = agc || ai > ci;
				ll nbgc = bgc || bi > ci;
				ll nald = ald || ai < di;
				ll nbld = bld || bi < di;
				ndp.cnt[nagc][nald][nbgc][nbld] += dp.cnt[agc][ald][bgc][bld];
			}
		}
		dp = ndp;
	}
	ll res = 0;
	FOR(agc,0,2) FOR(ald,0,2) FOR(bgc,0,2) FOR(bld,0,2) {
		res += dp.cnt[agc][ald][bgc][bld];
	}
	return res;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	ll tc; cin >> tc;
	while (tc--) {
		ll c, d;
		cin >> c >> d;
		cout << solve(c,d) << endl;
	}
}
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
	
	ll tc; cin >> tc;
	while (tc--) {
		ll n, pipe, pillar;
		cin >> n >> pipe >> pillar;

		string s; cin >> s;

		vl cost = {pillar, oo};
		
		for (char c: s) {
			vl ncost(2);
			if (c == '0') {
				ncost[0] = pillar + min(pipe + cost[0], 2*pipe + cost[1]);
				ncost[1] = 2*pillar + min(pipe + cost[1], 2*pipe + cost[0]);
			} else {
				ncost[0] = oo;
				ncost[1] = 2*pillar + pipe + cost[1];
			}
			cost = ncost;
		}
		cout << cost[0] << endl;
	}
}
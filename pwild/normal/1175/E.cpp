#include <bits/stdc++.h>
using namespace std;

typedef int ll;
typedef vector<ll> vl;
typedef vector<vl> vvl;
typedef pair<ll,ll> pll;
typedef vector<bool> vb;
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

const ll N = 500500, K = 20;
ll step[N][K];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	ll n, q;
	cin >> n >> q;
	FOR(i,0,n) {
		ll a, b;
		cin >> a >> b;
		step[a][0] = max(step[a][0], b);
	}
	
	FOR(a,1,N) step[a][0] = max(step[a][0], step[a-1][0]);

	FOR(k,1,K) FOR(a,0,N) step[a][k] = step[ step[a][k-1] ][k-1];

	while (q--) {
		ll a, b;
		cin >> a >> b;

		ll res = 0;
		FORD(k,0,K) {
			if (step[a][k] < b) {
				a = step[a][k];
				res += 1 << k;
			}
		}
		
		if (step[a][0] < b) {
			cout << -1 << endl;
		} else {
			cout << res+1 << endl;
		}
	}
}
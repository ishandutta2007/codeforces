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
	vl cnt(10);
	ll res = 1;
	FOR(i,0,n) {
		ll x; cin >> x;
		x--;
		cnt[x]++;
		
		bool ok = false;
		FOR(j,0,10) if (cnt[j]) {
			cnt[j]--;
			
			FOR(k,0,10) if (cnt[k]) {
				bool cur = true;
				FOR(l,k+1,10) if (cnt[l] > 0 && cnt[l] != cnt[k]) cur = false;
				if (cur) ok = true;
				break;
			}

			cnt[j]++;
		}

		if (ok) res = i+1;
	}
	cout << res << endl;
}
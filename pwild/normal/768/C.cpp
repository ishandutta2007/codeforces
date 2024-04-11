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
#define mt make_tuple
#define pb push_back
#define eb emplace_back
#define xx first
#define yy second
#define has(c,i) ((c).find(i) != end(c))
#define DBGDO(X) ({ if(1) cerr << "DBGDO: " << (#X) << " = " << (X) << endl; })

ll cnt[2][1024];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	ll n, k, x;
	cin >> n >> k >> x;

	FOR(i,0,n) {
		ll a; cin >> a;
		cnt[0][a]++;
	}
	
	FOR(ii,0,k) {
		ll s = ii % 2, t = !s;
		memset(cnt[t],0,sizeof(cnt[t]));
		ll sum = 0;
		FOR(i,0,1024) {
			ll y = cnt[s][i]/2;
			cnt[t][i] += y;
			cnt[t][i^x] += y;
			if (cnt[s][i] & 1) {
				if (sum & 1) cnt[t][i]++; else cnt[t][i^x]++;	
			}
			sum += cnt[s][i];
		}
	}
	
	ll s = k % 2;
	FORD(i,0,1024) if (cnt[s][i]) {
		cout << i << " ";
		break;
	}
	FOR(i,0,1024) if (cnt[s][i]) {
		cout << i << endl;
		break;
	}

}
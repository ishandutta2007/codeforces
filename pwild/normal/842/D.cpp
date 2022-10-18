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

const ll k = 19, N = 1 << k;

bool flip[k];
ll cnt[2*N];

ll y = 0;

ll mex() {
	ll i = 1;
	FORD(j,0,k) {
		ll l = 2*i, r = 2*i+1;
		if (flip[j]) swap(l,r);
		if (cnt[l] < (1 << j)) i = l; else i = r;
	}
	return i-N;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	ll n, m; cin >> n >> m;

	while (n--) {
		ll a; cin >> a;
		cnt[N+a] = 1;
	}
	
	FORD(i,1,N) cnt[i] = cnt[2*i] + cnt[2*i+1];

	while (m--) {
		ll x; cin >> x;
		FOR(j,0,k) if (x & (1 << j)) flip[j] = !flip[j];
		y ^= x;
		cout << (mex()^y) << "\n";
	}
}
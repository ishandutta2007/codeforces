#include <bits/stdc++.h>
using namespace std;

typedef int ll;
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
#define TR(X) ({ if(1) cerr << "TR: " << (#X) << " = " << (X) << endl; })

const ll N = 1.5e7 + 10, M = 1e6;
ll pf[N];
ll pr[M], cnt[M];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	ll pc = 0;
	memset(pf,-1,sizeof pf);
	FOR(i,2,N) if (pf[i] == -1) {
		for (ll j = i; j < N; j += i) {
			pf[j] = pc;
		}
		pr[pc++] = i;
	}
	cerr << pc << endl;
	
	ll n; cin >> n;
	vl a(n);
	FOR(i,0,n) cin >> a[i];

	ll g = 0;
	FOR(i,0,n) g = __gcd(g,a[i]);
	FOR(i,0,n) a[i] /= g;
	
	FOR(i,0,n) {
		for (ll x = a[i]; x > 1;) {
			ll nx = x/pr[pf[x]];
			if (pf[x] != pf[nx]) cnt[pf[x]]++;
			x = nx;
		}
	}
	ll res = n;
	FOR(i,0,pc) res = min(res,n-cnt[i]);
	
	if (res == n) res = -1;
	cout << res << endl;

}
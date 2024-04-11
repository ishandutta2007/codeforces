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
	
	ll n, k;
	cin >> n >> k;

	vl a(n);
	FOR(i,0,n) cin >> a[i];
	sort(all(a));

	vl s(n+1);
	FOR(i,0,n) s[i+1] = a[i]+s[i];
	
	ll res = oo;
	FOR(i,0,n) if (i == 0 || a[i] != a[i-1]) {
		ll j = i;
		while (j < n && a[j] == a[i]) j++;
		ll x = a[i];

		ll costL = i*(x-1) - (s[i]-s[0]);
		ll costR = s[n]-s[j] - (n-j)*(x+1);
		
		ll need = max(k - (j-i), 0LL);

		if (need == 0) res = 0;
		if (j >= k) res = min(res, costL + need);
		if (n-i >= k) res = min(res, costR + need);
		res = min(res, costL + costR + need);
	}
	cout << res << endl;
}
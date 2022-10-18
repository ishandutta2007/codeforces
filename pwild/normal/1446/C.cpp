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

ll rec(const vl &a, ll i, ll j, ll k) {
	if (j-i <= 1) return j-i;

	ll m = i;
	while (m < j && !(a[m] & (1 << k))) m++;

	if (m == i || m == j) return rec(a,i,j,k-1);

	ll L = rec(a,i,m,k-1), R = rec(a,m,j,k-1);
	return max(L,R)+1;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	ll n; cin >> n;
	vl a(n);
	FOR(i,0,n) cin >> a[i];
	sort(all(a));

	ll res = n - rec(a,0,n,31);
	cout << res << endl;
}
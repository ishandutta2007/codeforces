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

ll split(ll a, ll k) {
	if (k > a) return oo;
	return (a%k) * (a/k+1)*(a/k+1) + (k-a%k) * (a/k)*(a/k);
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	ll n, k;
	cin >> n >> k;

	vl a(n);
	FOR(i,0,n) cin >> a[i];
	sort(all(a));

	priority_queue<pll> q;
	ll res = 0;

	vl c(n,1);
	FOR(i,0,n) {
		res += split(a[i],1);
		q.emplace(split(a[i],1) - split(a[i],2), i);
	}

	while (k --> n) {
		auto [x,i] = q.top();
		q.pop();
		res -= x;
		c[i]++;
		q.emplace(split(a[i],c[i]) - split(a[i],c[i]+1), i);
	}
	
	cout << res << endl;
}
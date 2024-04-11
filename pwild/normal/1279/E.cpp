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

const ll N = 55,  M = 1e18 + 1e9;

struct num {
	ll x;
	long double y;
	num(ll x = 0): x(x), y(x) { }
	num(ll x, long double y): x(x), y(y) { }
	num operator+(num n) { return num(x+n.x, y+n.y); }
	num operator-(num n) { return num(x-n.x, y-n.y); }
	num operator*(num n) { return num(x*n.x, y*n.y); }
	bool operator<(num n) {
		if (y < M) return n.y > M || x < n.x;
		return y < n.y;
	}
};

num fac[N], dp[N];

num block(ll n) {
	return fac[max(0LL,n-2)];
}

vl cycle(ll n, ll r) {
	if (n == 1) return {0};
	if (n == 2) return {1,0};
	
	vl a(n,-1);
	a[0] = n-1;
	
	FOR(i,1,n-1) {
		num u = fac[n-i-2];
		ll q = u.y > M ? 0LL : r/u.x;
		r = u.y > M ? r : r%u.x;
		
		FOR(j,0,n) {
			a[i] = j;

			bool ok = true;
			FOR(k,0,i) if (a[k] == a[i]) ok = false;

			ll x = a[i];
			while (x != -1 && x != i) x = a[x];
			if (x == i) ok = false;
			
			if (!ok) continue;

			if (q-- == 0) break;
		}
		assert(q == -1);
	}

	FOR(j,0,n) {
		bool ok = true;
		FOR(i,0,n-1) if (a[i] == j) ok = false;
		if (ok) a[n-1] = j;
	}

	return a;
}

ll res[N];
void rec(ll n, ll a, num r) {
	if (n == 0) return;
	
	FOR(k,1,n+1) {
		num cur = block(k) * dp[n-k];
		if (r < cur) {
			num u = dp[n-k];
			num q = u.y > M ? num(0) : num(r.x/u.x);
			num nr = u.y > M ? r : num(r.x%u.x);
			
		
			vl v = cycle(k,q.x);
			
			FOR(i,0,k) res[a+i] = a + v[i];
			
			rec(n-k, a+k, nr);
			return;
		} else {
			r = r - cur;
		}
	}
	memset(res,-1,sizeof res);
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	

	ll N = 55;

	fac[0] = num(1);
	FOR(n,1,N) fac[n] = num(n)* fac[n-1];

	dp[0] = num(1);
	FOR(n,1,N) FOR(k,1,n+1) {
		dp[n] = dp[n] + block(k) * dp[n-k];
	}

/*
	FOR(n,1,6) FOR(r,0,fac[max(0LL,n-2)].x) {
		vl v = cycle(n,r);
		for (ll x: v) cout << " " << x;
		cout << endl;
	}
*/

	ll tc; cin >> tc;
	while (tc--) {
		ll n, m;
		cin >> n >> m;
		
		rec(n, 0, num(m-1));
		if (res[0] < 0) cout << -1 << endl;
		else FOR(i,0,n) cout << res[i]+1 << " \n"[i+1==n];
	}
}
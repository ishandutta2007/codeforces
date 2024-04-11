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

template<int m>
struct mod {
	ll x;
	mod(ll x = 0): x((m + x%m) % m) { }
	
	mod operator+(const mod &a) const { return mod(x+a.x); }
	mod operator-(const mod &a) const { return mod(x-a.x); }
	mod operator*(const mod &a) const { return mod(x*a.x); }
	mod operator/(const mod &a) const { return *this * (a^(m-2)); }
	
	bool operator==(const mod &a) const { return x == a.x; }

	mod operator^(ll n) const {
		ll res = 1, a = x;
		for (; n; n /= 2) {
			if (n%2) res = res*a % m;
			a = a*a % m;
		}
		return mod(res);
	}
};

using num = mod<998244353>;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	ll n; cin >> n;

	vector<num> pw(n+1);
	pw[0] = 1;
	FOR(i,1,n+1) pw[i] = num(10)*pw[i-1];

	FOR(k,1,n) {
		num res = 0;
		if (n-k-1 >= 0) res = res + num(2*10*9) * pw[n-k-1];
		if (n-k-2 >= 0) res = res + num(10*9*9) * num(n-k-1) * pw[n-k-2];
		cout << res.x << " ";
	}

	cout << 10 << endl;
}
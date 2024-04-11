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

void print_poly(ll n) {
	vl p(n+1);
	if (n%2 == 0) FOR(i,0,n+1) p[i] = 1 - i%2;
	else p[n] = 1;
	FOR(i,0,n) p[i] = -1 + rand()%3;
	cout << n << endl;
	FOR(i,0,n+1) cout << p[i] << " ";
	cout << endl;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	vl a = {}, b = {1};
	
	ll n; cin >> n;
	FOR(k,1,n+1) {
		vl c(k+1);
		FOR(i,0,k-1) c[i] += a[i];
		FOR(i,0,k) c[i+1] += b[i];
		a = c, swap(a,b);
	}
	
	for (vl v: {b,a}) {
		cout << sz(v)-1 << endl;
		for (ll x: v) cout << x%2 << " ";
		cout << endl;
	}

}
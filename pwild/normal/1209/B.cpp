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
	string s; cin >> s;
	
	ll m = 1000;

	vl cnt(m);
	FOR(i,0,n) {
		ll a, b;
		cin >> a >> b;
		FOR(j,0,b) cnt[j] += s[i]-'0';
		FOR(j,b,m) cnt[j] += (s[i]-'0' + 1 + (j-b)/a) % 2;
	}
	
	cout << *max_element(all(cnt)) << endl;
}
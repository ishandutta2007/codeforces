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
	string a; cin >> a;
	
	map<char,ll> cnt;
	for (char c: a) cnt[c]++;

	ll diff = cnt['('] - cnt[')'];
	ll have = cnt['?'];
	
	if (abs(diff) > have || n%2 == 1) {
		cout << ":(" << endl;
		return 0;
	}
	
	ll pos = (have-diff)/2;
	
	for (char &c: a) if (c == '?') {
		if (--pos >= 0) c = '('; else c = ')';
	}

	bool ok = true;
	ll dep = 0;
	FOR(i,0,n) {
		if (i > 0 && dep == 0) ok = false;
		char c = a[i];
		if (c == '(') dep++;
		if (c == ')') dep--;
		if (dep < 0) ok = false;
	}

	if (ok) cout << a << endl;
	else cout << ":(" << endl;

}
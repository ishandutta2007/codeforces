#include <bits/stdc++.h>
using namespace std;
 
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef vector<int> vi;
typedef vector<ll> vll;
 
#define FOR(i, a, b) for (int i=a; i<(b); i++)
#define F0R(i, a) for (int i=0; i<(a); i++)
#define FORd(i,a,b) for (int i = (b)-1; i >= a; i--)
#define F0Rd(i,a) for (int i = (a)-1; i >= 0; i--)
#define f first
#define s second
#define mp make_pair
#define pb push_back

///

int main() {
    ios_base::sync_with_stdio(0);cin.tie(0);
	int n, m; cin >> n >> m;
	vector<string> v(n);
	F0R(i, n)
		cin >> v[i];
	ll ans = 0;
	F0R(i, m) {
		map<char,int> map;
		F0R(j, n)
			map[v[j][i]]++;
		int as = 0;
		for(auto x : map)
			as = max(as, x.s);
		int a; cin >> a;
		ans += a * as;
	}
	cout << ans << endl;
///
	return 0;
}
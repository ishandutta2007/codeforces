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
	int n, k; cin >> n >> k; k--;
	int f, l; cin >> f; l = f;
	vi v;
	F0R(i, n-1) {
		int a; cin >> a;
		v.pb(l-a);
		l = a;
	}
	sort(v.begin(), v.end());
	ll ans = l-f;
	F0R(i, k) ans += v[i];
	cout << ans << endl;
///
	return 0;
}
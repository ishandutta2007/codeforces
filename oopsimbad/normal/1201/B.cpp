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
	int n; cin >> n;
	if(n == 2) {
		int a, b; cin >> a >> b;
		cout << (a==b ? "YES" : "NO") << endl;
	} else {
		vi v(n);
		ll sum = 0;
		F0R(i, n) {
			cin >> v[i];
			sum += v[i];
		}
		sort(v.begin(), v.end());
		if(sum&1 || v[n-1]*2 > sum) cout << "NO" << endl;
		else cout << "YES" << endl;
	}
///
	return 0;
}
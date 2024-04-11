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
	int t; cin >> t;
	while(t-->0) {
		vi v;
		int n; cin >> n;
		F0R(i, n) { int a; cin >> a; v.pb(a); }
		sort(v.begin(), v.end());
		cout << max(0,min(min(*(v.end()-1), *(v.end()-2))-1, n-2)) << endl;
	}
///
	return 0;
}
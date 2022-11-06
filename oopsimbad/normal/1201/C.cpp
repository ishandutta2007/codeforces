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
	int n, k; cin >> n >> k;
	vi v(n);
	F0R(i, n)
		cin >> v[i];
	sort(v.begin(), v.end());
	int m = n/2;
	int p = v[m];
	bool print = false;
	FOR(i,m+1,n) {
		if(((ll)i-m)*(v[i]-p) > k) {
			print = true;
			cout << p + k/(i-m) << endl;
			break;
		} else {
			k -= (i-m)*(v[i]-p);
			p = v[i];
		}
	}
	if(!print) cout << p + k/(n/2+1) << endl;
///
	return 0;
}
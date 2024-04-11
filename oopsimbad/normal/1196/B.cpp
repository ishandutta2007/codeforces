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
	int q; cin >> q;
	while(q--) {
		int n, k; cin >> n >> k;
		--k;
		vi v; int c = 0;
		F0R(i, n) {
			int a; cin >> a;
			if(a&1) 
				if(k) {
					--k;
					v.pb(i+1);
				} else c ^= 1;
		}
		v.pb(n);
		if(c && !k) {
			cout << "YES" << endl;
			for(auto x : v) cout << x << " ";
		} else cout << "NO" << endl;
	}
///
	cin >> q;
	return 0;
}
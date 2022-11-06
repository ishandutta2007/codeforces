#include <bits/stdc++.h>
using namespace std;
 
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<int, pii> piii;
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
	int asdf; cin >> asdf;
	while(asdf-->0) {
		int n, m; cin >> n >> m;
		vi v(3*n);
		vi match;
		F0R(i, m) {
			int a, b;
			cin >> a >> b;
			--a; --b;
			if(!v[a]&&!v[b]) {
				v[a] = true;
				v[b] = true;
				match.pb(i);
			}
		}
		if(match.size() >= n) {
			cout << "Matching" << endl;
			F0R(i, n) cout << match[i]+1 << " ";
			cout << endl;
		} else {
			cout << "IndSet" << endl;
			int cnt = 0;
			F0R(i, 3*n) {
				if(!v[i]) {
					cout << i+1 << " ";
					if(++cnt == n) break;
				}
			}
			cout << endl;
		}
	}
///
	int qwertyuiop;
	cin >> qwertyuiop;
	return 0;
}
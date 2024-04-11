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
	while(q-->0) {
		int b, w; cin >> b >> w;
		int r = 2;
		if(w > b) {
			int t = w;
			w = b;
			b = t;
			r++;
		}
		int curcnt = 1;
		int c = 0;
		while(c/2 < w && curcnt < b) {
			c += 2;
			curcnt += 3;
		}
		if(curcnt < b) {
			cout << "NO" << endl;
			continue;
		}
		cout << "YES" << endl;
		FOR(i, 1, c+2) {
			if((i&1) && b > 0) {
				cout << r << " " << i << endl;
				b--;
			}
			else if(!(i&1) && w > 0) {
				cout << r << " " << i << endl;
				w--;
			}
		}
		FOR(i, 1, c+2) {
			if((i&1) && w>0) {
				cout << r-1 << " " << i << endl;
				w--;
				if(w > 0) {
					w--;
					cout << r+1 << " " << i << endl;
				}
			}
			if(!(i&1) && b>0) {
				cout << r-1 << " " << i << endl;
				b--;
				if(b > 0) {
					b--;
					cout << r+1 << " " << i << endl;
				}
			}
		}
	}
///
	cin >> q;
	return 0;
}
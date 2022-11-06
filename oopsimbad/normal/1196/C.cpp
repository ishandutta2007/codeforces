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
		int minx, maxx, miny, maxy;
		minx = miny = 100000;
		maxx = maxy = -100000;
		int n; cin >> n;
		while(n--) {
			int x, y; cin >> x >> y;
			int a; cin >> a;
			if(!a) maxx = max(x, maxx);
			cin >> a;
			if(!a) miny = min(y, miny);
			cin >> a;
			if(!a) minx = min(x, minx);
			cin >> a;
			if(!a) maxy = max(y, maxy);
		}
		if(minx >= maxx && miny >= maxy)
			cout << 1 << " " << minx << " " << miny << endl;
		else cout << 0 << endl;
	}
///
	cin >> q;
	return 0;
}
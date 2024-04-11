#include <bits/stdc++.h>

using namespace std;

#define ALL(x) (x).begin(), (x).end()

#ifdef LOCAL
const bool debug = true;
#else
const bool debug = false;
#define cerr if (true) {} else cout
#endif

#define int long long
#define double long double

const int INF = 1e18;
const int mod = 1e9 + 7;

int32_t main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    int t;
    cin >> t;
    while (t--) {
		int x, y, x2, y2;
		cin >> x >> y >> x2 >> y2;
		int res = abs(x - x2) + abs(y - y2) + 2;
		if (x - x2 == 0 || y - y2 == 0) {
			res -= 2;
		}
		cout << res << "\n";
	}
    
    return 0;
}/*

*/
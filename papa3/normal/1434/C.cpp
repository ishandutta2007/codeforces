#include <bits/stdc++.h>

using namespace std;

#define ALL(x) (x).begin(), (x).end()

template<class C> void mini(C &a5, C b5) { a5 = min(a5, b5); }
template<class C> void maxi(C &a5, C b5) { a5 = max(a5, b5); }

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
		int a, b, c, d;
		cin >> a >> b >> c >> d;

		if (a > b * c) {
			cout << "-1\n";
			continue;
		}
		
		int n = a / (d * b) + 1;
		cout << n * a - n * (n - 1) / 2 * d * b << "\n";
	}
    
    return 0;
}/*

*/
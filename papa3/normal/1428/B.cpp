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
		int n;
		cin >> n;
		string s;
		cin >> s;
		int ile = 0;
		int l = 0, r = 0;
		for (int i = 0; i < n; i++) {
			if (s[i] == '-' || s[(i + 1) % n] == '-') {
				ile++;
			}
			if (s[i] == '>') r++;
			if (s[i] == '<') l--;
		}
		if (l == 0 || r == 0) cout << n << "\n";
		else cout << ile << "\n";
	}
    
    return 0;
}/*

*/
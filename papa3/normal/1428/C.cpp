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
		string s, v;
		cin >> s;
		for (char c : s) {
			if (v.size() && c == 'B') v.pop_back();
			else v.push_back(c);
		}
		cout << v.size() << "\n";
	}
    
    return 0;
}/*

*/
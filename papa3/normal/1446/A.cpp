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
		int n, w;
		cin >> n >> w;
		vector<int> res;
		vector<int> v;
		
		for (int a, i = 0; i < n; i++) {
			cin >> a;
			v.push_back(a);
		}
		
		int sum = 0;
		bool czy = false;
		for (int i = 0; i < n; i++) {
			int a = v[i];
			if (a > w) continue;
			if (a >= (w + 1) / 2) {
				cout << "1\n" << i + 1 << "\n";
				czy = true;
				break;
			}
			sum += a;
			res.push_back(i);
			if (sum >= (w + 1) / 2) {
				break;
			}
		}
		if (!czy) {
			if (sum >= (w + 1) / 2) {
				cout << res.size() << "\n";
				for (int i : res) cout << " " << i + 1;
				cout << "\n";
			} else {
				cout << "-1\n";
			}
		}
		
	}
    
    return 0;
}/*

*/
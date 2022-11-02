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
    
    priority_queue<int, vector<int>, greater<int>> kol;
    int n;
    vector<pair<char, int> > v;
    
    cin >> n;
    for (int i = 0; i < 2 * n; i++) {
		char c;
		int x = 0;
		cin >> c;
		if (c == '-') {
			cin >> x;
		}
		v.push_back({c, x});
	}
	reverse(ALL(v));
	
	vector<int> res;
	kol.push(INF);
	for (auto &[c, x] : v) {
		if (c == '-') {
			if (x > kol.top()) {
				cout << "NO";
				return 0;
			}
			kol.push(x);
		} else {
			res.push_back(kol.top());
			if (res.back() == INF) {
				cout << "NO";
				return 0;
			}
			kol.pop();
		}
	}
	cout << "YES\n";
	reverse(ALL(res));
	for (int i : res) {
		cout << i << " ";
	}
    
    return 0;
}/*

*/
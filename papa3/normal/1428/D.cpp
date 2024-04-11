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
const int MAX_N = 1e5 + 100;

//int a[MAX_N];

int32_t main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    int n;
    cin >> n;
    vector<int> v2, v3;
    vector<pair<int, int> > res;
    for (int i = 1; i <= n; i++) {
		int a;
		cin >> a;
		if (a == 0) continue;
		
		int h = i;
		if (a == 1 && v2.size()) {
			h = v2.back();
			v2.pop_back();
		} else if (v3.size()) {
			res.push_back({v3.back(), i});
			v3.pop_back();
		}
		
		res.push_back({h, i});
		if (a == 2) v2.push_back(i);
		if (a == 3) v3.push_back(i);
	}
	
	if (v2.size() || v3.size()) {
		cout << -1;
	} else {
		cout << res.size() << "\n";
		for (auto i : res) {
			cout << i.first << " " << i.second << "\n";
		}
	}
    
    return 0;
}/*

*/
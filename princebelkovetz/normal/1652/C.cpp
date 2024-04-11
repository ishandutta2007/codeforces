#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <cassert>
#include <iomanip>
#include <queue>
#include <set>
#include <map>

using namespace std;
#define int long long
#define debug(x) cout << #x << " is " << x < '\n';
#define ld long double
const int mod = 1e9 + 7, N = 1e5 + 2;

signed main() {
	cin.tie(0);
	ios_base::sync_with_stdio(false);

	int tt; cin >> tt;
	while (tt--) {
		int n, sum = 0; cin >> n;
		multiset <int> heap;
		for (int i = 0, x; i < n; ++i) {
			cin >> x;
			heap.insert(x);
			sum += x;
		}
		multiset <int> cur = { sum };
		bool ok = true;
		while (cur.size() > 0) {
			int x = *cur.begin();
			if (heap.find(x) != heap.end()) {
				heap.erase(heap.find(x));
				cur.erase(cur.begin());
			}
			else if (x >= 2) {
				cur.erase(cur.begin());
				cur.insert(x / 2);
				cur.insert((x + 1) / 2);
			}
			else {
				ok = false;
				break;
			}
		}cout << (ok ? "YES" : "NO") << '\n';
	}
	
}
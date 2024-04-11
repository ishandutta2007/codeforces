#include <iostream>
#include <vector>
#include <algorithm>
#include <iomanip>
#include <string>
#include <cmath>
#include <set>
#include <map>
#include <queue>
#define endl "\n"
#define int long long
#define debug(x) cout << #x << " is " << x << endl;
using namespace std;
const int mxN = 1e5 + 7, inf = 1e9 + 5;
struct tre {
	int fir, sec, thr;
};
signed main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	cout << fixed << setprecision(2);
	int x1, y1, x2, y2; cin >> x1 >> y1 >> x2 >> y2;
	int n; cin >> n;
	set <pair <int, int>> able, used;
	for (int i = 0; i < n; ++i) {
		int z, x, y; cin >> z >> x >> y;
		for (int j = x; j <= y; ++j) able.insert({ z, j });
	}
	queue <tre> q; q.push({ x1, y1, 0 });
	while (!q.empty()) {
		tre v = q.front(); q.pop();
		
		if (used.find({ v.fir, v.sec }) != used.end() or able.find({ v.fir, v.sec }) == able.end()) continue;
		used.insert({ v.fir, v.sec });
		if (v.fir == x2 and v.sec == y2) {
			cout << v.thr << endl;
			return 0;
		}
		if (v.fir > 0) {
			q.push({ v.fir - 1, v.sec, v.thr + 1 });
		}
		if (v.fir < 1e9) {
			q.push({ v.fir + 1, v.sec, v.thr + 1 });
		}
		if (v.sec > 0) {
			q.push({ v.fir, v.sec - 1, v.thr + 1 });
		}
		if (v.fir < 1e9) {
			q.push({ v.fir, v.sec + 1, v.thr + 1 });
		}
		if (v.fir > 0 and v.sec > 0) {
			q.push({ v.fir - 1, v.sec - 1, v.thr + 1 });
		}
		if (v.fir < 1e9 and v.sec > 0) {
			q.push({ v.fir + 1, v.sec - 1, v.thr + 1 });
		}
		if (v.sec < 1e9 and v.fir > 0) {
			q.push({ v.fir - 1, v.sec + 1, v.thr + 1 });
		}
		if (v.sec < 1e9 and v.fir < 1e9) {
			q.push({ v.fir + 1, v.sec + 1, v.thr + 1 });
		}
		
	}
	cout << "-1\n"; return 0;
}
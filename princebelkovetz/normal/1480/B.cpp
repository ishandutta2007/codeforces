#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <iomanip>
using namespace std;
#define int long long
#define debug(x) cout << #x << " is " << x << '\n';

signed main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout << fixed << setprecision(3);
	int tt; cin >> tt;
	while (tt-- > 0) {
		int A, B, n; cin >> A >> B >> n;
		vector <vector <int>> m(n, vector <int>(2));
		for (int i = 0; i < n; ++i) {
			cin >> m[i][0];
		}
		for (int i = 0; i < n; ++i) {
			cin >> m[i][1];
		}
		sort(m.begin(), m.end());
		int st = 0;
		for (; st < n and B > 0; ++st) {
			int hits = (m[st][1] + A - 1) / A;
			B -= hits * m[st][0];
			if (B + m[st][0] <= 0) break;
		}
		cout << (st == n ? "YES" : "NO") << '\n';
	}
}
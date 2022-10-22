#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>
#include <iomanip>
#include <string>
#include <cmath>
#include <set>
#include <map>
#include <unordered_map>
#include <queue>
#define endl "\n";
#define int long long
#define debug(x) cout << #x << " is " << x << endl;
using namespace std;
bool cmp(pair <int, int> a, pair <int, int> b) {
	return a.second / a.first > b.second / b.first;
}
void solve() {
	int n, m, curi = 2; cin >> n >> m;
	if (n == m and n == 1) { cout << 0; return; }
	vector <vector<int>> a(n + 1, vector <int>(m + 1));
	set <int> ok;
	if (n <= m) {
		for (int i = 1; i <= n; i++) {
			a[i][1] = i * 2;
			ok.insert(i * 2);
		}
		for (int i = 3; curi != m + 1; ++i) {
			if (ok.find(i) == ok.end()) {
				a[1][curi] = i;
				++curi;
			}
		}
	}
	else {
		for (int i = 1; i <= m; i++) {
			a[1][i] = i * 2;
			ok.insert(i * 2);
		}
		for (int i = 3; curi != n + 1; ++i) {
			if (ok.find(i) == ok.end()) {
				a[curi][1] = i;
				++curi;
			}
		}
	}
	for (int i = 2; i <= n; ++i) {
		for (int j = 2; j <= m; ++j) {
			a[i][j] = a[i][1] * a[1][j]; 
		}
	}
	for (int i = 1; i <= n; ++i) {
		for (int j = 1; j <= m; ++j) {
			cout << a[i][j] << " ";
		}
		cout << endl;
	}

}
signed main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	cout << fixed << setprecision(15);
	int t;
	t = 1;
	while (t--) {
		solve();
	}
	return 0;
}
#include <iostream>
#include <string>
#include <cmath>
#include <vector>
#include <map>
#include <set>
#include <queue>
#include <deque>
#include <algorithm>
#include <unordered_map>
#include <unordered_set>
#include <stack>
#include <iomanip>
#define int long long
#define endl "\n";
#define debug(x) cout << #x << " is " << x << endl;
using namespace std;
int gcd(int a, int b) {
	if (!b) return a;
	return gcd(b, a % b);
}
void solve() {
	int n, m; pair <int, int> v; bool check;
	cin >> n >> m;
	vector <string> a(n);
	vector <vector <bool>> lol(n, vector <bool>(m)), used(n, vector <bool>(m));
	vector <pair <int, int>> go, ba;
	for (int i = 0; i < n; ++i) {
		cin >> a[i];
		for (int j = 0; j < m; ++j) {
			if (a[i][j] == 'B') ba.push_back({ i, j });
			else if (a[i][j] == 'G') go.push_back({ i, j });
		}
	}
	queue <pair<int, int>> q;
	q.push({ n - 1, m - 1 });
	check = false;
	while (q.size()) {
		v = q.front(); q.pop();
		if (used[v.first][v.second]) continue;
		used[v.first][v.second] = true;
		if (a[v.first][v.second] == '#' or a[v.first][v.second] == 'B') continue;
		if (v.first > 0 and a[v.first - 1][v.second] == 'B') continue;
		if (v.first < n - 1 and a[v.first + 1][v.second] == 'B') continue;
		if (v.second > 0 and a[v.first][v.second - 1] == 'B') continue;
		if (v.second < m - 1 and a[v.first][v.second + 1] == 'B') continue;
		lol[v.first][v.second] = true;
		if (v.first > 0) q.push({ v.first - 1, v.second });
		if (v.first < n - 1) q.push({ v.first + 1, v.second });
		if (v.second > 0) q.push({ v.first, v.second - 1 });
		if (v.second < m - 1) q.push({ v.first, v.second + 1 });
	}
	for (auto x: go){
		if (lol[x.first][x.second]) continue;
		else {
			cout << "No\n"; return;
		}
	}
	cout << "Yes\n";

}
signed main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	cout << fixed << setprecision(15);
	int t;
	cin >> t;
	while (t--) {
		solve();
	}
	return 0;
}
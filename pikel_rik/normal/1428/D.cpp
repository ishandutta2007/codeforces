#include <bits/stdc++.h>
using namespace std;

using ull = unsigned long long;
using ll = long long;
using ld = long double;

const int mod = 1e9 + 7;
const double pi = acos(-1.0);
const int inf = INT_MAX;
const int N = 1e5 + 5;

int n, a[N], nxt[N];
bool visited[N];

vector<pair<int, int>> ans;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	memset(nxt, -1, sizeof(nxt));

	cin >> n;
	for (int i = 0; i < n; i++) cin >> a[i];

	vector<int> starts[4];
	for (int i = n - 1; i >= 0; i--) {
		if (a[i] == 1) {
			starts[1].push_back(i);
		} else if (a[i] == 2) {
			if (starts[1].empty()) {
				cout << "-1\n";
				return 0;
			}
			int x = starts[1].back();
			starts[1].pop_back();
			nxt[i] = x;
			starts[2].push_back(i);
		} else if (a[i] == 3) {
			if (!starts[3].empty()) {
				int x = starts[3].back();
				nxt[i] = x;
				starts[3].back() = i;
			} else if (!starts[2].empty()) {
				int x = starts[2].back();
				starts[2].pop_back();
				nxt[i] = x;
				starts[3].push_back(i);
			} else if (!starts[1].empty()) {
				int x = starts[1].back();
				starts[1].pop_back();
				nxt[i] = x;
				starts[3].push_back(i);
			} else {
				cout << "-1\n";
				return 0;
			}
		}
	}

	for (int i = 0; i < n; i++) {
		if (a[i] == 0 or visited[i]) continue;
		int x = i, last = n + 2;
		while (x != -1) {
			visited[x] = true;
			if (a[last] == 3) {
				ans.emplace_back(last, x);
				ans.emplace_back(x, x);
			} else if (a[last] == 2) {
				ans.emplace_back(last, x);
			} else {
				ans.emplace_back(x, x);
			}
			last = x;
			x = nxt[x];
		}
	}

	cout << ans.size() << '\n';
	for (auto& [x, y] : ans) {
		cout << x + 1 << ' ' << y + 1 << '\n';
	}
	return 0;
}
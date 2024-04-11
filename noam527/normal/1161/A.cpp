#include <bits/stdc++.h>
#define CHECK cout << "ok" << endl
#define finish(x) return cout << x << endl, 0
typedef long long ll;
typedef long double ldb;
const int md = 1e9 + 7;
const ll inf = 1e18;
const int OO = 1;
const int OOO = 1;
using namespace std;

int n, k;
vector<int> a;
vector<int> pos[100005];

int possible(int x, int y) {
	if (pos[x].size() == 0 || pos[y].size() == 0) return 1;
	if (x == y) return 0;
	int p = pos[x][0];
	int q = pos[y].back();
	if (p > q) return 1;
	return 0;
}

int main() {
	ios::sync_with_stdio(0), cin.tie(0);
	cin >> n >> k;
	a.resize(k);
	for (auto &i : a) cin >> i;
	for (int i = 0; i < k; i++) pos[a[i]].push_back(i);
	int ans = 0;
	for (int i = 1; i <= n; i++) {
		if (i - 1 > 0) ans += possible(i, i - 1);
		ans += possible(i, i);
		if (i + 1 <= n) ans += possible(i, i + 1);
	}
	finish(ans);
}
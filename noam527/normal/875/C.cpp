#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <unordered_map>
#include <set>
#include <unordered_set>
#include <string>
#include <time.h>
#include <queue>
#define last(x, y) (x)[(x).size() - (y)]
#define endl '\n'
#define flush fflush(stdout), cout.flush()
#define fast ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
#define debug cout << "ok" << endl
#define in(X) ((X) - '0')
#define finish(x) return cout << x << endl, 0
typedef long long ll;
typedef long double ldb;
const int md = 1e9 + 7;
const ll hs = 199;
//const ldb eps = 1e-9, pi = acos(-1);
using namespace std;

int n, m, l;
vector<int> mand, tog;
vector<vector<int>> a, pa;
vector<int> ans;

bool check(int i) {
	int p = 0;
	while (p < a[i].size() && p < a[i + 1].size() && a[i][p] == a[i + 1][p]) p++;
	if (p == a[i].size()) return true;
	if (p == a[i + 1].size()) return false;
	if (a[i][p] > a[i + 1][p]) {
		if (mand[a[i + 1][p]] == 1 || mand[a[i][p]] == -1) return false;
		mand[a[i + 1][p]] = -1, mand[a[i][p]] = 1;
		return true;
	}
	pa[a[i + 1][p]].push_back(a[i][p]);
	return true;
}

void dfs(int x) {
	tog[x] = 1;
	for (auto &i : pa[x])
		if (!tog[i]) dfs(i);
}

int main() {
	fast;
	cin >> n >> m;
	mand.resize(m + 1, 0);
	a.resize(n);
	pa.resize(m + 1);
	tog.resize(m + 1, 0);
	for (int i = 0; i < n; i++) {
		cin >> l;
		a[i].resize(l);
		for (int j = 0; j < l; j++) cin >> a[i][j];
	}
	for (int i = 0; i < n - 1; i++)
		if (!check(i)) finish("No");
	for (int i = 1; i <= m; i++) {
		if (mand[i] == 1) tog[i] = 1;
		if (tog[i]) dfs(i);
	}
	for (int i = 1; i <= m; i++)
		if (mand[i] == -1 && tog[i]) finish("No");
	for (int i = 1; i <= m; i++)
		if (tog[i]) ans.push_back(i);
	cout << "Yes" << endl;
	cout << ans.size() << endl;
	if (ans.size()) {
		for (auto &i : ans) cout << i << " "; cout << endl;
	}
}
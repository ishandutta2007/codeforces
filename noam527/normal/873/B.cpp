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
const ldb eps = 1e-9, pi = acos(-1);
using namespace std;

int n;
string s;
vector<int> a(1, 0);
vector<vector<int>> g;

int main() {
	fast;
	cin >> n >> s;
	g.resize(2 * n + 5);
	for (auto &i : s)
		if (i == '0')
			a.push_back(a.back() - 1);
		else
			a.push_back(a.back() + 1);
	for (int i = 0; i < a.size(); i++) g[a[i] + n].push_back(i);
	int ans = 0;
	for (int i = 0; i < g.size(); i++) {
		if (g[i].size() > 1)
			ans = max(ans, last(g[i], 1) - g[i][0]);
	}
	cout << ans << endl;
}
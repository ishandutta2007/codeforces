#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <unordered_map>
#include <set>
#include <unordered_set>
#include <string>
#include <time.h>
#include <stack>
#include <queue>
#include <random>
#include <fstream>
#define endl '\n'
#define flush fflush(stdout), cout.flush()
#define fast ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
#define debug cout << "ok" << endl
#define finish(x) return cout << x << endl, 0
typedef long long ll;
typedef long double ldb;
const int md = 1e9 + 7, inf = 1e9 + 7;
const ll hs = 199;
const ldb eps = 1e-7, pi = acos(-1);
using namespace std;

int n, k, m;
vector<string> a;
vector<int> group, cost, mn;
map<string, int> ma;

int main() {
	fast;
	cin >> n >> k >> m;
	a.resize(n);
	cost.resize(n);
	for (auto &i : a) cin >> i;
	for (auto &i : cost) cin >> i;
	group.resize(n, 0);
	mn.resize(k, 2e9);
	for (int i = 0, x, y; i < k; i++) {
		cin >> x;
		while (x--)
			cin >> y, group[y - 1] = i;
	}
	for (int i = 0; i < n; i++) ma[a[i]] = group[i];
	for (int i = 0; i < n; i++) mn[group[i]] = min(mn[group[i]], cost[i]);

	ll ans = 0;
	string tmp;
	while (m--) {
		cin >> tmp;
		ans += mn[ma[tmp]];
	}
	cout << ans << endl;
}
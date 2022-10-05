#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <set>
#include <string>
#define last(x, y) (x)[(x).size() - y]
#define endl '\n'
#define flush fflush(stdout), cout.flush()
#define fast ios::sync_with_stdio(0), cin.tie(0)
#define debug cout << "ok" << endl
#define in(X) ((X) - '0')
const int md = 1e9 + 7;
typedef long long ll;
typedef long double ldb;
using namespace std;

int n;
vector<vector<int>> ans;
vector<int> vis, p;

void scan(int v) {
	ans.push_back(vector<int>());
	last(ans, 1).push_back(v + 1);
	vis[v] = 1;
	v = p[v];
	while (!vis[v]) {
		last(ans, 1).push_back(v + 1);
		vis[v] = 1;
		v = p[v];
	}
}

int main() {
	fast;
	cin >> n;
	vector<pair<int, int>> a(n);
	vis.resize(n, 0), p.resize(n);
	for (int i = 0; i < n; i++) cin >> a[i].first, a[i].second = i;
	sort(a.begin(), a.end());
	for (int i = 0; i < n; i++)
		p[a[i].second] = i;
	for (int i = 0; i < n; i++)
		if (!vis[i]) scan(i);
	
	cout << ans.size() << endl;
	for (auto &i : ans) {
		cout << i.size() << " ";
		for (auto j : i) cout << j << " ";
		cout << endl;
	}
}
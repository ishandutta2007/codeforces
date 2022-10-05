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
const int md = 1e9 + 7;
typedef long long ll;
typedef long double ldb;
using namespace std;

int m;
vector<int> a, ans;
vector<pair<int, int>> b;

bool in(pair<int, int> &x, pair<int, int> &y) { return x.first < y.first; }
bool de(int x, int y) { return x > y; }

int main() {
	fast;
	cin >> m;
	a.resize(m), b.resize(m), ans.resize(m);
	for (int i = 0; i < m; i++) cin >> a[i];
	for (int i = 0; i < m; i++) cin >> b[i].first, b[i].second = i;
	sort(a.begin(), a.end(), de);
	sort(b.begin(), b.end(), in);
	for (int i = 0; i < m; i++)
		ans[b[i].second] = a[i];
	for (auto i : ans) cout << i << " "; cout << endl;
}
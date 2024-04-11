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

bool cmp(pair<int, int> &a, pair<int, int> &b) {
	if (a.first != b.first) return a.first < b.first;
	return a.second < b.second;
}

int main() {
	fast;
	int n, cnt = 0;
	cin >> n;
	vector<pair<int, int>> eve;
	for (int i = 0, l, r; i < n; i++) {
		cin >> l >> r;
		eve.push_back({ l, 0 }), eve.push_back({ r, 1 });
	}
	sort(eve.begin(), eve.end(), cmp);
	for (auto &i : eve) {
		if (i.second == 0) cnt++;
		else cnt--;
		if (cnt > 2) {
			cout << "NO" << endl;
			return 0;
		}
	}
	cout << "YES" << endl;
}
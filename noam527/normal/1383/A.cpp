#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <queue>
#include <set>
#include <map>
#define finish(X) return cout << (X) << endl, 0
typedef long long ll;
typedef long double ldb;
const int md = 1e9 + 7;
const ll inf = 2e18;
const int OO = 1;
using namespace std;

int n;
string a, b;

void solve() {
	cin >> n >> a >> b;
	for (int i = 0; i < n; i++) {
		if (a[i] > b[i]) {
			cout << "-1\n";
			return;
		}
	}
	if (a == b) {
		cout << "0\n";
		return;
	}
	vector<vector<int>> op;
	while (a != b) {
		char mn = 'z' + 1;
		for (int i = 0; i < n; i++) {
			if (a[i] != b[i])
				mn = min(mn, a[i]);
		}
		char mn2 = 'z' + 1;
		vector<int> pos;
		for (int i = 0; i < n; i++)
			if (a[i] == mn && a[i] != b[i])
				mn2 = min(mn2, b[i]);
		for (int i = 0; i < n; i++)
			if (a[i] == mn && a[i] != b[i])
				pos.push_back(i), a[i] = mn2;
		op.push_back(pos);
	}
	int ans = 1;
	for (int i = 1; i < op.size(); i++)
		if (op[i - 1] != op[i])
			ans++;
	cout << ans << endl;
}

int main() {
	ios::sync_with_stdio(0), cin.tie(0);
	int t;
	cin >> t;
	while (t--) solve();
}
#include <bits/stdc++.h>
#define finish(x) return cout << x << endl, 0
typedef long long ll;
typedef long double ldb;
const int md = 1e9 + 7;
const ll inf = 4e18;
const int OO = 1;
const int OOO = 1;
using namespace std;

int n;
string a, b;

void solve() {
	cin >> n >> a >> b;
	vector<int> op;
	for (int i = n - 1; i >= 0; i--) {
		if (a[i] != b[i]) {
			op.push_back(i + 1);
			op.push_back(1);
			op.push_back(i + 1);
		}
	}
	cout << op.size() << " ";
	for (const auto &i : op) cout << i << " "; cout << endl;
}

int main() {
	ios::sync_with_stdio(0), cin.tie(0);
	int tst;
	cin >> tst;
	while (tst--) solve();
}
#include <bits/stdc++.h>
#define CHECK cout << "ok" << endl
#define finish(x) return cout << x << endl, 0
typedef long long ll;
typedef long double ldb;
const int md = 1e9 + 7;
const ll inf = 1e18;
const int OO = 0;
const int OOO = 1;
using namespace std;

int n, m;
int a[505][505];
vector<int> ans;

void justend() {
	cout << "TAK\n";
	for (const auto &i : ans) cout << i + 1 << " ";
	exit(0);
}

int main() {
	ios::sync_with_stdio(0), cin.tie(0);
	cin >> n >> m;
	for (int i = 0; i < n; i++) for (int j = 0; j < m; j++)
		cin >> a[i][j];
	ans.resize(n, 0);
	int x = 0;
	for (int i = 0; i < n; i++) x ^= a[i][0];
	if (x != 0) justend();
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++)
			if (a[i][0] != a[i][j]) {
				ans[i] = j;
				justend();
			}
	}
	cout << "NIE";
}
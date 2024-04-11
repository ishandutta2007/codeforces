#include <bits/stdc++.h>
#define finish(x) return cout << x << endl, 0
typedef long long ll;
typedef long double ldb;
const int md = 1e9 + 7;
const ll inf = 2e18;
const int OO = 1;
const int OOO = 1;
using namespace std;

int n;
vector<pair<int, int>> a;

int main() {
	ios::sync_with_stdio(0), cin.tie(0);
	cin >> n;
	for (int i = 0; i <= n; i++) {
		int st = 2 * i;
		for (int j = 0; j < 3; j++) for (int k = 0; k < 3; k++)
			if (j != 1 || k != 1)
				a.emplace_back(st + j, st + k);
	}
	sort(a.begin(), a.end());
	a.resize(unique(a.begin(), a.end()) - a.begin());
	cout << a.size() << endl;
	for (const auto &i : a) cout << i.first << " " << i.second << endl;
}
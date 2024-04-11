#include <bits/stdc++.h>
#define finish(x) return cout << x << endl, 0
typedef long long ll;
typedef long double ldb;
const int md = 1e9 + 7;
const ll inf = 1e18;
const int OO = 0;
const int OOO = 1;
using namespace std;

int n;

int main() {
	ios::sync_with_stdio(0), cin.tie(0);
	cin >> n;
	if (n % 2 == 0) finish("NO");
	cout << "YES\n";
	vector<int> ans(2 * n);
	int nxt = 1;
	for (int i = 0; i < n; i++) {
		if (i % 2 == 0) {
			ans[i] = nxt;
			ans[i + n] = nxt + 1;
		}
		else {
			ans[i] = nxt + 1;
			ans[i + n] = nxt;
		}
		nxt += 2;
	}
	for (const auto &i : ans) cout << i << " "; cout << '\n';

}
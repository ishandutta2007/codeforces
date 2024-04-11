#include <bits/stdc++.h>
#define finish(x) return cout << x << endl, 0
typedef long long ll;
typedef long double ldb;
const int md = 1e9 + 7;
const ll inf = 2e18;
const int OO = 1;
const int OOO = 1;
using namespace std;
 
int n, k;
vector<int> a;
 
void solve() {
	cin >> n >> k;
	a.resize(n);
	for (auto &i : a) cin >> i;
	int cnt = 0;
	for (int i = 0; i + 1 < n; i++)
		if (a[i] != a[i + 1]) cnt++;
	if (cnt == 0) {
		cout << "1\n";
		return;
	}
	if (k == 1) {
		cout << "-1\n";
		return;
	}
	k--;
	cout << (cnt + k - 1) / k << '\n';
}
 
int main() {
	ios::sync_with_stdio(0), cin.tie(0);
	int tst = 1;
	cin >> tst;
	while (tst--) solve();
}
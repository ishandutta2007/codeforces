#include <bits/stdc++.h>
typedef long long ll;
typedef long double ldb;
const int md = 998244353;
const ll inf = 2e18;
const int OO = 1;
using namespace std;

int n, k;
string s;

void solve() {
	cin >> n >> k >> s;
	int sz = n / k;
	int cnt[26] = {};
	for (auto &i : s) cnt[i - 'a']++;
	for (int i = 0; i < k; i++) {
		int j = 0;
		for (j = 0; j < sz && cnt[j] > 0; j++) {
			cnt[j]--;
		}
		cout << char('a' + j);
	}
	cout << '\n';
}

int main() {
	ios::sync_with_stdio(0), cin.tie(0);
	int tst = 1;
	cin >> tst;
	while (tst--) solve();
}
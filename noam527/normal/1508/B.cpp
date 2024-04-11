#include <bits/stdc++.h>
typedef long long ll;
typedef long double ldb;
const int md = 1e9 + 7;
const ll inf = 3e18;
const int OO = 1;
using namespace std;

ll n;
ll k;

void solve() {
	cin >> n >> k;
	if (n <= 62 && (1LL << (n - 1)) < k) {
		cout << "-1\n";
		return;
	}
	vector<int> res;
	ll left = n;
	while (left > 62) {
		res.push_back(1);
		left--;
	}
	while (left > 0) {
		ll sum = 0, cur = left - 1;
		int cnt = 1;
		while (sum + (1LL << (cur - 1)) < k && cur >= 1) {
			sum += (1LL << (cur - 1));
			cnt++;
			cur--;
		}
		res.push_back(cnt);
		k -= sum;
		left -= cnt;
	}
	int nxt = 1;
	for (const auto &i : res) {
		for (int j = nxt + i - 1; j >= nxt; j--) cout << j << " ";
		nxt += i;
	}
	cout << '\n';
}

int main() {
	ios::sync_with_stdio(0), cin.tie(0);
	int tst = 1;
	cin >> tst;
	while (tst--) solve();
}
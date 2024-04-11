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
vector<int> a;

ll calc(const vector<int> &c, int sum) {
	int nxt = n - 1;
	ll ans = 0;
	for (int i = 0; i < n; i++) {
		while (nxt >= 0 && c[i] + c[nxt] > sum) nxt--;
		int add = nxt + 1;
		if (nxt >= i) ans += add - 1;
		else ans += add;
	}
	return ans / 2;
}

int calc(int b) {
	ll ans = 0;
	vector<int> c(n);
	for (int i = 0; i < n; i++)
		c[i] = a[i] % (2 * b);
	sort(c.begin(), c.end());
	ans = calc(c, 2 * b - 1) - calc(c, b - 1);
	ans += calc(c, 4 * b - 1) - calc(c, 3 * b - 1);
	return ans & 1;
}

int main() {
	ios::sync_with_stdio(0), cin.tie(0);
	cin >> n;
	a.resize(n);
	for (auto &i : a) cin >> i;
	int ans = 0;
	for (int b = 0; b < 30; b++)
		if (calc(1 << b))
			ans |= (1 << b);
	cout << ans << '\n';
}
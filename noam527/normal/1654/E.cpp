#include <bits/stdc++.h>
typedef long long ll;
typedef long double ldb;
const int md = 998244353;
const ll inf = 3e18;
const int OO = 1;
using namespace std;

const int N = 100005;
const int K = 444;

int n;
vector<int> a, b;

int attempt1(int add) {
	for (int i = 0; i < n; i++)
		b[i] = a[i] + add * i;
	sort(b.begin(), b.end());
	int mx = 1, cur = 1;
	for (int i = 1; i < n; i++) {
		if (b[i - 1] == b[i]) cur++;
		else cur = 1;
		if (mx < cur) mx = cur;
	}
	return mx;
}

int attempt2(int i, int j) {
	if (i > j) swap(i, j);
	if ((a[j] - a[i]) % (j - i) != 0) return 0;
	int m = (a[j] - a[i]) / (j - i);
	if (abs(m) <= K)
		return 0;
	int res = 0;
	for (int x = max(0, i - N / K); x <= min(n - 1, j + N / K); x++) {
		if (a[x] - (ll)m * (x - i) == a[i])
			res++;
	}
	return res;
}

void solve() {
	cin >> n;
	a.resize(n);
	b.resize(n);
	for (auto &i : a) cin >> i;
	int mx = 1;
	for (int i = -K; i <= K; i++)
		mx = max(mx, attempt1(i));

	for (int i = 0; i < n; i++) {
		for (int j = i + 1; j < n && j - i <= N / K && j - i <= N / K / mx + 3; j++)
			mx = max(mx, attempt2(i, j));
	}
	cout << n - mx << '\n';
}

int main() {
	ios::sync_with_stdio(0), cin.tie(0);
	int tst = 1;
	//cin >> tst;
	while (tst--) solve();
}
#include <bits/stdc++.h>

using namespace std;

const int N = 5e6 + 50;
int pri[N], tot;
bool vis[N];
long long f[N];

void init(int n = 5e6) {
	for (int i = 2; i <= n; ++i) {
		if (!vis[i]) {
			pri[++tot] = i;
			f[i] = 1;
		}
		for (int j = 1; j <= tot && i * pri[j] <= n; ++j) {
			vis[i * pri[j]] = true;
			f[i * pri[j]] = f[i] + 1;
			if (i % pri[j] == 0)
				break;
		}
	}
	for (int i = 1; i <= n; ++i)
		f[i] += f[i - 1];
}

void solve() {
	int a, b;
	cin >> a >> b;
	cout << f[a] - f[b] << "\n";
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	init();
	int T = 1;
	cin >> T;
	while (T--) {
		solve();
	}
}
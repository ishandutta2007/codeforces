#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 50;
int p[N];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	int T;
	cin >> T;

	while (T--) {
		int n;
		cin >> n;
		cout << n << '\n';
		iota(p, p + n + 1, 0);
		auto print = [&]() {
			for (int i = 1; i <= n; ++i)
				cout << p[i] << " \n"[i == n];
		};
		for (int i = 1; i <= n; ++i) {
			print();
			if (i < n) swap(p[i], p[i + 1]);
		}
	}
}
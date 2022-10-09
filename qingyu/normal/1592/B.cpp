#include <bits/stdc++.h>

using namespace std;
int a[123456], b[123456];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	int t;
	cin >> t;
	while (t--) {
		int n, x;
		cin >> n >> x;
		for (int i = 1; i <= n; ++i)  {
			cin >> a[i];
			b[i] = a[i];
		}	
		sort(b + 1, b + n + 1);
		bool ok = true;
		for (int i = 1; i <= n; ++i)
			if (a[i] != b[i]) {
				if (i - x < 1 && i + x > n)
				{
					ok = false;
					break;
				}	
			}
		puts(ok ? "YES" : "NO");
	}
}
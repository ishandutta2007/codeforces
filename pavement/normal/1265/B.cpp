#include <bits/stdc++.h>
using namespace std;

int a[200005], p[200005];

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int t, n;
	cin >> t;
	while (t--) {
		int cc = 0;
		cin >> n;
		for (int i = 1; i <= n; i++)
			cin >> a[i], p[a[i]] = i;
		a[0] = a[n + 1] = 1e9;
		for (int i = 1; i <= n; i++) {
			int pos = p[i];
			if (a[pos - 1] < i && a[pos + 1] < i) cc--;
			else if (a[pos - 1] > i && a[pos + 1] > i) cc++;
			cout << (cc == 1);
		}
		cout << '\n';
	}
}
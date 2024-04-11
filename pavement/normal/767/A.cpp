#include <bits/stdc++.h>
using namespace std;
#define int long long

int n, a[100005];
bool s[100005];

main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n;
	for (int i = 1; i <= n; i++) cin >> a[i];
	for (int i = 1, curm = n; i <= n; i++) {
		s[a[i]] = 1;
		if (a[i] == curm) {
			for (int j = curm; j; j--)
				if (s[j]) cout << j << ' ', curm = j - 1;
				else break;
		}
		cout << '\n';
	}
}
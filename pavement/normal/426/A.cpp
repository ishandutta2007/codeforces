#include <bits/stdc++.h>
using namespace std;
#define int long long
#define mp make_pair
#define mt make_tuple
#define pb push_back
#define ppb pop_back
#define eb emplace_back
typedef long double ld;

int a[105];

main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n, s;
	cin >> n >> s;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}
	sort(a + 1, a + 1 + n);
	for (int i = 1; i < n; i++) s -= a[i];
	if (s >= 0) cout << "YES\n";
	else cout << "NO\n";
}
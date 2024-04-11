#include <bits/stdc++.h>
using namespace std;
#define int long long
#define mp make_pair
#define mt make_tuple
#define pb push_back
#define pf push_front
#define ppb pop_back
#define ppf pop_front
#define eb emplace_back
typedef long double ld;

main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n, t = 0;
	string a, b;
	cin >> n >> a >> b;
	for (int i = 0; i < n; i++) {
		t += min({9 - (a[i] - '0') + (b[i] - '0') + 1, (a[i] - '0') + (9 - b[i] + '0') + 1, abs(a[i] - b[i])});
	}
	cout << t << '\n';
}
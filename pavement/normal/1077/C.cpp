#include <bits/stdc++.h>
using namespace std;
#define int long long

int N, S, a[200005], pf[200005], sf[200005];
vector<int> v;

main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> N;
	for (int i = 1; i <= N; i++) cin >> a[i], S += a[i];
	for (int i = 1; i <= N; i++) pf[i] = max(a[i], pf[i - 1]);
	for (int i = N; i >= 1; i--) sf[i] = max(a[i], sf[i + 1]);
	for (int i = 1; i <= N; i++) {
		int mx = max(pf[i - 1], sf[i + 1]);
		if (mx == S - a[i] - mx) v.push_back(i);
	}
	cout << v.size() << '\n';
	for (int i : v) cout << i << ' ';
	cout << '\n';
}
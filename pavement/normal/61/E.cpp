#include <bits/stdc++.h>
using namespace std;
#define int long long

int ft[1000005], a[1000005], sl[1000005], gt[1000005], cnt;
pair<int, int> s[1000005];

int ls(int x) {
	return x & -x;
}

main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) cin >> a[i], s[i] = make_pair(a[i], i);
	sort(s, s + n);
	for (int i = 0; i < n; i++)
		a[s[i].second] = i + 1;
	memset(s, 0, sizeof s);
	for (int i = n - 1; i >= 0; i--) {
		for (int p = a[i] - 1; p; p -= ls(p)) sl[i] += ft[p];
		for (int p = a[i]; p <= n; p += ls(p)) ft[p]++;
	}
	memset(ft, 0, sizeof ft);
	for (int i = 0; i < n; i++) {
		for (int p = a[i]; p; p -= ls(p)) gt[i] += ft[p];
		gt[i] = i - gt[i];
		for (int p = a[i]; p <= n; p += ls(p)) ft[p]++;
	}
	for (int i = 0; i < n; i++)
		cnt += sl[i] * gt[i];
	cout << cnt << '\n';
}
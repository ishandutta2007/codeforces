#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ar array

int n, p[100000], l[100000], r[100000], pre[100000], suf[100000];

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n;
	for (int i = 0; i < n; ++i)
		cin >> p[i];
	for (int i = 1; i < n; ++i)
		l[i] = p[i - 1] > p[i] ? l[i - 1] + 1 : 0;
	for (int i = n - 2; ~i; --i)
		r[i] = p[i + 1] > p[i] ? r[i + 1] + 1 : 0;
	for (int i = 0; i < n; ++i) {
		pre[i] = max(l[i], r[i]);
		if (i)
			pre[i] = max(pre[i], pre[i - 1]);
	}
	for (int i = n - 1; ~i; --i) {
		suf[i] = max(l[i], r[i]);
		if (i + 1 < n)
			suf[i] = max(suf[i], suf[i + 1]);
	}
	int ans = 0;
	for (int i = 1; i < n - 1; ++i) {
		if (p[i - 1] > p[i] || p[i + 1] > p[i])
			continue;
		int j = i, x = 0, y = 0;
		while(j && p[j - 1] < p[j])
			--j, ++x;
		j = i;
		while(j + 1 < n && p[j + 1] < p[j])
			++j, ++y;
		//cout << x << " " << y << "\n";
		if (x != y || x % 2)
			continue;
		int big = max(l[i - x], r[i + x]);
		if (i - x)
			big = max(big, pre[i - x - 1]);
		if (i + x + 1 < n)
			big = max(big, suf[i + x + 1]);
		ans += x > big;
	}
	cout << ans;
	return 0;
}
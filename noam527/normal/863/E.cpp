#include <bits/stdc++.h>
using namespace std;

int n, i, a[2][200005];
map<int, int> m;

int main() {
	cin >> n;
	vector<int> b(4*n + 5000, 0);
	for (i = 0; i < n; i++)
		cin >> a[0][i] >> a[1][i], m[a[0][i]] = m[a[1][i]] = m[a[0][i] - 1] = m[a[1][i] + 1] = 0;

	int x = 1;
	for (auto j = m.begin(); j != m.end(); j++) j->second = x++;
	for (i = 0; i < n; i++) a[0][i] = m[a[0][i]], a[1][i] = m[a[1][i]];

	for (i = 0; i < n; i++) b[a[0][i]]++, b[a[1][i] + 1]--;
	for (i = 1; i < b.size(); i++) b[i] += b[i - 1];
	for (i = 1; i < b.size(); i++) b[i] = min(b[i], 2);
	for (i = 1; i < b.size(); i++) b[i] += b[i - 1];
	for (i = 0; i < n; i++)
		if (b[a[1][i]] - b[a[0][i] - 1] == 2 * (a[1][i] - a[0][i] + 1)) return cout << i + 1 << endl, 0;
	cout << -1 << endl;
}
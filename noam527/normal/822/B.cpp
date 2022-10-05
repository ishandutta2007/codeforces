#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	int mn = 1e9, mnloc = 0, cnt = 0, n, m;
	string s, t;
	cin >> n >> m >> s >> t;
	for (int i = 0; i + n - 1 < m; i++) {
		cnt = n;
		for (int j = 0; j < n; j++)
			cnt -= s[j] == t[j + i];
		if (cnt < mn)
			mn = cnt, mnloc = i;
	}
	cout << mn << endl;
	for (int i = 0; i < n; i++)
		if (s[i] != t[i + mnloc]) cout << i + 1 << " ";
	return 0;
}
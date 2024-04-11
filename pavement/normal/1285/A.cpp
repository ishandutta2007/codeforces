#include <bits/stdc++.h>
using namespace std;
#define int long long

main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n, le = 0, ri = 0;
	string s;
	cin >> n >> s;
	for (int i = 0; i < n; i++) {
		if (s[i] == 'L') le++;
		else ri++;
	}
	cout << ri + le + 1 << '\n';
}
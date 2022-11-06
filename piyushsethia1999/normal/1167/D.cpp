#include <bits/stdc++.h>
#define pb emplace_back
#define mp make_pair

using namespace std;

int32_t main()
{
	ios::sync_with_stdio(false); cin.tie(NULL); cout.precision(10);
	int n; cin >> n;
	string s; cin >> s;
	int u = 0;
	int v = 0;
	for (int i = 0; i < n; ++i) {
		if (s[i] == '(') {
			cout << u; u ^= 1;
		} else {
			cout << v; v ^= 1;
		}
	}
}
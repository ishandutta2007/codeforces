#include <bits/stdc++.h>
#define pb emplace_back
#define mp make_pair

using namespace std;

int32_t main()
{
	ios::sync_with_stdio(false); cin.tie(NULL); cout.precision(10);
	int n; cin >> n;
	string s; cin >> s;
	int ma = 100000000;
	for (int i = 0; i <= n - 4; ++i) {
		int u = int(min(abs(s[i] - 'A'), 26 - abs(s[i] - 'A'))) + int(min(abs(s[i + 1] - 'C'), 26 - abs(s[i + 1] - 'C'))) + int(min(abs(s[i + 2] - 'T'), (26 - abs(s[i + 2] - 'T')))) + int(min(abs(s[i + 3] - 'G'), 26 - abs(s[i + 3] - 'G')));
		ma = min(ma, u);
	}
	cout << ma;
}
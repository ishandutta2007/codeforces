#include <bits/stdc++.h>
#define pb emplace_back
#define mp make_pair
#define int long long

using namespace std;

int32_t main()
{
	ios::sync_with_stdio(false); cin.tie(NULL); cout.precision(10);
	int n; cin >> n;
	int b[26] = {};
	vector<string> a(n); for (int o = 0; o < n; o++) { cin >> a[o]; }
	for (int i = 0; i < n; ++i) {
		b[a[i][0] - 'a']++;
	}
	int u = 0;
	for (int i = 0; i < 26; ++i) {
		int u1 = b[i] / 2;
		int u2 = b[i] - u1;
		u += (u1 * (u1 - 1)) / 2 + (u2 * (u2 - 1)) / 2;
	}
	cout << u;
}
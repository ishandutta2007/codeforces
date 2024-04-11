#include <bits/stdc++.h>
#define pb emplace_back
#define mp make_pair
#define int long long

using namespace std;

int32_t main()
{
	ios::sync_with_stdio(false); cin.tie(NULL); cout.precision(10);
	int n; cin >> n;
	int T; cin >> T;
	std::vector<int> t(n);
	vector<int> s(n); for (int o = 0; o < n; o++) { cin >> s[o] >> t[o]; }
	int gap = 100000000;
	int in = -1;
	for (int i = 0; i < n; ++i) {
		int g = -1;
		if (s[i] >= T) {
			g = s[i] - T;
		} else {
			g = ((T - s[i] + t[i] - 1) / t[i]) * (t[i]) + s[i] - T;
		}
		if (g < gap) {
			in = i;
			gap = g;
		} 
	}
	cout << in + 1;
}
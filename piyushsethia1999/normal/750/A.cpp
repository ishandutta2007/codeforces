#include <bits/stdc++.h>
#define pb emplace_back
#define mp make_pair

using namespace std;

int32_t main()
{
	ios::sync_with_stdio(false); cin.tie(NULL); cout.precision(10);
	int n; cin >> n;
	int k; cin >> k;
	int ti = 60 * 4 - k;
	int ans = 0;
	for (int i = 1; i <= n; ++i) {
		if ((5 * (i * (i + 1))) / 2 <= ti) {
			ans = i;
		} 
	}
	cout << ans;
}
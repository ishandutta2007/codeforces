#include <bits/stdc++.h>
#define pb emplace_back
#define mp make_pair
#define int long long

using namespace std;

int32_t main()
{
	ios::sync_with_stdio(false); cin.tie(NULL); cout.precision(10);
	int n; cin >> n;
	int res = 0;
	for (int i = 1; i <= n; ++i) {
		res = (res + (1ll << i));
	}
	cout << res;
}
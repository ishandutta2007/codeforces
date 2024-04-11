#include <bits/stdc++.h>
#define pb emplace_back
#define mp make_pair

using namespace std;

int32_t main()
{
	ios::sync_with_stdio(false); cin.tie(NULL); cout.precision(10);
	int n; cin >> n;
	int k; cin >> k;
	if (n == k || k == 0) {
		cout << (n - 1) + (n) + (n + 1);
	} else {
		cout << (3 * n) + min(k - 1, n - k);
	}
}
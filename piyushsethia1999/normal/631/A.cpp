#include <bits/stdc++.h>
#define pb emplace_back
#define mp make_pair
#define int long long

using namespace std;

int32_t main()
{
	ios::sync_with_stdio(false); cin.tie(NULL); cout.precision(10);
	int n; cin >> n;
	int a[n]; for (int o = 0; o < n; o++) { cin >> a[o]; }
	int b[n]; for (int o = 0; o < n; o++) { cin >> b[o]; }
	for (int i = 1; i < n; ++i) {
		a[i] |= a[i - 1];
		b[i] |= b[i - 1];
	}
	cout << a[n - 1] + b[n - 1] << "\n";
}
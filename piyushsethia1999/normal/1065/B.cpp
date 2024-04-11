#include <bits/stdc++.h>
#define pb emplace_back
#define mp make_pair
#define int long long

using namespace std;

int p1(int n) {	return (n * (n - 1ll)) / 2ll; }
int p2(int n)
{
	for (int i = 0; i <= (100000ll); ++i) {
		if (p1(i) >= n) {
			return (i);
		}
	}
}
int32_t main()
{
	int n; cin >> n;
	int m; cin >> m;
	int r = p2(m);
	cout << max(n - m * 2ll, 0ll) << " " << n - r;
}
#include <bits/stdc++.h>
#define pb emplace_back
#define mp make_pair
#define int long long

using namespace std;

int co(int l)
{
	if (l == 0)
		return 0;
	if (l & 1)
		return -((l + 1) / 2);
	return (l / 2);
}

int32_t main()
{
	ios::sync_with_stdio(false); cin.tie(NULL); cout.precision(10);
	int q;
	cin >> q;
	while (q--) {
		int l; cin >> l;
		int r; cin >> r;
		cout << (co(r) - co(l - 1)) << "\n";
	}
}
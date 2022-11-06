#include <bits/stdc++.h>
#define pb emplace_back
#define mp make_pair
#define int long long

using namespace std;

int32_t main()
{
	ios::sync_with_stdio(false); cin.tie(NULL); cout.precision(10);
	int n; cin >> n;
	int g = 0;
	vector<int> a(n); for (int o = 0; o < n; o++) { cin >> a[o]; g += a[o];}
	int m; cin >> m;
	int f = 0;
	vector<int> b(m); for (int o = 0; o < m; o++) { cin >> b[o]; f += b[o];}
	if (f != g) {
		cout << -1;
		return 0;
	}
	int l = 0;
	int i1 = 0, i2 = 0;
	int l1 = a[0];
	int l2 = b[0];
	while (i1 < n && i2 < m) {
		if (l1 == l2)
		{
			l++; i1++; i2++;
			if (i1 == n)
				break;
			else {
				l1 = a[i1]; l2 = b[i2];
			}
		}
		else if (l1 < l2)
			l1 += a[++i1];
		else
			l2 += b[++i2];
	}
	cout << l;
}
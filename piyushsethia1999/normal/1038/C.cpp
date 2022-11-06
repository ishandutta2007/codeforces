#include <bits/stdc++.h>
#define pb emplace_back
#define mp make_pair
#define int long long

using namespace std;

int32_t main()
{
	ios::sync_with_stdio(false); cin.tie(NULL); cout.precision(10);
	int n; cin >> n;
	vector<int> a(n); for (int o = 0; o < n; o++) { cin >> a[o]; }
	vector<int> b(n); for (int o = 0; o < n; o++) { cin >> b[o]; }
	sort(a.rbegin(), a.rend());
	sort(b.rbegin(), b.rend());
	int a1 = 0;
	int b1 = 0;
	int c = 0;
	int sc = 0;
	while (a1 < n || b1 < n) {
		if (!(c & 1))
		{
			if (a1 < n && (b1 == n || (b1 < n && a[a1] > b[b1])))
				sc += a[a1++];
			else
				b1++;
		}
		else {
			if (b1 < n && (a1 == n || (a1 < n && a[a1] < b[b1])))
				sc -= b[b1++];
			else
				a1++;
		}
		c++;
	}
	cout << sc;
}
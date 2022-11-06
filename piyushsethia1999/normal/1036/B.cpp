#include <bits/stdc++.h>
#define pb emplace_back
#define mp make_pair
#define int long long

using namespace std;

int krabs(int a)
{
	if (a > 0)
		return a;
	return -a;
}

int32_t main()
{
	ios::sync_with_stdio(false); cin.tie(NULL); cout.precision(10);
	int q; cin >> q;
	while (q--) {
		int n; cin >> n;
		int m; cin >> m;
		int k; cin >> k;
		n = krabs(n);
		m = krabs(m);
		if (n < m)
			swap(n, m);
		if ((n + m) & 1) {
			k--;
			if (!(k & 1)) {
				if (n & 1)
					n--;
				else
					m--;
			}
			else {
				if (m & 1)
					n--;
				else
					m--;
			}
		}
		if (max(n, m) > k) {
			cout << -1;
		}
		else {
			if ((!(n & 1)) && (!(m & 1))) {

				if (k & 1)
					cout << k - 2;
				else
					cout << k;
			}

			else if (n & 1 && m & 1) {

				if (k & 1)
					cout << k;
				else
					cout << k - 2;
			}
		}
		cout << "\n";
	}
}
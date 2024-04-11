#include<bits/stdc++.h>
using namespace std;

#define int long long


#define pb push_back


signed main()
{
	ios_base::sync_with_stdio(0);
	cout.tie(0);
	cin.tie(0);
	int n, k;
	cin >> n >> k;
	vector <int> v(n);
	for (int i = 0; i < n; i++) {
		cin >> v[i];
	}
	vector <pair<int, int>> p(k, make_pair(-1, -1));
	vector <bool> u(n, false);
	int cnt = 0, s = 0;
	while (cnt < n) {
		for (int i = 0; i < k; i++) {
			if (p[i].first != -1 && p[i].second != -1) {
				if (p[i].first > v[p[i].second]) {
					cnt++;
					p[i] = make_pair(-1, -1);
				}
			}
		}
		for (int i = 0; i < k; i++) {
			if (p[i].first == -1 && s < n) {
				p[i] = make_pair(1, s);
				s++;
			}
		}
		int d = round((((long double)cnt) / ((long double)n) * 100.0));
		for (int i = 0; i < k; i++) {
			if (p[i].first == d && p[i].second != -1) {
				u[p[i].second] = 1;
			}
			p[i].first++;
		}
	}
	cnt = 0;
	for (int i = 0; i < n; i++) {
		if (u[i]) {
			cnt++;
		}
	}
	cout << cnt;
	return 0;
}
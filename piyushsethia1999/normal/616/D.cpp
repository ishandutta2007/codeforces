#include <bits/stdc++.h>
#define pb emplace_back
#define mp make_pair

using namespace std;

int32_t main()
{
	ios::sync_with_stdio(false); cin.tie(NULL);
	int n; cin >> n;
	int k; cin >> k;
	vector<int> a(n + 1); for (int o = 0; o < n; o++) { cin >> a[o + 1]; }
	int f = 1;
	int s = 0;
	std::map<int, int> m;
	int si = 0;
	while(s < n && si < k) {
		s++;
		if (m[a[s]] == 0)
			si++;
		m[a[s]] = s;
	}
	int ma = s - f + 1;
	int l = f, r = s;
	while(s < n) {
		while(s < n && si < k) {
			s++;
			if (m[a[s]] == 0)
				si++;
			m[a[s]] = s;
		}
		while(s < n) {
			if(m[a[s + 1]] != 0)
			{
				s++;
				m[a[s]] = s;
			}
			else {
				break;
			}
		}
		if(ma < (s - f + 1)) {
			l = f;
			r = s;
			ma = s - f + 1;
		}
		while(f <= n && si == k) {
			if(m[a[f]] == f) {
				m[a[f]] = 0;
				si--;
				f++;
				break;
			}
			else
			{
				f++;
			}
		}
	}
	cout << l << " " << r;
}
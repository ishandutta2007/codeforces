#ifdef _MSC_VER
#define _CRT_SECURE_NO_WARNINGS
#endif

#include <bits/stdc++.h>

using namespace std;

int main()
{
#ifdef _MSC_VER
	freopen("d.in", "r", stdin);
#endif
	std::ios::sync_with_stdio(false);
	int t;
	cin >> t;
	while (t--) {
		int n, l, r;
		cin >> n >> l >> r;
		vector<int> a;
		for (int i = 0; i < l; ++i) {
			int x;
			cin >> x;
			a.push_back(x);
		}
		vector<int> b;
		for (int i = 0; i < r; ++i) {
			int x;
			cin >> x;
			b.push_back(x);
		}
		sort(a.begin(), a.end());
		sort(b.begin(), b.end());
		vector<int> c;
		vector<int> d;
		for (int i = 0, j = 0; i < a.size() || j < b.size(); ) {
			if (i < a.size() && j < b.size() && a[i] == b[j]) {
				++i;
				++j;
			}
			else if (j >= b.size() || i < a.size() && a[i] < b[j]) {
				c.push_back(a[i]);
				++i;
			}
			else {
				d.push_back(b[j]);
				++j;
			}
		}
		if (c.size() > d.size()) {
			c.swap(d);
		}
		int count = 0;
		for (int i = 0; i + 1 < d.size(); ++i) {
			if (d[i] == d[i + 1]) {
				++count;
				++i;
			}
		}
		int ret = c.size();
		l = d.size() - c.size();
		r = min(l / 2, count);
		ret += r;
		l -= r * 2;
		ret += l;
		printf("%d\n", ret);
	}
	return 0;
}
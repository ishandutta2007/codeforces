#ifdef _MSC_VER
#define _CRT_SECURE_NO_WARNINGS
#endif

#include <bits/stdc++.h>

using namespace std;

using ll = long long;

int main()
{
	std::ios::sync_with_stdio(false);
	string a;
	cin >> a;
	int n = a.size();

	int m = max(1, (int)sqrt(n) / 2);
	ll results = 0;

	vector<int> count(n * m * 2 + 16);
	for (int x = 1; x <= m; ++x) {
		vector<int> d(n);
		int s = n * m;
		for (int i = 0; i < n; ++i) {
			d[i] = s;
			++count[s];
			s += (a[i] == '1' ? -(x - 1) : 1);
			results += count[s];
		}
		for (int i = 0; i < n; ++i) {
			count[d[i]] = 0;
		}
	}

	vector<int> p;
	for (int i = 0; i < n; ++i) {
		if (a[i] == '1') {
			p.push_back(i);
		}
	}
	int n1 = p.size();
	p.push_back(n);
	for (int start_j = 0, i = 0; i < n; ++i) {
		int cnt = 0;
		for (; p[start_j] < i; ++start_j);
		for (int j = start_j; j < n1; ++j) {
			++cnt;
			if (n / cnt <= m) {
				break;
			}
			int L = p[j] - i + 1;
			int H = p[j + 1] - i;
			L = max(L, (m + 1) * cnt);
			if (L <= H) {
				results += H / cnt - (L - 1) / cnt;
			}
		}
	}
	cout << results << endl;
	return 0;
}
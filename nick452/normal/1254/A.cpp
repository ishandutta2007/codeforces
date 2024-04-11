#include <bits/stdc++.h>

using namespace std;

int main()
{
#ifdef _MSC_VER
	FILE *file_stream;
	freopen_s(&file_stream, "a.in", "r", stdin);
#endif
	std::ios::sync_with_stdio(false);
	int n_cases;
	cin >> n_cases;
	for (int case_n = 0; case_n < n_cases; ++case_n) {
		int n, m, k;
		cin >> n >> m >> k;
		vector<string> a(n);
		for (int x = 0; x < n; ++x) {
			cin >> a[x];
		}
		int total = 0;
		for (int x = 0; x < n; ++x) {
			for (int y = 0; y < m; ++y) {
				if (a[x][y] == 'R') {
					++total;
				}
			}
		}
		int x0 = 0, y0 = -1;
		for (int i = 0; i < k; ++i) {
			char digit;
			if (i < 10) {
				digit = (char)('0' + i);
			} else if (i - 10 < 26) {
				digit = (char)('A' + i - 10);
			} else {
				digit = (char)('a' + i - 10 - 26);
			}
			int cnt = total / (k - i);
			total -= cnt;
			while (1) {
				if (x0 % 2 == 1) {
					if (y0 <= 0) {
						++x0;
					} else {
						--y0;
					}
				} else {
					if (y0 >= m - 1) {
						++x0;
					} else {
						++y0;
					}
				}
				if (x0 >= n) {
					break;
				}
				if (a[x0][y0] == 'R') {
					--cnt;
				}
				a[x0][y0] = digit;
				if (total > 0 && cnt == 0) {
					break;
				}
			}
		}
		for (int x = 0; x < n; ++x) {
			cout << a[x] << endl;
		}
	}
	return 0;
}
#ifdef _MSC_VER
#define _CRT_SECURE_NO_WARNINGS
#endif

#include <bits/stdc++.h>

using namespace std;

int main()
{
#ifdef _MSC_VER
	freopen("c.in", "r", stdin);
#endif
	std::ios::sync_with_stdio(false);
	int n;
	cin >> n;
	vector<int> x;
	vector<int> y;
	for (int i = 0; i < n; i++) {
		string s;
		cin >> s;
		int a = 0;
		int b = 0;
		for (char c : s) {
			if (c == 'B') {
				++a;
			}
			else {
				++b;
			}
		}
		x.push_back(a);
		y.push_back(b);
	}
	int low = -1;
	int high = 2000000;
	int cx = 1;
	int cy = 1;
	while (high - low > 1) {
		int d = low + (high - low) / 2;
		int min_x = 0;
		int max_x = 2000000;
		int min_y = 0;
		int max_y = 2000000;
		int min_d_x_y = -2000000;
		int max_d_x_y = 2000000;

		for (int i = 0; i < n; i++) {
			min_x = max(min_x, x[i] - d);
			max_x = min(max_x, x[i] + d);
			min_y = max(min_y, y[i] - d);
			max_y = min(max_y, y[i] + d);
			min_d_x_y = max(min_d_x_y, x[i] - y[i] - d);
			max_d_x_y = min(max_d_x_y, x[i] - y[i] + d);
		}
		int valid = 0;
		for (int x0 = min_x; x0 <= max_x; ++x0) {
			int next_min_y = min_y;
			int next_max_y = max_y;
			if (x0 == 0) {
				next_min_y = max(next_min_y, 1);
			}
			next_min_y = max(next_min_y, x0 - max_d_x_y);
			next_max_y = min(next_max_y, x0 - min_d_x_y);
			if (next_min_y <= next_max_y) {
				valid = 1;
				cx = x0;
				cy = next_max_y;
			}
		}
		if (valid) {
			high = d;
		}
		else {
			low = d;
		}
	}
	printf("%d\n", high);
	for (int i = 0; i < cx; ++i) {
		printf("B");
	}
	for (int i = 0; i < cy; ++i) {
		printf("N");
	}
	return 0;
}
#include <bits/stdc++.h>
#define pb emplace_back
#define mp make_pair

using namespace std;
int cn = 0;
int to;

void pri(int x, int y) {
	cout << x + 1 << " " << y + 1 << "\n";
	cn++;
	if (cn == to) {
		exit(0);
	}
}

int32_t main()
{
	ios::sync_with_stdio(false); cin.tie(NULL); cout.precision(10);
	int n, m;
	cin >> n >> m;
	int x1 = 1, y1 = 1, x2 = n, y2 = m;
	to = n * m;
	for (int j = 0; j < m; ++j) {
		for (int i = 0; i < n; ++i) {
			if (j & 1) {
				pri(n - i - 1, j);
				pri(i, m - j - 1);
			} else {
				pri(i, j);
				pri(n - i - 1, m - j - 1);
			}
		}
	}
}
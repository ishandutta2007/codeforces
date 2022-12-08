#include <bits/stdc++.h>
#define err(...) fprintf(stderr, __VA_ARGS__), fflush(stderr)
typedef long long ll;

using namespace std;

const int dd = (int)200 + 7;

string A[dd];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	int n, m;
	cin >> n >> m;
	for (int i = 0; i < n; ++i) {
		cin >> A[i];
	}
	int i1, j1, i2, j2;
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < m; ++j) if (A[i][j] == 'B') {
			i2 = i, j2 = j;
		}
	}

	for (int i = n - 1; i >= 0; --i) {
		for (int j = m - 1; j >= 0; --j) if (A[i][j] == 'B') {
			i1 = i, j1 = j;
		}
	}

	cout << (i1 + i2) / 2 + 1 << " " << (j1 + j2) / 2 + 1 << "\n";
	return 0;
}
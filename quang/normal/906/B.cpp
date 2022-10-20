#include <bits/stdc++.h>

using namespace std;


int n, m;
vector<vector<int> > a, b;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cin >> n >> m;
	int f = n > m;
	if (n > m) swap(n, m);
	a.resize(n, vector<int>(m, 0));
	if (f) {
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				a[i][j] = j * n + i + 1;
			}
		}
	} else {
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				a[i][j] = i * m + j + 1;
			}
		}
	}
	b.resize(n, vector<int>(m, 0));
	if (n == 1) {
		if (m == 1) {
			puts("YES");
			printf("1\n");
			return 0;
		}
		if (m <= 3) {
			puts("NO");
			return 0;
		}
		puts("YES");
		for (int i = 2; i <= m; i += 2) {
			printf("%d ", i);
		}
		for (int i = 1; i <= m; i += 2) {
			printf("%d ", i);
		}
		return 0;
	}
	if (n == 2) {
		if (m <= 3) {
			puts("NO");
			return 0;
		}
	}
	int cur = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			b[(i + j) % n][j] = a[i][(cur + j) % m]; 
		}
		cur = (cur + 2) % m;
	}
	puts("YES");
	if (!f)
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			printf("%d ", b[i][j]);
		}
		printf("\n");
	}
	else 
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			printf("%d ", b[j][i]);
		}
		printf("\n");
	}
	return 0;
}
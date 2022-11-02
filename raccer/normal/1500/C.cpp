#include <bits/stdc++.h>
using namespace std;

int a[1510][1510], b[1510][1510];
int id[1510], cnt[1510], alive[1510];
map <vector <int>, vector <int> > all;
vector <int> ord;

int main() {
	int n, m; scanf("%d%d", &n, &m);
	for (int i = 0; i < n; i++) for (int j = 0; j < m; j++) scanf("%d", &a[i][j]);
	for (int i = 0; i < n; i++) for (int j = 0; j < m; j++) scanf("%d", &b[i][j]);
	for (int i = 0; i < n; i++) {
		vector <int> tmp; for (int j = 0; j < m; j++) tmp.push_back(a[i][j]);
		all[tmp].push_back(i);
	}
	for (int i = n - 1; i >= 0; i--) {
		vector <int> tmp; for (int j = 0; j < m; j++) tmp.push_back(b[i][j]);
		if (!all[tmp].size()) {
			printf("-1\n");
			return 0;
		}
		b[i][m] = all[tmp].back(), all[tmp].pop_back();
	}
	m++;
	for (int j = 0; j < m; j++) for (int i = 1; i < n; i++) cnt[j] += b[i - 1][j] > b[i][j];
	for (int j = 0; j < m; j++) if (!cnt[j]) ord.push_back(j);
	for (int it = 0; it < ord.size(); it++) {
		int x = ord[it];
		for (int i = 1; i < n; i++) {
			if (b[i - 1][x] < b[i][x] && !alive[i]) {
				alive[i] = 1;
				for (int j = 0; j < m; j++) {
					cnt[j] -= b[i - 1][j] > b[i][j];
					if (!cnt[j] && b[i - 1][j] > b[i][j]) ord.push_back(j);
				}
			}
		}
	}
	if (cnt[m - 1]) {
		printf("-1\n");
		return 0;
	}
	for (int i = 0; i < ord.size(); i++) {
		if (ord[i] == m - 1) {
			printf("%d\n", i);
			for (int j = i - 1; j >= 0; j--) {
				printf("%d ", ord[j] + 1);
			}
			printf("\n");
			return 0;
		}
	}
	return 0;
}
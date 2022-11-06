#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn = 1e5;
int T, x, y;
vector<int> a, b;
bool f[31][31], g[31][31];


int main() {
	scanf("%d", &T);
	while (T--) {
		a.clear(); b.clear();
		a.push_back(0); b.push_back(0);
		scanf("%d%d", &x, &y);
		for (int i = 0; i <= 30; ++i) {
			if (x >> i & 1) a.push_back(i);
			if (y >> i & 1) b.push_back(i);
		}
		int n = (int)a.size() - 1, m = (int)b.size() - 1;
		for (int i = 0; i <= 30; ++i)
			for (int j = 0; j <= 30; ++j) {
				f[i][j] = g[i][j] = 0;
			}
		f[0][0] = g[0][0] = 1;
		for (int i = 1; i <= n; ++i) g[0][i] = 1;
		for (int i = 1; i <= m; ++i)
			for (int j = 1; j <= n; ++j) {
				if (b[i] >= a[j]) {
					if (b[i] == a[j]) f[i][j] = f[i - 1][j - 1];
					else f[i][j] = g[i - 1][j - 1];
				}
				g[i][j] = g[i][j - 1] | f[i][j];
			}
		printf("%s\n", f[m][n] ? "YES" : "NO");
	}
}
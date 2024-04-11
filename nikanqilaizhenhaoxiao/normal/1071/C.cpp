#include <bits/stdc++.h>

#ifdef __WIN32
#define LLFORMAT "I64"
#else
#define LLFORMAT "ll"
#endif

using namespace std;

const int maxn = 1e5 + 10, maxs = (1 << 15) | 10;

int n, a[maxn], d[maxs], q[maxs], fnt, rar, rem[maxs];
vector<vector<int> > ans;;

int main() {
	scanf("%d", &n);
	for (int i = 1; i <= n; ++i) scanf("%d", a + i);
	while(n > 12) {
		if(a[n]) {
			if(a[n - 1] == 0 && a[n - 2] == 0) {
				ans.push_back({n - 6, n - 3, n});
				a[n] ^= 1;
				a[n - 3] ^= 1;
				a[n - 6] ^= 1;
			}
			else if(a[n - 1] == 0 && a[n - 2] == 1) {
				ans.push_back({n - 4, n - 2, n});
				a[n] ^= 1;
				a[n - 2] ^= 1;
				a[n - 4] ^= 1;
			}
			else if(a[n - 1] == 1 && a[n - 2] == 0) {
				vector<int> b;
				for (int i = 3; i < 6; ++i) if(a[n - i] == 1) b.push_back(i);
				if(b.size() == 3) {
					ans.push_back({n - 5, n - 3, n - 1});
					a[n - 1] ^= 1;
					a[n - 3] ^= 1;
					a[n - 5] ^= 1;
					ans.push_back({n, n - 4, n - 8});
					a[n] ^= 1;
					a[n - 4] ^= 1;
					a[n - 8] ^= 1;
				}
				else if(b.size() == 2) {
					for (int i = 0; i < 2; ++i) {
						int x = n - i, y = n - b[i];
						ans.push_back({x, y, y * 2 - x});
						a[x] ^= 1;
						a[y] ^= 1;
						a[y * 2 - x] ^= 1;
					}
				}
				else if(b.size() == 1) {
					int x = n, y = n - b[0];
					ans.push_back({x, y, y * 2 - x});
					a[x] ^= 1;
					a[y] ^= 1;
					a[y * 2 - x] ^= 1;
				}
				else {
					ans.push_back({n - 2, n - 1, n});
				a[n] ^= 1;
				a[n - 1] ^= 1;
				a[n - 2] ^= 1;
				}
			}
			else {
				ans.push_back({n - 2, n - 1, n});
				a[n] ^= 1;
				a[n - 1] ^= 1;
				a[n - 2] ^= 1;
			}
		}
		--n;
	}
	memset(d, -1, sizeof d);
	int s = 0;
	for (int i = 0; i < n; ++i) if(a[i + 1]) s |= (1 << i);
	q[rar++] = s; d[s] = 0;
	vector<int> all;
	for (int i = 0; i < n; ++i) for (int d = 1; i - d >= 0 && i + d < n; ++d) all.push_back((1 << i - d) | (1 << i) | (1 << i + d));
	while(fnt != rar) {
		int u = q[fnt++];
		for (auto t: all) {
			int v = t ^ u;
			if(!~d[v]) d[v] = d[u] + 1, rem[v] = u, q[rar++] = v;
		}
	}
	if(!~d[0]) { puts("NO"); return 0; }
	puts("YES");
	for (int u = 0; u != s; u = rem[u]) {
		int v = rem[u];
		int t = u ^ v;
		vector<int> fuck;
		for (int i = 0; i < n; ++i) if((t >> i) & 1) fuck.push_back(i + 1);
		ans.push_back(fuck);
	}
	printf("%d\n", ans.size());
	for (auto t: ans) printf("%d %d %d\n", t[0], t[1], t[2]);
	return 0;
}
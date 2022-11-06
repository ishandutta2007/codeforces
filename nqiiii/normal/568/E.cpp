#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e5;
int n, m, a[maxn + 10], b[maxn + 10], ans;
int d[maxn + 10], f[maxn + 10], w[maxn + 10];
int v, pos;
bool mk[maxn + 10];
vector<int> g[maxn + 10];
multiset<int> st;
int main() {
	scanf("%d", &n);
	for (int i = 1; i <= n; ++i)
		scanf("%d", &a[i]);
	scanf("%d", &m);
	for (int i = 1; i <= m; ++i) {
		scanf("%d", &b[i]); st.insert(b[i]);
	}	
	sort(b + 1, b + m + 1);
	memset(d, 0x3f, sizeof d); d[0] = 0;
	for (int i = 1; i <= n; ++i)
		if (a[i] == -1) {
			for (int j = 1, p = 1; j <= m; ++j) {
				while (d[p] < b[j]) ++p;
				w[j] = p; ans = max(ans, p);
			}
			for (int j = 1; j <= m; ++j)
				d[w[j]] = min(d[w[j]], b[j]);
		} else {
			int v = lower_bound(d + 1, d + n + 1, a[i]) - d;
			f[i] = v; d[v] = a[i];
			ans = max(ans, v);
			g[v].push_back(i);
		}
	v = 2e9; pos = n + 1;
	while (ans) {
		while (!g[ans].empty() && g[ans].back() >= pos) g[ans].pop_back();
		if (g[ans].empty() || a[g[ans].back()] >= v) {
			--pos;
			while (a[pos] != -1) --pos;
			auto it = --st.lower_bound(v);
			a[pos] = v = *it; st.erase(it);
		} else {
			pos = g[ans].back(); v = a[pos];
		}
		--ans;
	}
	for (int i = 1; i <= n; ++i) {
		if (a[i] == -1) {
			a[i] = *st.begin(); st.erase(st.begin());
		}
		printf("%d ", a[i]);
	}
}
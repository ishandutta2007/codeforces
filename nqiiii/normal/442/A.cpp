#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn = 1e5;

int n, a[maxn + 10], b[maxn + 10], cnt1[maxn + 10], cnt2[maxn + 10];
int w1, w2, cnt3[5 + 10][5 + 10], ans = 1e9;
int va[5 + 10], vb[5 + 10];

int id(char c) {
	return c == 'R' ? 0 : c == 'G' ? 1 : c == 'B' ? 2 : c == 'Y' ? 3 : 4;
}

void dfs1(int p);
void dfs2(int p);

void dfs1(int p) {
	if (va[p]) return;
	va[p] = 1;
	int cnt = 0;
	for (int i = 0; i < 5; ++i)
		if (cnt3[p][i] && !vb[i]) ++cnt;
	if (cnt == 1) {
		for (int i = 0; i < 5; ++i)
			if (cnt3[p][i] && !vb[i]) dfs2(i);
	}
}

void dfs2(int p) {
	if (vb[p]) return;
	int cnt = 0;
	for (int i = 0; i < 5; ++i)
		if (cnt3[i][p] && !va[i]) ++cnt;
	if (cnt == 1) {
		vb[p] = 1;
		for (int i = 0; i < 5; ++i)
			if (cnt3[i][p] && !va[i]) dfs1(i);
	}
}

int main() {
	scanf("%d", &n);
	for (int i = 1; i <= n; ++i) {
		char s[10]; scanf("%s", s);
		a[i] = id(s[0]);
		b[i] = s[1] - '1';
		cnt3[a[i]][b[i]] = 1;
	}
	for (int i = 0; i < 5; ++i)
		for (int j = 0; j < 5; ++j)
			if (cnt3[i][j]) {
				++cnt1[i]; ++cnt2[j];
			}
	for (int i = 0; i < 1 << 5; ++i)
		for (int j = 0; j < 1 << 5; ++j) {
			memset(va, 0, sizeof va);
			memset(vb, 0, sizeof vb);
			int left = 0;
			for (int k = 0; k < 5; ++k)
				for (int l = 0; l < 5; ++l)
					if (cnt3[k][l]) {
						if ((i >> k & 1) && (j >> l & 1)) {
							++va[k]; ++vb[l];
							
						} else if (i >> k & 1) ++vb[l];
						else if (j >> l & 1) ++va[k];
						else ++left;
					}
			bool fd = 0;
			for (int i = 0; i < 5; ++i) {
				if (va[i] + 1 < cnt1[i]) fd = 1;
				if (vb[i] + 1 < cnt2[i]) fd = 1;
			}
			if (left > 1) fd = 1;
			if (!fd) {
				int tot = 0;
				for (int k = 0; k < 5; ++k) {
					tot += i >> k & 1;
					tot += j >> k & 1;
				}
				ans = min(ans, tot);
			}
		}
	printf("%d", ans);
}
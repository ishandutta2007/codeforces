#include <stdio.h>
#include <bits/stdc++.h>

using namespace std;

const int N = 1e6 + 10, M = (1 << 21);

int first[N + M], cur = 1;
struct Edge {
	int nxt, to;
}	e[(N) << 1];
int f[(N) << 1];
void con(int x, int y) {
	e[++cur] = (Edge){first[x], y};
	first[x] = cur;
}

int n, a[N], b[N], d[M];
int s1[(N + M) << 1], s2[(N + M) << 1], top1, top2;
int s3[(N + M) << 1], top3;

int main() {
	scanf("%d", &n);
	for (int i = 1; i <= n; i++)
		scanf("%d%d", &a[i], &b[i]);
	for (int o = 20; o >= 1; o--) {
		int s = (1 << o), up = s - 1;
		for (int j = 0; j < s; j++) d[j] = 0;
		for (int j = 1; j <= n; j++)
			d[a[j] & up]++, d[b[j] & up]++;
		int flag = 1;
		for (int i = 0; i < s; i++) if (d[i] & 1) {
			flag = 0;
			break;
		}
		if (flag == 0) continue;
		for (int i = 1; i <= n + 1 + 1 + s; i++) first[i] = 0;
		for (int i = 2; i <= cur; i++) f[i] = 0; cur = 1;
		for (int i = 1; i <= n; i++) {
			int tmp = n + 1 + (a[i] & up);
			con(i, tmp), con(tmp, i);
			tmp = n + 1 + (b[i] & up);
			con(i, tmp), con(tmp, i);
		}
		top1 = top2 = 0;
		s1[++top1] = 1;
		while (top1) {
			int &i = first[s1[top1]];
			while (f[i]) i = e[i].nxt;
			if (!i) s2[++top2] = s1[top1], top1--;
			else f[i] = f[i ^ 1] = 1, s1[++top1] = e[i].to, i = e[i].nxt;
		}
		int lst = 0, cnt = 0;
		for (int i = 1; i <= top2; i++)
			if (s2[i] <= n) cnt++;
		if (cnt != n + 1) continue;
		while (top2) {
			int t = s2[top2--];
			s3[++top3] = t;
		}
		printf("%d\n", o);
		top3--;
		while (top3) {
			int t = s3[top3--];
			if (t > n) {
				lst = t - n - 1;
				continue;
			}
			if ((a[t] & up) == lst) printf("%d %d ", 2 * t - 1, 2 * t);
			else printf("%d %d ", 2 * t, 2 * t - 1);
		}
		puts("");
		return 0;
	}
	puts("0");
	for (int i = 1; i <= 2 * n; i++)
		printf("%d ", i);
	puts("");
	return 0;
}
#include <bits/stdc++.h>
using namespace std;

char s[200010], t[200010];
int L[200010], R[200010];

struct Segment_tree {
	int T[800010], lazy[800010];
	void Build(int now, int l, int r) {
		lazy[now] = -1;
		if (l == r) {
			T[now] = t[l] - '0';
			return ;
		}
		int mid = l + r >> 1;
		Build(now << 1, l, mid), Build(now << 1 | 1, mid + 1, r);
		T[now] = T[now << 1] + T[now << 1 | 1];
	}
	void pushdown(int now, int l, int r) {
		if (lazy[now] == -1) return ;
		int mid = l + r >> 1, c = lazy[now]; lazy[now] = -1;
		T[now << 1] = c * (mid - l + 1), lazy[now << 1] = c;
		T[now << 1 | 1] = c * (r - mid), lazy[now << 1 | 1] = c;
	}
	int Query(int now, int l, int r, int L, int R) {
		if (l == L && r == R) return T[now];
		pushdown(now, l, r);
		int mid = l + r >> 1;
		if (R <= mid) return Query(now << 1, l, mid, L, R);
		if (L > mid) return Query(now << 1 | 1, mid + 1, r, L, R);
		return Query(now << 1, l, mid, L, mid) + Query(now << 1 | 1, mid + 1, r, mid + 1, R);
	}
	void Update(int now, int l, int r, int L, int R, int c) {
		if (l == L && r == R) {
			T[now] = c * (r - l + 1), lazy[now] = c;
			return ;
		}
		pushdown(now, l, r);
		int mid = l + r >> 1;
		if (R <= mid) Update(now << 1, l, mid, L, R, c);
		else if (L > mid) Update(now << 1 | 1, mid + 1, r, L, R, c);
		else Update(now << 1, l, mid, L, mid, c), Update(now << 1 | 1, mid + 1, r, mid + 1, R, c);
		T[now] = T[now << 1] + T[now << 1 | 1];
	}
	bool check(int now, int l, int r) {
		if (l == r) return T[now] == s[l] - '0';
		pushdown(now, l, r);
		int mid = l + r >> 1;
		return check(now << 1, l, mid) && check(now << 1 | 1, mid + 1, r);
	}
}seg;

int main () {
	int T; scanf("%d", &T);
	while (T--) {
		int n, q; scanf("%d%d", &n, &q);
		scanf("%s%s", s + 1, t + 1);
		seg.Build(1, 1, n);
		for (int i = 0; i < q; i++) {
			scanf("%d%d", &L[i], &R[i]);
		}
		int flag = 1;
		for (int i = q - 1; i >= 0; i--) {
			int l = L[i], r = R[i];
			int cnt = seg.Query(1, 1, n, l, r);
			int minj = min(cnt, r - l + 1 - cnt);
			if (minj * 2 == r - l + 1) {
				flag = 0;
				break;
			}
			if (minj == cnt) seg.Update(1, 1, n, l, r, 0);
			else seg.Update(1, 1, n, l, r, 1);
		}
		if (flag && seg.check(1, 1, n)) printf("YES\n");
		else printf("NO\n");
	}
	return 0;
}
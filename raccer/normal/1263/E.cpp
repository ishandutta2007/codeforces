#include <bits/stdc++.h>
using namespace std;

const int N = 1000010;

struct Segment_Tree {
	int sum[4000010], minj[4000010], maxj[4000010];
	void Build() {
		memset(sum, 0, sizeof(sum)), memset(minj, 0, sizeof(minj)), memset(maxj, 0, sizeof(maxj));
	}
	void pushup(int now) {
		sum[now] = sum[now << 1] + sum[now << 1 | 1];
		minj[now] = min(minj[now << 1], minj[now << 1 | 1] + sum[now << 1]);
		maxj[now] = max(maxj[now << 1], maxj[now << 1 | 1] + sum[now << 1]);
	}
	void Update(int now, int l, int r, int pos, int x) {
		if (l == r) {
			sum[now] = x;
			minj[now] = min(x, 0);
			maxj[now] = max(x, 0);
			return ;
		}
		int mid = l + r >> 1;
		if (pos <= mid) Update(now << 1, l, mid, pos, x);
		else Update(now << 1 | 1, mid + 1, r, pos, x);
		pushup(now);
	}
}seg;

char s[1000010];

int main () {
	int n; scanf("%d", &n);
	scanf("%s", s);
	seg.Build();
	int cur = 1;
	for (int i = 0; i < n; i++) {
		if (s[i] == 'R') cur++;
		else if (s[i] == 'L') cur = max(cur - 1, 1);
		else seg.Update(1, 1, N, cur, s[i] == '(' ? 1 : s[i] == ')' ? -1 : 0);
		if (seg.minj[1] < 0 || seg.sum[1] != 0) printf("-1 ");
		else printf("%d ", seg.maxj[1]);
	}
	printf("\n");
	return 0;
}
#include <cstdio>
#include <algorithm>

typedef long long LL;
const int MN = 300005, MS = 1 << 20 | 7;

int N, arr[MN], pos[MN];
#define li (i << 1)
#define ri (li | 1)
#define mid ((l + r) >> 1)
#define ls li, l, mid
#define rs ri, mid + 1, r
int val[MS], num[MS], tg[MS];
inline void P(int i, int x) { val[i] += x, tg[i] += x; }
inline void pd(int i) { if (tg[i]) P(li, tg[i]), P(ri, tg[i]), tg[i] = 0; }
void Build(int i, int l, int r) {
	val[i] = N, num[i] = r - l + 1;
	if (l == r) return ;
	Build(ls), Build(rs);
}
void Add(int i, int l, int r, int a, int b, int x) {
	if (r < a || b < l) return ;
	if (a <= l && r <= b) return P(i, x);
	pd(i), Add(ls, a, b, x), Add(rs, a, b, x);
	val[i] = std::min(val[li], val[ri]), num[i] = 0;
	if (val[i] == val[li]) num[i] += num[li];
	if (val[i] == val[ri]) num[i] += num[ri];
}
LL Ans;

int main() {
	scanf("%d", &N);
	for (int i = 1, x, y; i <= N; ++i)
		scanf("%d%d", &x, &y), pos[y] = x;
	Build(1, 1, N);
	for (int i = 1; i <= N; ++i) {
		int p = pos[i];
		arr[p] = i;
		Add(1, 1, N, i, i, -N);
		Add(1, 1, N, 1, i, 1);
		if (arr[p - 1]) Add(1, 1, N, 1, arr[p - 1], -1);
		if (arr[p + 1]) Add(1, 1, N, 1, arr[p + 1], -1);
		Ans += num[1];
	}
	printf("%lld\n", Ans);
	return 0;
}
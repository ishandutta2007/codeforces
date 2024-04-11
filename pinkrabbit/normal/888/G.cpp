#include <cstdio>
#include <algorithm>

#define INF 0x3f3f3f3f

const int MN = 200005;
const int MM = 6000005;

int N;
int a[MN];

int c[MM][2], val[MM], bit[MM], siz[MM], ed[MM], cnt;

void Add(int x) {
	int now = 0;
	for (int j = 29; ~j; --j) {
		if (!c[now][x >> j & 1]) {
			c[now][x >> j & 1] = ++cnt;
			val[cnt] = val[now] ^ (x & 1 << j);
			bit[cnt] = j;
		}
		now = c[now][x >> j & 1];
		++siz[now];
	} ed[now] = 1;
}

int stk[MN], tp;
void Extract(int now) {
	if (ed[now]) { stk[++tp] = val[now]; return ; }
	if (c[now][0]) Extract(c[now][0]);
	if (c[now][1]) Extract(c[now][1]);
}

int GetMin(int now, int x) {
	if (ed[now]) return x ^ val[now];
	int dir = x >> (bit[now] - 1) & 1;
	if (c[now][dir]) return GetMin(c[now][dir], x);
	else return GetMin(c[now][dir ^ 1], x);
}

long long DFS(int now) {
	if (ed[now]) return 0ll;
	long long Ans = 0ll;
	if (c[now][0] && c[now][1]) {
		int t1 = c[now][0], t2 = c[now][1], mn = INF;
		if (siz[t1] > siz[t2]) std::swap(t1, t2);
		tp = 0, Extract(t1);
		for (; tp; --tp) mn = std::min(mn, GetMin(t2, stk[tp]));
		Ans += mn;
	}
	if (c[now][0]) Ans += DFS(c[now][0]);
	if (c[now][1]) Ans += DFS(c[now][1]);
	return Ans;
}

int main() {
	scanf("%d", &N);
/*	Add(0);
	for (int i = 1; i <= N; ++i) {
		scanf("%d", &a[i]), a[i] ^= a[i - 1];
		Add(a[i]);
	}*/
	for (int i = 1; i <= N; ++i)
		scanf("%d", &a[i]), Add(a[i]);
	printf("%lld\n", DFS(0));
	return 0;
}
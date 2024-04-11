#include <stdio.h>
#include <bits/stdc++.h>

using namespace std;

const int N = 5e4 + 10;

int n, p, a[N], pos[N], cnt[N];
int pw[20 * N];

struct Node {
	int num, cnt;
};

inline void Merge(Node &ret, Node &x, Node &y) {
	ret.cnt = x.cnt + y.cnt;
	ret.num = (1ll * x.num * pw[y.cnt] + y.num) % p;
}

Node o[N << 2];
int s, typ, b[N], f[N], B = 0;
int vec[N], cv;

int st[100], top = 0;

inline void Mdf(int x, int l, int r) {
	top = 0; st[++top] = x;
	while (l != r) {
		int mid = (l + r) >> 1;
		if (s <= mid) {
			x = x << 1;
			st[++top] = x;
			r = mid;
		}
		else {
			x = x << 1 | 1;
			st[++top] = x;
			l = mid + 1;
		}
	}
	if (typ) o[st[top]] = (Node){a[s], cnt[a[s]]};
	else o[st[top]] = (Node){0, 0}; top--;
	while (top) Merge(o[st[top]], o[st[top] << 1], o[st[top] << 1 | 1]), top--;
}

inline void Add(int t1, int t2) {
	s = t1, typ = t2;
	Mdf(1, 1, n);
}

inline int Range(int x, int y) {
	return rand() % (y - x + 1) + x;
}

vector <int> out;

inline void check(int x) {
	int temp = x;
	for (int i = B; i >= 0; i--)
		if ((temp >> i) & 1)
			Add(pos[b[i]], 1), temp ^= b[i];
	if (o[1].num == 0) {
		puts("Yes");
		temp = x;
		for (int i = B; i >= 0; i--)
			if ((temp >> i) & 1)
				temp ^= b[i], out.push_back(pos[b[i]]);
		sort (out.begin(), out.end());
		printf("%d\n", (int)out.size());
		int tt = 0, ttt = 0;
		for (int x : out) ttt ^= a[x];
		for (int x : out) tt = (1ll * tt * pw[cnt[a[x]]] + a[x]) % p;
		assert(tt == 0 && ttt == 0);
		for (int x : out) printf("%d ", x); puts("");
		exit(0);
	}
	temp = x;
	for (int i = B; i >= 0; i--)
		if ((temp >> i) & 1)
			Add(pos[b[i]], 0), temp ^= b[i];
}

int main() {
	srand(98914060);
	scanf("%d%d", &n, &p);
	for (int i = 1; i <= n; i++)
		scanf("%d", &a[i]), pos[a[i]] = i;
	if (n <= 2) return 0 * puts("No");
	pw[0] = 1;
	for (int i = 1; i <= 20 * n; i++)
		pw[i] = pw[i - 1] * 10 % p;
	for (int i = 1; i <= n; i++) {
		int tmp = i;
		while (tmp) cnt[i]++, tmp /= 10;
	}
	while (n >> (B + 1)) B++;
	for (int T = 1; T <= 200000 / n; T++) {
		for (int i = 0; i <= B; i++) {
			b[i] = Range(1 << i, min((1 << (i + 1)) - 1, n));
			f[b[i]] = 1;
		}
		cv = 0;
		for (int i = 1; i <= n; i++) if (!f[i]) vec[++cv] = i;
		random_shuffle(vec + 1, vec + cv + 1);
		int fuk = 0;
		for (int i = 1; i <= cv; i++) {
			fuk ^= vec[i];
			out.push_back(pos[vec[i]]);
			Add(pos[vec[i]], 1);
			check(fuk);
		}
		while (out.size()) out.pop_back();
		for (int i = 1; i <= cv; i++)
			Add(pos[vec[i]], 0);
		for (int i = 0; i <= B; i++) f[b[i]] = 0;
	}
	puts("No");
	return 0;
}
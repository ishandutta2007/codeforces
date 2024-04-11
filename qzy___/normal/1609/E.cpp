#include <stdio.h>
#include <bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define pii pair<int,int>
#define pll pair<ll,ll>
#define puu pair<ull,ull>
#define fi first
#define se second
#define inf 0x3f3f3f3f
#define infll 0x3f3f3f3f3f3f3f3f
#define mset(a, b) memset(a, b, sizeof a)
#define lep(i, j, k) for (int i = (j); i <= (k); i++)
#define rep(i, j, k) for (int i = (j); i >= (k); i--)
#define Lep(i, j, k) for (int i = (j); i < (k); i++)
#define Rep(i, j, k) for (int i = (j); i > (k); i--)

using namespace std;

typedef long long ll;
typedef unsigned long long ull;

template <typename T>
void ckmin(T &A, T B) {A = A < B ? A : B;}
template <typename T>
void ckmax(T &A, T B) {A = A > B ? A : B;}

inline void read(int &x) {scanf("%d", &x);}
inline void print(int x) {printf("%d", x);}
inline void print(int x, char c) {printf("%d%c", x, c);}
inline void read(long long &x) {scanf("%lld", &x);}
inline void print(long long x) {printf("%lld", x);}
inline void print(long long x, char c) {printf("%lld%c", x, c);}

const int N = 1e5 + 10;

struct Node {
	int mn, s1, s2, l[4];
}	o[N << 2];

void PushUp(int x) {
	o[x].mn = min(o[x << 1].s1 + o[x << 1 | 1].s2, min(o[x << 1].mn, o[x << 1 | 1].mn));
	o[x].s1 = min(o[x << 1].s1, o[x << 1 | 1].s1);
	o[x].s2 = min(o[x << 1].s2, o[x << 1 | 1].s2);
}

void Upd(int x, int c, int d) {
	if (c == 1) o[x].s1 += d, o[x].mn += d, o[x].l[1] += d;
	if (c == 2) o[x].s1 -= d, o[x].s2 += d, o[x].l[2] += d;
	if (c == 3) o[x].s2 -= d, o[x].mn -= d, o[x].l[3] += d;
}

void PushDown(int x) {
	for (int i = 1; i <= 3; i++)
		if (o[x].l[i] != 0) {
			Upd(x << 1, i, o[x].l[i]);
			Upd(x << 1 | 1, i, o[x].l[i]);
			o[x].l[i] = 0;
		}
}

void Mdf(int x, int l, int r, int tl, int tr, int c, int d) {
	if (tl <= l && r <= tr) return Upd(x, c, d);
	PushDown(x); int mid = (l + r) >> 1;
	if (tl <= mid) Mdf(x << 1, l, mid, tl, tr, c, d);
	if (tr > mid) Mdf(x << 1 | 1, mid + 1, r, tl, tr, c, d);
	PushUp(x);
}

int n, q, ct[4];
char s[N];

int main() {
	read(n), read(q);
	scanf("%s", s + 1);
	for (int i = 1; i <= n; i++)
		Mdf(1, 1, n, i, n, s[i] - 'a' + 1, 1), ct[s[i] - 'a' + 1]++;
	for (int i = 1; i <= q; i++) {
		int p; char c; scanf("%d %c", &p, &c);
		Mdf(1, 1, n, p, n, s[p] - 'a' + 1, -1), ct[s[p] - 'a' + 1]--;
		s[p] = c;
		Mdf(1, 1, n, p, n, s[p] - 'a' + 1, 1), ct[s[p] - 'a' + 1]++;
		print(min(ct[3] + o[1].mn, min(ct[3] + o[1].s2, ct[3])), '\n');
	}
	return 0;
}
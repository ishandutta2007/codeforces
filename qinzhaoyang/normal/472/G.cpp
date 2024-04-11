#include <stdio.h>
#include <bits/stdc++.h>
#define il inline

using namespace std;

const int N = 200010, S = 1400;

namespace FFT {
	const double Pi = acos(-1);
	struct cp {
		double x, y;
		cp (double x = 0, double y = 0)
			: x(x), y(y) {}
	};
	il cp operator + (cp A, cp B) {return cp(A.x + B.x, A.y + B.y);}
	il cp operator - (cp A, cp B) {return cp(A.x - B.x, A.y - B.y);}
	il cp operator * (cp A, cp B) {return cp(A.x * B.x - A.y * B.y, A.x * B.y + A.y * B.x);}
	cp a[N << 2]; int lim, l, r[N << 2];
	void fft(cp *a, int type) {
		for (int i = 0; i < lim; i++) if (i < r[i]) swap(a[i], a[r[i]]);
		for (int i = 1; i < lim; i <<= 1) {
			cp t = cp(cos(Pi / i), type * sin(Pi / i));
			for (int j = 0; j < lim; j += (i << 1)) {
				cp o = cp(1, 0);
				for (int k = 0; k < i; k++, o = o * t) {
					cp dx = a[j + k], dy = a[i + j + k] * o;
					a[j + k] = dx + dy, a[i + j + k] = dx - dy;
				}
			}
		}
	}
	void Mul(int n, int m, int *A, int *B, int &len, int *C) {
		lim = 1, l = 0; len = n + m - 1; while (n + m > lim) lim <<= 1, l++;
		for (int i = n; i < lim; i++) A[i] = 0;
		for (int i = m; i < lim; i++) B[i] = 0;
		for (int i = 0; i < lim; i++) r[i] = (r[i >> 1] >> 1) | ((i & 1) << (l - 1));
		for (int i = 0; i < lim; i++) a[i] = cp(A[i] + B[i], A[i] - B[i]);
		fft(a, 1); for (int i = 0; i < lim; i++) a[i] = a[i] * a[i]; fft(a, -1);
		for (int i = 0; i < len; i++) {
			if (a[i].x < 0) C[i] = (int)(a[i].x / (4 * lim) - 0.5);
			else C[i] = (int)(a[i].x / (4 * lim) + 0.5);
		}
	}
};

int la, lb, q, lc;
char sA[N], sB[N];
int a[N << 2], b[N << 2], c[N << 2];
int p[N][N / S + 10], id[N];

struct Block {
	int l, r, c;
}	k[N / S + 10];
int cnt;

int main() {
	scanf("%s%s", sA, sB);
	la = strlen(sA), lb = strlen(sB);
	for (int i = 0; i < lb; i++) {
		if (i % S == 0) ++cnt, k[cnt].l = i, k[cnt].c = 0;
		k[cnt].c++, k[cnt].r = i, id[i] = cnt;
	}
	for (int i = 0; i < la; i++) {
		if (sA[i] == '1') a[i] = 1;
		else a[i] = -1;
	}
	for (int i = 1; i <= cnt; i++) {
		for (int j = k[i].l; j <= k[i].r; j++) {
			if (sB[j] == '1') b[k[i].r - j] = 1;
			else b[k[i].r - j] = -1;
		}
		FFT::Mul(la, k[i].c, a, b, lc, c);
		for (int j = k[i].c - 1; j < lc; j++)
			p[j - k[i].c + 1][i] = (k[i].c - c[j]) / 2;
	}
	for (scanf("%d", &q); q; q--) {
		int x, y, l; scanf("%d%d%d", &x, &y, &l);
		int ed = y + l - 1, ans = 0;
		for (; y <= ed && y % S; x++, y++)
			ans += sA[x] != sB[y];
		for (; y + S - 1 <= ed; x += S, y += S)
			ans += p[x][y / S + 1];
		for (; y <= ed; x++, y++)
			ans += sA[x] != sB[y];
		printf("%d\n", ans);
	}
	return 0;
}
#include <bits/stdc++.h>
#define rep(i, l, r) for(int i = (l); i <= (r); i++)
#define per(i, r, l) for(int i = (r); i >= (l); i--)
#define mem(a, b) memset(a, b, sizeof a)
#define For(i, l, r) for(int i = (l), i##e = (r); i < i##e; i++)
#define pb push_back

using namespace std;

const int N = 1005;

int n, m, K, A[N][N], B[N][N], c[N][N];
char s[N];

int main() {
#ifdef local
	freopen(".in", "r", stdin);
#endif
	cin >> n >> m >> K;
	int ct = 0;
	For(i, 1, n * 2) {
		scanf("%s", s + 1);
		if(i & 1) For(j, 1, m) ct += !(A[(i + 1) / 2][j] = s[j] == 'N');
		else rep(j, 1, m) ct += !(B[i / 2][j] = s[j] == 'N');
	}
	if(K == 1) {
		if(ct * 4 < 3 * (2 * n * m - n - m)) puts("NO"), exit(0);
	} else {
		if(n < m) rep(i, 1, n) {
			ct = 0;
			For(j, 1, m) c[i][j + 1] = c[i][j] ^ A[i][j];
			if(i > 1) rep(j, 1, m) ct += c[i][j] ^ c[i - 1][j] ^ B[i - 1][j];
			if(ct * 2 > m) rep(j, 1, m) c[i][j] ^= 1;
		} else rep(j, 1, m) {
			ct = 0;
			For(i, 1, n) c[i + 1][j] = c[i][j] ^ B[i][j];
			if(j > 1) rep(i, 1, n) ct += c[i][j] ^ c[i][j - 1] ^ A[i][j - 1];
			if(ct * 2 > n) rep(i, 1, n) c[i][j] ^= 1;
		}
	}
	puts("YES");
	rep(i, 1, n) {
		rep(j, 1, m) printf("%d ", c[i][j] + 1);
		puts("");
	}
	return 0;
}
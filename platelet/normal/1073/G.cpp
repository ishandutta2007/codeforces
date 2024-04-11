#include <bits/stdc++.h>
#define rep(i, l, r) for(int i = (l); i <= (r); i++)
#define per(i, r, l) for(int i = (r); i >= (l); i--)
#define mem(a, b) memset(a, b, sizeof a)
#define For(i, l, r) for(int i = (l), i##e = (r); i < i##e; i++)
#define pb push_back

using namespace std;
typedef long long ll;
const int N = 2e5 + 5, K = 500;
int n, q, a, b, A[N], B[N];
char s[N];
int m = 128, sa[N], rk[N], tp[N], buc[N], h[18][N];
int c1[N], c2[N], L[N], R[N];
int lcp(int a, int b) {
	if(a == b) return n - a + 1;
	a = rk[a], b = rk[b];
	if(a > b) swap(a, b);
	int k = 31 - __builtin_clz(b - a);
	return min(h[k][a + 1], h[k][b - (1 << k) + 1]);
}
int main() {
	#ifdef local
		freopen(".in", "r", stdin);
	#endif
	scanf("%d%d%s", &n, &q, s + 1);
	rep(i, 1, n) buc[rk[i] = s[i]]++;
	rep(i, 1, m) buc[i] += buc[i - 1];
	rep(i, 1, n) sa[buc[rk[i]]--] = i;
	for(int k = 1;; k *= 2) {
		mem(buc, 0);
		int p = 0;
		rep(i, n - k + 1, n) tp[++p] = i;
		rep(i, 1, n) if(sa[i] > k) tp[++p] = sa[i] - k;
		rep(i, 1, n) buc[rk[i]]++;
		rep(i, 1, m) buc[i] += buc[i - 1];
		per(i, n, 1) sa[buc[rk[tp[i]]]--] = tp[i];
		memcpy(tp, rk, N * 4), p = 0;
		rep(i, 1, n) rk[sa[i]] = p += tp[sa[i]] ^ tp[sa[i - 1]] || tp[sa[i] + k] ^ tp[sa[i - 1] + k];
		if((m = p) == n) break;
	}
	int k = 0;
	rep(i, 1, n) {
		for(k ? k-- : 0; s[i + k] == s[sa[rk[i] - 1] + k]; k++);
		h[0][rk[i]] = k;
	}
	rep(i, 1, 17) rep(j, 1, n - (1 << i) + 1)
		h[i][j] = min(h[i - 1][j], h[i - 1][j + (1 << (i - 1))]);
	rep(i, 1, n) for(int& j = L[i] = i - 1; j && h[0][i] < h[0][j]; j = L[j]);
	per(i, n, 1) for(int& j = R[i] = i + 1; j <= n && h[0][i] <= h[0][j]; j = R[j]);
	while(q--) {
		scanf("%d%d", &a, &b);
		rep(i, 1, a) scanf("%d", &A[i]);
		rep(i, 1, b) scanf("%d", &B[i]);
		ll as = 0;
		if(a <= K && b <= K) rep(i, 1, a) rep(j, 1, b) as += lcp(A[i], B[j]);
		else {
			mem(c1, 0), mem(c2, 0);
			rep(i, 1, a) c1[rk[A[i]]]++;
			rep(i, 1, b) c2[rk[B[i]]]++;
			rep(i, 1, n) if(c1[i] && c2[i]) as += n - sa[i] + 1;
			per(i, n, 1) c1[i] += c1[i + 1], c2[i] += c2[i + 1];
			rep(i, 1, n) as += 1ll * h[0][i] * ((c1[L[i]] - c1[i]) * (c2[i] - c2[R[i]]) + (c2[L[i]] - c2[i]) * (c1[i] - c1[R[i]]));
		}
		printf("%lld\n", as);
	}
	return 0;
}
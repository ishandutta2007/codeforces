#include <bits/stdc++.h>

template <int MAXN = 3100000>
struct SA {
	int sa[MAXN], rk[MAXN], ht[MAXN], s[MAXN << 1], t[MAXN << 1], p[MAXN], cnt[MAXN], cur[MAXN];
#define pushS(x) sa[cur[s[x]]--] = x
#define pushL(x) sa[cur[s[x]]++] = x
#define inducedSort(v) std::fill_n(sa, n, -1); std::fill_n(cnt, m, 0);\
	for (int i = 0; i < n; i++) cnt[s[i]]++;\
	for (int i = 1; i < m; i++) cnt[i] += cnt[i-1];\
	for (int i = 0; i < m; i++) cur[i] = cnt[i]-1;\
	for (int i = n1-1; ~i; i--) pushS(v[i]);\
	for (int i = 1; i < m; i++) cur[i] = cnt[i-1];\
	for (int i = 0; i < n; i++) if (sa[i] > 0 &&  t[sa[i]-1]) pushL(sa[i]-1);\
	for (int i = 0; i < m; i++) cur[i] = cnt[i]-1;\
	for (int i = n-1;  ~i; i--) if (sa[i] > 0 && !t[sa[i]-1]) pushS(sa[i]-1)
	void sais(int n, int m, int *s, int *t, int *p) {
		int n1 = t[n-1] = 0, ch = rk[0] = -1, *s1 = s+n;
		for (int i = n-2; ~i; i--) t[i] = s[i] == s[i+1] ? t[i+1] : s[i] > s[i+1];
		for (int i = 1; i < n; i++) rk[i] = t[i-1] && !t[i] ? (p[n1] = i, n1++) : -1;
		inducedSort(p);
		for (int i = 0, x, y; i < n; i++) if (~(x = rk[sa[i]])) {
			if (ch < 1 || p[x+1] - p[x] != p[y+1] - p[y]) ch++;
			else for (int j = p[x], k = p[y]; j <= p[x+1]; j++, k++)
				if ((s[j]<<1|t[j]) != (s[k]<<1|t[k])) {ch++; break;}
			s1[y = x] = ch; }
		if (ch+1 < n1) sais(n1, ch+1, s1, t+n, p+n1);
		else for (int i = 0; i < n1; i++) sa[s1[i]] = i;
		for (int i = 0; i < n1; i++) s1[i] = p[sa[i]];
		inducedSort(s1); }
	template<typename T> int mapCharToInt(int n, const T *str) {
		int m = *std::max_element(str, str+n);
		std::fill_n(rk, m+1, 0);
		for (int i = 0; i < n; i++) rk[str[i]] = 1;
		for (int i = 0; i < m; i++) rk[i+1] += rk[i];
		for (int i = 0; i < n; i++) s[i] = rk[str[i]] - 1;
		return rk[m]; }
	template<typename T> void suffixArray(int n, const T *str) {
		int m = mapCharToInt(++n, str);
		sais(n, m, s, t, p);
		for (int i = 0; i < n; i++) rk[sa[i]] = i;
		for (int i = 0, h = ht[0] = 0; i < n-1; i++) {
			int j = sa[rk[i]-1];
			while (i+h < n && j+h < n && s[i+h] == s[j+h]) h++;
			if (ht[rk[i]] = h) h--; } } };

SA <> sa;

const int MOD = 998244353;

char A[3100000], L[3100000], R[3100000];
char LR[3100000];
int n, ll, rl;
int dp[3100000], pre[3100000];

int main () {
  scanf ("%s %s %s", A, L, R); n = strlen (A); ll = strlen (L); rl = strlen (R);
  for (int i = 0; i < n; ++i) LR[i] = A[i];
  for (int i = n + 1; i < n + ll + 1; ++i) LR[i] = L[i - n - 1];
  for (int i = n + ll + 2; i < n + ll + rl + 2; ++i) LR[i] = R[i - n - ll - 2];
  LR[n] = 2; LR[n + ll + 1] = 1; LR[n + ll + rl + 2] = 127;
//  for (int i = 0; i < n + ll + rl + 3; ++i) std::cout << (int)LR[i] << "\n";
  sa.suffixArray (n + ll + rl + 3, LR);
  int left = sa.rk[n + 1], right = sa.rk[n + ll + 2];
  dp[0] = 1;
  for (int i = 0, cur = 0; i < n; ++i) {
    if (A[i] != '0') {
      (pre[sa.rk[i] > left ? i + ll : i + ll + 1] += dp[i]) %= MOD;
      (pre[sa.rk[i] < right ? i + rl + 1 : i + rl] += -dp[i] + MOD) %= MOD;
//      std::cout << ":: " <<
//      sa.rk[i] << " " <<
//      left << " " << right << "\n";
//      std::cout <<
//      (sa.rk[i] > left ? i + ll : i + ll + 1) << " " <<
//      (sa.rk[i] < right ? i + rl + 1 : i + rl) << "\n";
    } else if (L[0] == '0') {
//      std::cout << ": " << i << " " << dp[i] << "\n";
      (pre[i + 1] += dp[i]) %= MOD;
      (pre[i + 2] += -dp[i] + MOD) %= MOD;
    }
    (cur += pre[i + 1]) %= MOD;
    dp[i + 1] = cur;
  }
//  for (int i = 0; i <= n; ++i) std::cout << i << " " << dp[i] << " " << pre[i] << "\n";
  std::cout << dp[n] << "\n";
}
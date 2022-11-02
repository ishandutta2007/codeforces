#include <bits/stdc++.h>
using namespace std;

const int mod = 1002333037;
const int P = 32323;

char s[1000010], tmp[1000010];
long long h[1000010], h1[1000010];
long long pw[1000010];

long long get_h(int l, int r) {
	return (h[r] - h[l - 1] * pw[r - l + 1] % mod + mod) % mod;
}

long long get_h_rev(int l, int r) {
	return (h1[l] - h1[r + 1] * pw[r - l + 1] % mod + mod) % mod;
}

int main () {
	pw[0] = 1;
	for (int i = 1; i <= 1000005; i++) {
		pw[i] = pw[i - 1] * P % mod;
	}
	int T; scanf("%d", &T);
	while (T--) {
		scanf("%s", s + 1); int n = strlen(s + 1);
		for (int i = 1; i <= n; i++) {
			h[i] = (h[i - 1] * P + s[i]) % mod;
		}
		for (int i = n; i >= 1; i--) {
			h1[i] = (h1[i + 1] * P + s[i]) % mod;
		}
		int p1 = 1, p2 = n;
		while (p1 < p2 && s[p1] == s[p2]) p1++, p2--;
		p1--, p2++;
		int ans = p1 * 2, pos = 0, pd = (p1 + 1 == p2 ? 0 : 1);
		for (int i = p1 + 1; ; i++) {
			int len = i - p1;
			if (i + len < p2 && get_h(p1 + 1, i) == get_h_rev(i + 1, i + len)) {
				if (ans < p1 * 2 + len * 2) {
					ans = p1 * 2 + len * 2;
					pos = len, pd = 0;
				}
			} else if (i + len >= p2) break;
			if (i + len + 1 < p2 && get_h(p1 + 1, i) == get_h_rev(i + 2, i + len + 1)) {
				if (ans < p1 * 2 + len * 2 + 1) {
					ans = p1 * 2 + len * 2 + 1;
					pos = len, pd = 1;
				}
			} else if (i + len + 1 >= p2) break;
		}
		for (int i = p2 - 1; ; i--) {
			int len = p2 - i;
			if (i - len > p1 && get_h(i, p2 - 1) == get_h_rev(i - len, i - 1)) {
				if (ans < p1 * 2 + len * 2) {
					ans = p1 * 2 + len * 2;
					pos = -len, pd = 0;
				}
			} else if (i - len <= p1) break;
			if (i - len - 1 > p1 && get_h(i, p2 - 1) == get_h_rev(i - len - 1, i - 2)) {
				if (ans < p1 * 2 + len * 2 + 1) {
					ans = p1 * 2 + len * 2 + 1;
					pos = -len, pd = 1;
				}
			} else if (i - len - 1 <= p1) break;
		}
		if (pos > 0) {
			int now = 1;
			for (int i = 1; i <= p1; i++) {
				tmp[now++] = s[i];
			}
			for (int i = p1 + 1; i <= p1 + 2 * pos + pd; i++) {
				tmp[now++] = s[i];
			}
			for (int i = p1; i >= 1; i--) {
				tmp[now++] = s[i];
			}
			tmp[now++] = '\0';
			printf("%s\n", tmp + 1);
		} else {
			int now = 1;
			for (int i = 1; i <= p1; i++) {
				tmp[now++] = s[i];
			}
			for (int i = p2 - 2 * (-pos) - pd; i <= n; i++) {
				tmp[now++] = s[i];
			}
			tmp[now++] = '\0';
			printf("%s\n", tmp + 1);
		}
	}
	return 0;
}
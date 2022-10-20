#include <bits/stdc++.h>

using namespace std;

const int N = 1000010, MOD = 1000000007;

int n;
char a[N], b[N];
int cnt[26];
int c[26];
int rev[N];

inline int add(int u, int v) {
	u += v;
	if (u >= MOD) {
		u -= MOD;
	}
	return u;
}

inline int sub(int u, int v) {
	u -= v;
	if (u < 0) {
		u += MOD;
	}
	return u;
}

inline int mul(int u, int v) {
	return (long long)u * v % MOD;
}

inline int qpow(int u, int v) {
	int res = 1;
	while (v) {
		if (v & 1) {
			res = mul(res, u);
		}
		u = mul(u, u);
		v >>= 1;
	}
	return res;
}

int main() {
	scanf("%s", a + 1);
	scanf("%s", b + 1);
	n = strlen(a + 1);
	for (int i = 1; i <= n; i++) {
		cnt[a[i] - 'a']++;
	}
	for (int i = 1; i <= n; i++) {
		rev[i] = qpow(i, MOD - 2);
	}
	for (int i = 0; i < 26; i++) {
		c[i] = cnt[i];
	}
	int cur = 1;
	for (int i = 1; i <= n; i++) {
		cur = mul(cur, i);
	}
	for (int i = 0; i < 26; i++) {
		for (int j = 1; j <= cnt[i]; j++) {
			cur = mul(cur, rev[j]);
		}
	}
	int backUpCur = cur;
	int res = 0;
	for (int i = 1; i <= n; i++) {
		cur = mul(cur, rev[n - i + 1]);
		//smaller
		for (int j = 0; j < b[i] - 'a'; j++) {
			if (!c[j]) {
				continue;
			}
			res = add(res, mul(cur, c[j]));
		}
		if (c[b[i] - 'a'] == 0) {
			break;
		}
		cur = mul(cur, c[b[i] - 'a']);
		c[b[i] - 'a']--;
	}
	res = sub(res, 1);
	cur = backUpCur;
	for (int i = 0; i < 26; i++) {
		c[i] = cnt[i];
	}
	for (int i = 1; i <= n; i++) {
		cur = mul(cur, rev[n - i + 1]);
		for (int j = 0; j < a[i] - 'a'; j++) {
			if (!c[j]) {
				continue;
			}
			// cout << i << " " << j << " " << mul(cur, c[j]) << endl;
			res = sub(res, mul(cur, c[j]));
		}
		cur = mul(cur, c[a[i] - 'a']);
		c[a[i] - 'a']--;
	}
	cout << res << endl;
	return 0;
}
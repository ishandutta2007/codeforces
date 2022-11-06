#include <bits/stdc++.h>
using namespace std;
const int maxn = 100000, mod = 1000000007;
string s, op[maxn + 10];
int n, val[10], len[10], ans;

void read(string &s) {
	static char t[maxn + 10];
	scanf("%s", t); s = t;
}

int fpow(int x, int y) {
	int ans = 1;
	while (y) {
		if (y % 2) ans = 1ll * ans * x % mod;
		y /= 2; x = 1ll * x * x % mod;
	}
	return ans;
}

int main() {
	read(s); scanf("%d", &n);
	for (int i = 1; i <= n; ++i) read(op[i]);
	for (int i = 0; i < 10; ++i) {
		val[i] = i; len[i] = 1;
	}
	for (int i = n; i >= 1; --i) {
		int tmpv = 0, tmpl = 0;
		for (int j = 3; j < op[i].size(); ++j) {
			int c = op[i][j] - '0';
			(tmpl += len[c]) %= (mod - 1); 
			tmpv = (1ll * tmpv * fpow(10, len[c]) + val[c]) % mod;
		}
		val[op[i][0] - '0'] = tmpv;
		len[op[i][0] - '0'] = tmpl;
	}
	for (int i = 0; i < s.size(); ++i) {
		int c = s[i] - '0';
		ans = (1ll * ans * fpow(10, len[c]) + val[c]) % mod;
	}
	printf("%d", ans);
}
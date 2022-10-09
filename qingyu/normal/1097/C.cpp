#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstdlib>
#include <vector>
#include <queue>
#include <stack>
#include <cctype>
#include <cstring>
#include <cassert>
#include <ctime>
#include <functional>
#include <map>

inline char nc() {
	static char buf[1000000], *p1 = buf, *p2 = buf;
	return p1 == p2 && (p2 = (p1 = buf) + fread(buf, 1, 1000000, stdin), p1 == p2) ? EOF : *p1++;
}

inline int read() {
	int res = 0;
	char ch;
	do ch = nc(); while (ch < 48 || ch > 57);
	do res = res * 10 + ch - 48, ch = nc(); while (ch >= 48 && ch <= 57);
	return res;
}

int S;
int val[1000005];
int neg[500005];
char s[500005];

const int delta = 500005;

int main() {
	int n;
	scanf("%d", &n);
	for (int i = 1; i <= n; ++i) {
		scanf("%s", s);
		int l = strlen(s), S = 0, min = 0;
		for (int j = 0; j < l; ++j) {
			if (s[j] == '(') ++S;
			else --S;
			if (S < 0) {
				neg[i] = true;
				min = std::min(min, S);
			}
		}
		if (S > min && neg[i] == true) continue;
		else ++val[S + delta];
	}
	long long ans = 0;
	ans += val[delta] / 2;
	for (int i = 1; i <= delta; ++i) {
		ans += std::min(val[delta + i], val[delta - i]);
	}
	printf("%lld", ans);
	return 0;
}
//QAQAQAQ?
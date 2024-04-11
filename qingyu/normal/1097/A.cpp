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
char s[5], s1[5], s2[5], s3[5], s4[5], s5[5];

std::map<char, bool> map;

int main() {
	scanf("%s%s%s%s%s%s", s, s1, s2, s3, s4, s5);
	for (int i = 0; i < 2; ++i) {
		map[s1[i]] = map[s2[i]] = map[s3[i]] = map[s4[i]] = map[s5[i]] = true;
	}
	if (map[s[0]] || map[s[1]]) {
		puts("YES");
	}
	else puts("NO");
    //qwqwq
	return 0;
}
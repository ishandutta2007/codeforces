#pragma warning(disable:4996)

#include <stdio.h>
#include <algorithm>
#include <assert.h>
#include <string.h>
#include <vector>
#include <set>
#include <tuple>

#define mp make_pair
#define mtp make_tuple
#define ni(n) scanf("%d", &(n))
#define nii(m, n) scanf("%d%d", &(m), &(n))

char buf1[1000010];
char buf2[1000010];

int main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	scanf("%s %s", buf1, buf2);
	int l1 = strlen(buf1);
	int l2 = strlen(buf2);
	int s1 = 0;
	int s2 = 0;
	while (s1 < l1 && buf1[s1] == '0') s1++;
	while (s2 < l2 && buf2[s2] == '0') s2++;
	if (l1 - s1 > l2 - s2) {
		puts(">"); return 0;
	}
	else if (l1 - s1 < l2 - s2) {
		puts("<"); return 0;
	}
	else {
		int res = strcmp(buf1 + s1, buf2 + s2);
		if (res > 0) puts(">");
		else if (res == 0)puts("=");
		else puts("<");
		return 0;
	}
	return 0;
}
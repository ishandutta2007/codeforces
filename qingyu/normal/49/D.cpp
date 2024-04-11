#pragma GCC optimize("Ofast")
#include<bits/stdc++.h>

char ch, s[500000];
int ar, br, cr;

inline int min (int x, int y) { return x < y ? x : y; }

int main() {
	int n;
	scanf("%d%s", &n, s);
	int ans1 = 0, ans2 = 0;
	for (int i = 0; i < n; ++i) {
		char &ch = s[i];
		if (ch == '1') ar = 1;
		else ar = 0;
		if (i & 1) br = 1, cr = 0;
		else br = 0, cr = 1;
		if (ar != br) ++ans1;
		if (ar != cr) ++ans2;
	}
	printf("%d", min(ans1, ans2));
	return 0;
}
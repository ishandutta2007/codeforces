#include <bits/stdc++.h>

long long A, B;
int used[110000];
int acnt = 0, bcnt = 0;

int main () {
	std::ios::sync_with_stdio (0);
	std::cin >> A >> B;	int sgn = 0;
	if (A > B) std::swap (A, B), sgn = 1;
	long long l = 0, r = 1E5, ans = -1;
	while (l <= r) {
		long long m = (l + r) / 2;
		if (m * (m + 1) / 2 <= A + B)
			ans = m, l = m + 1;
		else
			r = m - 1;
	}
	if (ans == 0) {
		printf ("0\n0\n"); return 0;
	}
	long long cur = A;
	for (long long i = ans; i >= 1; --i) {
		if (cur - i >= 0) {
			cur -= i; used[i] = 1; ++acnt;
		}
	}
	cur = B;
	for (long long i = 1; i <= ans; ++i) {
	   if (cur - i >= 0 && used[i] == 0) {
		   cur -= i; used[i] = -1; ++bcnt;
	   }
	}
	if (sgn) {
		printf ("%d\n", bcnt);
		for (int i = 1; i <= ans; ++i) if (used[i] == -1) printf ("%d ", i);
		puts ("");
		printf ("%d\n", acnt);
		for (int i = 1; i <= ans; ++i) if (used[i] == 1) printf ("%d ", i);
		puts ("");
	} else {
		printf ("%d\n", acnt);
		for (int i = 1; i <= ans; ++i) if (used[i] == 1) printf ("%d ", i);
		puts ("");
		printf ("%d\n", bcnt);
		for (int i = 1; i <= ans; ++i) if (used[i] == -1) printf ("%d ", i);
		puts ("");
	}
}
#include <bits/stdc++.h>

int cnt[1100], l[1100];
int f[1100];

int main () {
	int N;
	std::cin >> N;
	for (int i = 2; i <= N; ++i) {
		std::cin >> f[i];
		++cnt[f[i]];
	}
	for (int i = 1; i <= N; ++i) 
		if (cnt[i] == 0) ++l[f[i]];
	for (int i = 1; i <= N; ++i)
		if (cnt[i] != 0 && l[i] < 3) {
			puts ("No");
			return 0;
		}
	puts ("Yes");
}
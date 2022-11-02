#define _CRT_SECURE_NO_WARNINGS
#define fast ios::sync_with_stdio(false); cin.tie(0)
#define foru(i, k, n) for (int i = k; i < n; i++)
#define ford(i, k, n) for (int i = k; i >= n; i--)
#define pb push_back
#define mp make_pair

#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <list>
#include <bitset>
#include <intrin.h>

int g[]{ 0,1, 2, 1, 4, 3, 2, 1, 5, 6, 2, 1, 8, 7, 5, 9, 8, 7, 3, 4, 7, 4, 2, 1, 10, 9, 3, 6, 11, 12 };
bool b[40000];
bool piles[30];
int main() {
	int n, totcnt = 0;
	scanf("%d", &n);
	for (long long x = 2; x * x <= n; x++) {
		if (b[x])continue;
		long long t = x, cnt = 0;
		while (t <= n) {
			cnt++;
			totcnt++;
			if (t*t <= n)b[t] = 1;
			t *= x;
		}
		piles[cnt] = !piles[cnt];
	}
	piles[1] = ((n - totcnt) & 1);
	int totxor = 0;
	for (int i = 1; i <= 29; i++) {
		if (piles[i])totxor ^= g[i];
	}
	if (totxor != 0)printf("Vasya\n");
	else printf("Petya\n");
	return 0;
}
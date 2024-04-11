#define _CRT_SECURE_NO_WARNINGS
#define foru(i, k, n) for (int i = k; i < n; i++)
#define ford(i, k, n) for (int i = k; i >= n; i--)
#define pb push_back

#include <iostream>
#include <vector>
#include <algorithm>
#include <string.h>
#include <cstdio>

using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

const int sz = 4e3 + 5;
int n, k;
int a[sz][sz], dp[sz], prv[sz], c[sz][sz];

inline void dnc(const int& l,const int& r,const int& optl,const int& optr) {
	if (l > r)return;
	int mid = (l + r) / 2;
	int bst = 2e9, tmp;
	int bsti = -1;
	for (int i = optl; i <= mid && i <= optr; i++) {
		tmp = c[i][mid] + prv[i - 1];
		if (tmp < bst) {
			bst = tmp;
			bsti=i;
		}
	}
	dp[mid] = bst;
	dnc(l, mid - 1, optl, bsti);
	dnc(mid + 1, r, bsti, optr);
}

void calcCosts() {
	foru(d, 1, n) {
		foru(i, 0, n - d) {
			c[i][i + d] = c[i][i + d - 1] + c[i + 1][i + d] - c[i + 1][i + d - 1] + a[i][i + d];
		}
	}
}


int main() {
	scanf("%d%d\n", &n, &k);
	char buffer[10000];
	for (int i = 0; i < n; i++) {
		gets(buffer);
		for (int j = 0; j < n; j++)
			a[i][j] = buffer[2 * j] - '0';
	}
	calcCosts();
	foru(i, 0, n)prv[i] = c[0][i];
	foru(iter, 1, k) {
		dnc(iter, n - 1, iter, n - 1);
		foru(i, 0, n)prv[i] = dp[i];
	}
	printf("%d",prv[n-1]);
	return 0;
}
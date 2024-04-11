#pragma warning(disable:4996)

#include <stdio.h>
#include <iostream>
#include <assert.h>
#include <stdlib.h>
#include <string.h>
#include <vector>
#include <map>
#include <set>
#include <algorithm>
#include <tuple>
#include <complex>
#include <string>
#define mul(x,y) ((ll)(x)*(y))%mod

using namespace std;
typedef long long ll;

const int mod = 1000000007;

int prsum[1000];
int c[1000];
int inv[1001];

int ncr(int n, int r) {
	int ans = 1;
	for (int i = 0; i < r; i++) {
		ans = mul(ans, n - i);
		ans = mul(ans, inv[i + 1]);
	}
	return ans;
}

int main() {
#ifndef __GNUG__
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	inv[1] = 1;
	for (int i = 2; i <= 1000; i++) {
		inv[i] = mul(inv[mod%i], mod - mod / i);
	}

	int k; scanf("%d", &k);
	int ans = 1; int sum = 0;
	for (int i = 0; i < k; i++) {
		scanf("%d", c + i);
		sum += c[i];
		prsum[i] = sum;

	}
	for (int i = k - 1; i >= 0; i--) {
		ans = mul(ans, ncr(prsum[i] - 1, c[i] - 1));
	}

	printf("%d", ans);

	return 0;
}
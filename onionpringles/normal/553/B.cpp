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

ll fib[51];

vector<int> ans;
int res[50];

int main() {
#ifndef __GNUG__
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	fib[0] = 1;
	fib[1] = 1;
	for (int i = 2; i <= 50; i++) {
		fib[i] = fib[i - 1] + fib[i - 2];
		//printf("%I64d\n", fib[i]);
	}
	int n; ll k;
	scanf("%d %I64d", &n, &k);
	k--;
	while (k) {
		int i = 1;
		for (; i <= 49; i++) {
			if (fib[i + 1] > k) break;
		}
		k -= fib[i];
		ans.push_back(i);
	}
	for (int i = 0; i < n; i++) res[i] = i + 1;
	for (auto &x : ans) {
		swap(res[n - x], res[n - x - 1]);
	}
	for (int i = 0; i < n; i++) printf("%d ", res[i]);
	return 0;
}
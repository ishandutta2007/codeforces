#pragma warning(disable:4996)

#include <stdio.h>
#include <vector>
#include <set>
#include <algorithm>
#include <assert.h>
#include <string.h>
#include <string>
#include <iostream>

using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

int solve(ll n) {
	if (n == 0) return 0;
	vector<int> tmp;
	while (n) {
		tmp.push_back(n % 2);
		n /= 2;
	}
	int sz = tmp.size();
	int i;
	for (i = 0; i < sz; i++) {
		if (tmp[sz - 1 - i] == 0) break;
	}
	int j;
	for (j = 0; j < sz; j++) {
		if (tmp[j] == 0) break;
	}
	if (i == sz) {
		return sz*(sz - 1) / 2;
	}
	else {
		int cnt = (sz - 1)*(sz - 2) / 2;
		if (sz - 1 - i == j) {
			cnt += i;
		}
		else {
			cnt += (i - 1);
		}

		return cnt;
	}
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	ll a, b;
	cin >> a >> b;
	printf("%d", solve(b) - solve(a - 1));

	return 0;
}
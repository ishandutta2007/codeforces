#pragma warning(disable:4996)

#include <stdio.h>
#include <algorithm>
#include <vector>
#include <string.h>
#include <map>
#include <set>
#define mp make_pair
#define ni(n) scanf("%d", &(n))

using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

vector<int> odds;

int main() {
#ifndef __GNUG__
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	int n; ni(n);
	ll sum = 0;
	for (int i = 0; i < n; i++) {
		int x;
		ni(x);
		if (x % 2) odds.push_back(x);
		sum = sum + x;
	}
	if (sum % 2 == 0) {
		printf("%I64d\n", sum);
	}
	else {
		auto it = min_element(odds.begin(), odds.end());
		printf("%I64d", sum - *it);
	}
	return 0;
}
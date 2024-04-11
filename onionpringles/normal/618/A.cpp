#pragma warning(disable:4996)

#include <stdio.h>
#include <vector>
#include <algorithm>

using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

vector<int> ans;

int main() {
#ifndef __GNUG__
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

	int n;
	scanf("%d", &n);
	int v = 1;
	while (n) {
		if (n % 2) {
			ans.push_back(v);
		}
		v++;
		n /= 2;
	}
	int sz = ans.size();
	for (int i = sz - 1; i >= 0; i--) {
		printf("%d ", ans[i]);
	}

	return 0;
}
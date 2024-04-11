#include <bits/stdc++.h>
using namespace std;

bool same(int n) {
	string s = to_string(n);
	bool c[10] = {};
	for (char v : s) {
		if (c[v - '0']) return true;
		c[v - '0'] = true;
	}
	return false;
}

int main() {
	int l, r;
	scanf("%d%d", &l, &r);
	for (int i = l; i <= r; i++) {
		if (!same(i)) {
			printf("%d\n", i);
			return 0;
		}
	}
	printf("-1\n");
}
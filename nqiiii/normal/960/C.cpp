#include <bits/stdc++.h>
using namespace std;
typedef long long Long;
int x, d;
Long now;
vector<Long> ans;

int main() {
	scanf("%d%d", &x, &d);
	for (int i = 30; i >= 1; --i) {
		int v = (1 << i) - 1;
		while (x >= v) {
			x -= v; now += 1e10;
			for (int j = 1; j <= i; ++j) ans.push_back(now);
		}
	}
	printf("%d\n", (int)ans.size());
	for (int i = 0 ; i < ans.size(); ++i) printf("%lld ", ans[i]);
}
#include <bits/stdc++.h>
using namespace std;
const int maxn = 1000;
int n, ans[maxn + 10];
vector<int> ask;
int main() {
	scanf("%d", &n);
	for (int i = 0; i < n; ++i) ans[i] = 2e9;
	for (int i = 0; i < 10; ++i)
		for (int j = 0; j < 2; ++j) {
			ask.clear();
			for (int k = 0; k < n; ++k)
				if ((k >> i & 1) == j) ask.push_back(k + 1);
			if (!ask.empty()) {
				printf("%d\n", ask.size());
				for (int k = 0; k < ask.size(); ++k)
					printf("%d ", ask[k]);
				printf("\n"); fflush(stdout);
				for (int k = 0; k < n; ++k) {
					int x; scanf("%d", &x);
					if ((k >> i & 1) != j) ans[k] = min(ans[k], x);
				}
			}
		}
	printf("-1\n");
	for (int i = 0; i < n; ++i) printf("%d ", ans[i]);
	fflush(stdout);
}
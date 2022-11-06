#include <bits/stdc++.h>
using namespace std;
const int maxn = 100000;
int n, a[maxn + 10], f[maxn + 10], c[maxn + 10], ans;
bool np[maxn + 10];
vector<int> divs[maxn + 10];

void pre() {
	for (int i = 2; i <= maxn; ++i)
		if (!np[i]) {
			divs[i].push_back(i);
			for (int j = i + i; j <= maxn; j += i) {
				np[j] = 1; divs[j].push_back(i);
			}
		}
}

int main() {
	pre();
	scanf("%d", &n);
	for (int i = 1; i <= n; ++i) scanf("%d", &a[i]);
	for (int i = 1; i <= n; ++i) {
		for (int j = 0; j < divs[a[i]].size(); ++j) {
			int p = divs[a[i]][j];
			f[i] = max(f[i], c[p]);
		}
		++f[i]; ans = max(ans, f[i]);
		for (int j = 0; j < divs[a[i]].size(); ++j) {
			int p = divs[a[i]][j];
			c[p] = max(c[p], f[i]);
		}
	}
	printf("%d", ans);
}
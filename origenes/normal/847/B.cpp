#include <cstdio>
#include <algorithm>
#include <vector>
using namespace std;

int a[1000000];
int t[1000000];
int cnt = 0;
vector<int> ans[400000];

int n;

int main() {
	scanf("%d", &n);
	for (int i=1; i<=n; i++) {
		scanf("%d", &a[i]);
		a[i] = -a[i];
	}

	t[++cnt] = a[1];
	ans[1].push_back(a[1]);

	for (int i=2; i<=n; i++) {
		int pos = upper_bound(t+1, t+cnt+1, a[i]) - t;

		if (pos > cnt) {
			++cnt;
		}
		t[pos] = a[i];
		ans[pos].push_back(a[i]);

	}

	for (int i=1; i<=cnt; i++) {
		for (int j=0; j<ans[i].size(); j++) {
			printf("%d ", -ans[i][j]);
		}
		puts("");
	}

	return 0;
}
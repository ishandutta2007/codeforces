#ifdef _MSC_VER
#define _CRT_SECURE_NO_WARNINGS
#endif

#include <bits/stdc++.h>

using namespace std;

void one_case()
{
	int m, n;
	cin >> m >> n;
	vector<vector<int>> a(n);
	for (int i = 0; i < n; ++i) {
		int count;
		cin >> count;
		a[i] = vector<int>(count);
		for (int j = 0; j < count; ++j) {
			cin >> a[i][j];
			--a[i][j];
		}
	}
	vector<int> rank(n);
	for (int i = 0; i < n; ++i) {
		rank[i] = i;
	}
	sort(rank.begin(), rank.end(), [&](int x, int y) { return a[x].size() < a[y].size(); });

	vector<int> count(m);
	vector<int> result(n);
	for (int i : rank) {
		int p = a[i][0];
		for (int q : a[i]) {
			if (count[q] < count[p]) {
				p = q;
			}
		}
		++count[p];
		result[i] = p;
		if (count[p] > (n + 1) / 2) {
			printf("NO\n");
			return;
		}
	}
	printf("YES\n");
	for (int i = 0; i < n; ++i) {
		printf("%d ", result[i] + 1);
	}
	printf("\n");
}

int main()
{
#ifdef _MSC_VER
	freopen("a.in", "r", stdin);
#endif
	std::ios::sync_with_stdio(false);
	int t;
	cin >> t;
	while (t--) {
		one_case();
	}
	return 0;
}
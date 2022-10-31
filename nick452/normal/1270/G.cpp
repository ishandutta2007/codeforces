#ifdef _MSC_VER
#define _CRT_SECURE_NO_WARNINGS
#endif

#include <bits/stdc++.h>

using namespace std;

int main()
{
#ifdef _MSC_VER
	freopen("g.in", "r", stdin);
#endif
	std::ios::sync_with_stdio(false);
	int num_cases;
	cin >> num_cases;
	for (int case_id = 0; case_id < num_cases; ++case_id) {
		int n;
		cin >> n;
		vector<int> a(n);
		for (int i = 0; i < n; ++i) {
			cin >> a[i];
		}
		for (int i = 0; i < n; ++i) {
			a[i] = i - a[i]
				;
		}
		vector<int> used(n);
		vector<int> points;
		int p = 0;
		for (; !used[p]; p = a[p]) {
			points.push_back(p);
			used[p] = 1;
		}
		vector<int> results(std::find(points.begin(), points.end(), p), points.end());
		printf("%d\n", results.size());
		for (int idx : results) {
			printf("%d ", idx + 1);
		}
		printf("\n");
	}
	return 0;
}
#ifdef _MSC_VER
#define _CRT_SECURE_NO_WARNINGS
#endif

#include <bits/stdc++.h>

using namespace std;

int main()
{
#ifdef _MSC_VER
	freopen("a.in", "r", stdin);
#endif
	std::ios::sync_with_stdio(false);
	int num_cases;
	cin >> num_cases;
	for (int case_id = 0; case_id < num_cases; ++case_id) {
		int n, m, k;
		cin >> n >> m >> k;
		k = min(k, m - 1);
		vector<int> a(n);
		for (int i = 0; i < n; ++i) {
			cin >> a[i];
		}
		int results = 0;
		for (int num_front = 0; num_front <= k; ++num_front) {
			int num_back = k - num_front;
			int optimal = numeric_limits<int>::max();
			int num_arbitrary = m - 1 - k;
			for (int i = 0; i <= num_arbitrary; ++i) {
				optimal = min(optimal, max(a[num_front + i], a[n - 1 - num_back - (num_arbitrary - i)]));
			}
			results = max(results, optimal);
		}
		cout << results << endl;
	}
	return 0;
}
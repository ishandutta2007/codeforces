#ifdef _MSC_VER
#define _CRT_SECURE_NO_WARNINGS
#endif

#include <bits/stdc++.h>

using namespace std;

void doit(const vector<int>& a) {
	int n = a.size();
	int min_b = 0;
	int min_b_at = 0;
	int max_c = 0;
	int max_c_at = 0;
	for (int i = 0; i < n; ++i) {
		int b = a[i] - i;
		if (i == 0 || b < min_b) {
			min_b = b;
			min_b_at = i;
		}
		if (b > min_b) {
			printf("YES %d %d\n", min_b_at + 1, i + 1);
			return;
		}
		int c = a[i] + i;
		if (i == 0 || c > max_c) {
			max_c = c;
			max_c_at = i;
		}
		if (c < max_c) {
			printf("YES %d %d\n", max_c_at + 1, i + 1);
			return;
		}
	}
	printf("NO\n");
}

int main()
{
#ifdef _MSC_VER
	freopen("b.in", "r", stdin);
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
		doit(a);
	}
	return 0;
}
#ifdef _MSC_VER
#define _CRT_SECURE_NO_WARNINGS
#endif

#include <bits/stdc++.h>

using namespace std;

void solve_one_case()
{
	int n;
	long long k;
	cin >> n >> k;
	vector<long long> count(n + 1);
	count[0] = 1;
	for (int i = 1; i <= n; ++i) {
		for (int j = 1; j <= i; ++j) {
			count[i] += count[i - j];
			if (count[i] > k) {
				count[i] = k + 1;
				break;
			}
		}
	}
	if (count[n] < k) {
		printf("-1\n");
		return;
	}
	int next = 1;
	for (int i = n; i > 0; ) {
		for (int j = 1; j <= i; ++j) {
			if (count[i - j] < k) {
				k -= count[i - j];
				continue;
			}
			for (int l = j; l > 0; --l) {
				printf("%d ", next + l - 1);
			}
			i -= j;
			next += j;
			break;
		}
	}
	printf("\n");
}

int main()
{
#ifdef _MSC_VER
	freopen("b.in", "r", stdin);
#endif
	std::ios::sync_with_stdio(false);
	int num_cases;
	cin >> num_cases;
	for (int i = 0; i < num_cases; ++i) {
		solve_one_case();
	}
	return 0;
}
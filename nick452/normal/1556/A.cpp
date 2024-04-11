#ifdef _MSC_VER
#define _CRT_SECURE_NO_WARNINGS
#endif

#include <bits/stdc++.h>

using namespace std;

int solve(int a, int b) {
	if (a == 0 && b == 0) {
		return 0;
	}
	if ((a + b) % 2 != 0) {
		return -1;
	}
	if (a == b) {
		return 1;
	}
	return 2;
}
int main()
{
#ifdef _MSC_VER
	freopen("a.in", "r", stdin);
#endif
	std::ios::sync_with_stdio(false);
	int n_cases;
	cin >> n_cases;
	for (int case_id = 1; case_id <= n_cases; ++case_id) {
		int a, b;
		cin >> a >> b;
		printf("%d\n", solve(a, b));
	}
	return 0;
}
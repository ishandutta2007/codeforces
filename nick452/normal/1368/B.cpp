#ifdef _MSC_VER
#define _CRT_SECURE_NO_WARNINGS
#endif

#include <bits/stdc++.h>

using namespace std;

int main()
{
	std::ios::sync_with_stdio(false);
	string s = "codeforces";
	int m = s.length();
	long long n;
	cin >> n;
	vector<long long> count(m, 1);
	while (1) {
		long long c = 1;
		for (int i = 0; i < m; i++) {
			c *= count[i];
		}
		if (c >= n) {
			break;
		}
		auto it = std::min_element(count.begin(), count.end());
		++(*it);
	}
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < count[i]; j++) {
			printf("%c", s[i]);
		}
	}
	printf("\n");
	return 0;
}
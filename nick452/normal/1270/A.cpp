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
		int n, k1, k2;
		cin >> n >> k1 >> k2;
		vector<int> a1(k1);
		for (int i = 0; i < k1; ++i) {
			cin >> a1[i];
		}
		vector<int> a2(k2);
		for (int i = 0; i < k2; ++i) {
			cin >> a2[i];
		}
		if (*max_element(a1.begin(), a1.end()) > *max_element(a2.begin(), a2.end())) {
			printf("YES\n");
		} else {
			printf("NO\n");
		}
	}
	return 0;
}
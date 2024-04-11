#ifdef _MSC_VER
#define _CRT_SECURE_NO_WARNINGS
#endif

#include <bits/stdc++.h>

using namespace std;

int main()
{
#ifdef _MSC_VER
	freopen("b.in", "r", stdin);
#endif
	std::ios::sync_with_stdio(false);
	string a;
	cin >> a;
	vector<int> count[26];
	int n = a.length();
	for (int c = 0; c < 26; ++c) {
		count[c] = vector<int>(n + 1);
		for (int i = 0; i < n; ++i) {
			count[c][i + 1] = count[c][i] + (int)(a[i] == c + 'a');
		}
	}
	int num_queries;
	cin >> num_queries;
	for (int query_id = 0; query_id < num_queries; ++query_id) {
		int l, r;
		cin >> l >> r;
		--l;
		--r;
		if (l == r) {
			printf("Yes\n");
			continue;
		}
		int num_chars = 0;
		for (int c = 0; c < 26; ++c) {
			if (count[c][r + 1] > count[c][l]) {
				++num_chars;
			}
		}
		if (num_chars >= 3 || num_chars == 2 && a[l] != a[r]) {
			printf("Yes\n");
		} else {
			printf("No\n");
		}
	}
	return 0;
}
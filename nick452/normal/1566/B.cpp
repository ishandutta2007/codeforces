#ifdef _MSC_VER
#define _CRT_SECURE_NO_WARNINGS
#endif

#include <bits/stdc++.h>

using namespace std;

using ll = long long;

int solve(string s) {
	int n = s.size();
	int p = 0;
	while (p < n && s[p] != '0') {
		++p;
	}
	if (p >= n) {
		return 0;
	}
	while (p < n && s[p] == '0') {
		++p;
	}
	for (int i = p; i < n; ++i) {
		if (s[i] == '0') {
			return 2;
		}
	}
	return 1;
}

int main()
{
#ifdef _MSC_VER
	freopen("b.in", "r", stdin);
#endif
	std::ios::sync_with_stdio(false);
	int n_cases;
	cin >> n_cases;
	for (int case_id = 0; case_id < n_cases; ++case_id) {
		string s;
		cin >> s;
		cout << solve(s) << endl;
	}
	return 0;
}
#ifdef _MSC_VER
#define _CRT_SECURE_NO_WARNINGS
#endif

#include <bits/stdc++.h>

using namespace std;

int eval(const string& a, const string& b) {
	int ret = 0;
	for (int i = 0; i < a.length(); ++i) {
		if (a[i] != b[i]) {
			++ret;
		}
	}
	return ret;
}

int eval2(const string& s) {
	return eval(s, "RL");
}

int eval3(const string& s) {
	return min(eval(s, "RLL"), eval(s, "RRL"));
}

int eval4(const string& s) {
	return eval(s, "RRLL");
}

int solve2(const string& s) {
	int n = s.length();
	vector<int> f(n + 1, n + 1);
	f[0] = 0;
	for (int i = 0; i < n; i++) {
		if (i + 2 <= n) {
			f[i + 2] = min(f[i + 2], f[i] + eval2(s.substr(i, 2)));
		}
		if (i + 3 <= n) {
			f[i + 3] = min(f[i + 3], f[i] + eval3(s.substr(i, 3)));
		}
		if (i + 4 <= n) {
			f[i + 4] = min(f[i + 4], f[i] + eval4(s.substr(i, 4)));
		}
	}
	return f[n];
}

int solve(string s) {
	int ret = solve2(s);
	for (int i = 0; i < 5; i++) {
		s = s.substr(1) + s.substr(0, 1);
		ret = min(ret, solve2(s));
	}
	return ret;

}

int main()
{
#ifdef _MSC_VER
	freopen("d.in", "r", stdin);
#endif
	std::ios::sync_with_stdio(false);
	int num_cases;
	cin >> num_cases;
	while (num_cases--) {
		int n;
		string s;
		cin >> n >> s;
		cout << solve(s) << endl;
	}
	return 0;
}
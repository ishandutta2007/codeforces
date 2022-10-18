#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

i64 solve_naive(string s, i64 a, i64 b, i64 c) {
	map<pair<string,bool>,i64> dp;
	function<i64(string,bool)> rec = [&](string t, bool odd) {
		pair<string,bool> pr(t,odd);
		if (dp.count(pr)) return dp[pr];
		
		int n = size(t);
		i64 res = 0;
		if (odd) {
			for (int i = 0; i+1 < n; i++) if (t[i] == '0' && t[i+1] == '0') {
				res = max(res, a + rec(t.substr(0,i) + t.substr(i+1), !odd));
			}
			for (int i = 0; i < n; i++) if (t[i] == '0') {
				res = max(res, -c + rec(t.substr(0,i) + t.substr(i+1), !odd));
			}
		} else {
			for (int i = 0; i+1 < n; i++) if (t[i] == '1' && t[i+1] == '1') {
				res = max(res, b + rec(t.substr(0,i) + t.substr(i+1), !odd));
			}
		}
		return dp[pr] = res;
	};

	return max(rec(s, true), rec(s, false));
}

i64 solve(string s, i64 a, i64 b, i64 c) {
	int n = size(s);
	
	int ca = 0, cb = 0;
	for (int i = 0; i+1 < n; i++) {
		if (s[i] == s[i+1]) (s[i] == '0' ? ca : cb)++;
	}
	
	if (b <= c) {
		ca = min(ca, cb+1);
		cb = min(cb, ca+1);
		return ca*a + cb*b;
	}

	vector<int> ones;
	for (int i = 0; i < n; i++) {
		if (s[i] == '1') ones.push_back(i);
	}

	if (2*ssize(ones) > n+1) {
		int z = n - size(ones);
		return ca*a + (z+1)*b - (z-ca)*c;
	}

	if (2*ssize(ones) == n+1 && (s[0] == '0' || s[n-1] == '0')) {
		int z = n - size(ones);
		return ca*a + z*b - (z-1-ca)*c;
	}
	
	ca = min(ca, cb+1);

	vector<int> lens;
	for (int j = 0; j+1 < ssize(ones); j++) {
		int len = ones[j+1]-ones[j]-2;
		if (len >= 0) lens.push_back(len);
	}
	sort(begin(lens), end(lens));

	int k = 0, sum = 0;
	while (k < ssize(lens) && sum+lens[k] <= cb) sum += lens[k++];
	
	return ca*a + cb*b + k*(b-c);
}

void test() {
	srand(987);
	for (int tc = 0; tc < 100000; tc++) {
		int n = 1 + rand() % 10;
		int a = 1 + rand() % 10;
		int b = 1 + rand() % 10;
		int c = 1 + rand() % 10;
		string s(n,'0');
		for (int i = 0; i < n; i++) {
			s[i] += rand() % 2;
		}

		i64 x = solve(s,a,b,c);
		i64 y = solve_naive(s,a,b,c);

		if (x != y) {
			cout << s << " " << a << " " << b << " " << c << " " << x << " " << y << '\n';
		}
	}
}

int main() {
	int tc; cin >> tc;
	while (tc--) {
		int n, a, b, c;
		cin >> n >> a >> b >> c;
		
		string s; cin >> s;
		
		cout << solve(s,a,b,c) << '\n';
	}
}
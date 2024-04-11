#include <bits/stdc++.h>
using namespace std;

#define int long long
const int M = 998244353;

int n;
string s;

pair<int, string> solve(int x) {
	if (2*x >= s.size()) {
		return make_pair(1, string(1, s[x-1]));
	}

	auto [ans1, s1] = solve(2*x);
	auto [ans2, s2] = solve(2*x + 1);

	if (s1 > s2) swap(s1, s2);

	int ans = (ans1*ans2) % M;
	if (s1 != s2) ans = (ans*2) % M;

	return make_pair(ans, string(1, s[x-1])+s1+s2);
}

signed main() {
	ios::sync_with_stdio(0); cin.tie(0);

	cin >> n >> s;
	cout << solve(1).first << '\n';

	return 0;
}
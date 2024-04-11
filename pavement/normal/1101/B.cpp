#include <bits/stdc++.h>
using namespace std;
#define int long long

main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	string s;
	cin >> s;
	int idx = 0, l = 0;
	while (!s.empty() && s.back() != ']') s.pop_back();
	while (idx < s.size() && s[idx] != '[') idx++;
	while (!s.empty() && s.back() != ':') s.pop_back();
	while (idx < s.size() && s[idx] != ':') idx++;
	if (idx >= (int)s.size() - 1) return cout << "-1\n", 0;
	for (int i = idx + 1; i < s.size() - 1; i++)
		if (s[i] == '|') l++;
	cout << l + 4 << '\n';
}
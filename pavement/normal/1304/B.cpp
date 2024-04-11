#include <bits/stdc++.h>
using namespace std;
#define int long long

bool taken[105], h;
int tkby[105], n,m;
map<string, int> tcnt;
string s[105];

bool ip(string a, string b) {
	for (int i = 0; i < a.size(); i++)
		if (a[i] != b[a.size() - i - 1]) return 0;
	return 1;
}

main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n >> m;
	for (int i = 1; i <= n; i++)
		cin >> s[i];
	for (int i = 1; i <= n; i++) {
		if (taken[i]) continue;
		for (int j = 1; j <= n; j++) {
			if (i == j || taken[j]) continue;
			if (ip(s[i], s[j])) {
				tcnt[s[i]] += 2;
				taken[i] = taken[j] = 1;
				tkby[i] = j;
				break;
			}
		}
		if (!taken[i] && ip(s[i], s[i]))
			h = 1;
	}
	int se = 0;
	for (int i = 1; i <= n; i++)
		se += taken[i] * m;
	se += h * m;
	cout << se << '\n';
	vector<pair<string, int> > rev;
	for (auto i : tcnt)
		for (int j = 0; j < i.second / 2; j++) cout << i.first, rev.push_back(i);
	for (int i = 1; i <= n; i++)
		if (!taken[i] && ip(s[i], s[i])) {
			cout << s[i];
			break;
		}
	reverse(rev.begin(), rev.end());
	for (auto i : rev) {
		for (int j = 0; j < i.second / 2; j++) {
			for (int k = 0; k < m; k++)
				cout << i.first[m - k - 1];
		}
	}
	cout << '\n';
}
#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ar array

string a, b;
set<string> s;

void solve() {
	cin >> a >> b;
	s.clear();
	int best = 0;
	for (int i = 0; i < a.size(); ++i)
		for (int j = 1; i + j - 1 < a.size(); ++j)
			s.insert(a.substr(i, j));
	for (int i = 0; i < b.size(); ++i)
		for (int j = 1; i + j - 1 < b.size(); ++j)
			if (s.find(b.substr(i, j)) != s.end())
				best = max(best, j);
	cout << a.size() + b.size() - 2 * best << "\n";
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int t; cin >> t;
	while(t--)
		solve();
	return 0;
}
#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define arr array

string p, h;

void solve() {
	//brute force check all sublengths p.size() in the hash
	cin >> p >> h;
	sort(p.begin(), p.end());

	if (h.size() < p.size()) {
		cout << "NO\n";
		return;
	}

	for (int i=0; i<=h.size()-p.size(); ++i) {
		string s = h.substr(i, p.size());
		sort(s.begin(),s.end());
		if (p==s) {
			cout << "YES\n";
			return;
		}
	}

	cout << "NO\n";
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int t;
	cin >> t;
	while (t--)
		solve();

	return 0;
}
#include <bits/stdc++.h>
using namespace std;

pair<int, int> s[5005];

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int t;
	cin >> t;
	string a, b;
	while (t--) {
		cin >> a >> b;
		if (a < b) {
			cout << a << '\n';
			continue;
		}
		bool f = 0;
		int l = min(a.size(), b.size());
		s[a.size() - 1] = make_pair(a[a.size() - 1], a.size() - 1);
		for (int i = a.size() - 2; i >= 0; i--)
			if (a[i] < s[i + 1].first) s[i] = make_pair(a[i], i);
			else s[i] = s[i + 1];
		for (int i = 0; i < l; i++) {
			if (a[i] < b[i]) continue;
			swap(a[i], a[s[i].second]);
			if (a < b) {
				cout << a << '\n';
				f = 1;
				break;
			}
			swap(a[i], a[s[i].second]);
		}
		if (!f) cout << "---\n";
	}
}
#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ar array

string s;
set<int> oc[26];

void solve() {
	for (int i = 0; i < 26; ++i)
		oc[i].clear();
	cin >> s;
	int n = s.size();
	for (int i = 0; i < n; ++i)
		oc[s[i] - 'a'].insert(i);
	string ans;
	int last = -1;
	while(last != n - 1) {
		bool nf = 1;
		for (int i = 25; ~i; --i) {
			if (oc[i].empty())
				continue;
			int pos = *oc[i].begin();
			bool ok = 1;
			for (int j = last + 1; j < pos; ++j)
				if (oc[s[j] - 'a'].size() && *oc[s[j] - 'a'].rbegin() < pos) {
					ok = 0;
					break;
				}
			if (ok) {
				//cout << oc['e' - 'a'].size() << " ";
				ans += 'a' + i;
				oc[i].clear();
				for (int j = last + 1; j < pos; ++j)
					oc[s[j] - 'a'].erase(j);
				last = pos;
				nf = 0;
				//cout << oc['e' - 'a'].size() << "\n";
				break;
			}
		}
		if (nf)
			break;
	}
	cout << ans << "\n";
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int t; cin >> t;
	while(t--)
		solve();
	return 0;
}
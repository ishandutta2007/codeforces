#include <bits/stdc++.h>
using namespace std;

signed main() {
	ios::sync_with_stdio(0); cin.tie(0);

	string s; cin >> s;
	int i = 0, j = s.size() - 1;
	vector<int> ans;
	while (i < j) {
		while ((i < j) && s[i] != '(') i++;
		while ((i < j) && s[j] != ')') j--;

		if (i < j) {
			ans.push_back(i);
			ans.push_back(j);
			i++; j--;
		} else {
			if (ans.empty()) {
				cout << "0\n";
				exit(0);
			} else {
				cout << "1\n";
				sort(ans.begin(), ans.end());
				cout << ans.size() << '\n';
				for (int i: ans) cout << i+1 << ' ';
					exit(0);
			}
		}
	}

	if (ans.empty()) {
		cout << "0\n";
		exit(0);
	} else {
		cout << "1\n";
		sort(ans.begin(), ans.end());
		cout << ans.size() << '\n';
		for (int i: ans) cout << i+1 << ' ';
			exit(0);
	}
			

	return 0;
}
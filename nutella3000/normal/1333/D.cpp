#include <bits/stdc++.h>
#define int long long
#define pii pair<int, int>
  
using namespace std;
const int inf = 1e9 + 7;



signed main() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

	int n, k;
	string s;
	cin >> n >> k >> s;
	vector<vector<int>> id(n + 1);

	int sz = 0;
	int cnt = 0;
	for(int it = 0;it < n;it++) {
		for(int i = n - 2;i >= 0;i--) {
			if (s[i] == 'R' && s[i + 1] == 'L') {
				s[i] = 'L';
				s[i + 1] = 'R';
				cnt++;
				id[sz].emplace_back(i + 1);
				i--;
			}
		}
		if (!id[sz].empty()) sz++;
	}

	if (k < sz || k > cnt) {
		cout << -1;
		return 0;
	}

	int it = 0;
	//cout << sz << '\n';

	while(it < sz) {
		while (!id[it].empty() && k > sz - it) {
			cout << 1 << " " << id[it][id[it].size() - 1] << '\n';
			k--;
			id[it].pop_back();
		}

		if (!id[it].empty()) {
			cout << id[it].size() << " ";
			for(int i : id[it]) cout << i << " ";
			cout << '\n';
			k--;
		}

		it++;
	}


}
#include <bits/stdc++.h>
using namespace std;

vector<int> __cnt(1000001);
set<int> gg[5005];
map<int, int> mp;
int ans_mx = 2;

int cnt(int x) {
	if (x <= 1000000) return __cnt[x];
	else return mp[x];
}

int lookup(int f) {
	if (gg[f].upper_bound(ans_mx) == gg[f].end()) return -1;
	return *gg[f].upper_bound(ans_mx);
}

void insert(int x) {
	int f = cnt(x);
	if (f) gg[f].erase(gg[f].find(x));
	gg[f+1].insert(x);

	if (x <= 1000000) __cnt[x]++;
	else mp[x]++;
}

signed main() {
	//ios::sync_with_stdio(0); cin.tie(0);

	int n, m; cin >> n >> m;
	if (n <= 2) {
		if (m == 0) {
			if (n == 1) cout << 1;
			else cout << "1 2";
		} else {
			cout << -1;
		}
		exit(0);
	}
	vector<int> ans;

	ans.push_back(1);
	ans.push_back(2);
	insert(3);

	int curmx = 1000000000;
	while (ans.size() < n) {
		if (m == 0) {
			ans.push_back(curmx); curmx -= ans_mx + 2;
		} else {
			int f = min(5000, m);
			while (lookup(f) == -1) {
				f--;
			}

			int nd = lookup(f);
			m -= f;

			for (int i: ans) insert(i + nd);
			ans.push_back(nd);
			ans_mx = max(ans_mx, nd);
		}
	}

	sort(ans.begin(), ans.end());
	if (m == 0) {
		for (int i: ans) cout << i << ' ';
	} else {
		cout << "-1\n";
	}

	return 0;
}
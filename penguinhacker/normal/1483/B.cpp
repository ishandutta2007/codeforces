#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ar array

int n, a[100000];

void solve() {
	cin >> n;
	for (int i = 0; i < n; ++i)
		cin >> a[i];
	set<int> all, to;
	for (int i = 0; i < n; ++i) {
		all.insert(i);
		if (__gcd(a[i], a[(i + 1) % n]) == 1)
			to.insert((i + 1) % n);
	}
	int last = 0;
	vector<int> ans;
	while(!to.empty()) {
		auto it = to.upper_bound(last);
		if (it == to.end())
			it = to.begin();
		int ind = *it;
		to.erase(it);
		ans.push_back(ind);
		if (all.size() == 1)
			break;
		it = all.find(ind);
		int prv = it == all.begin() ? *all.rbegin() : *prev(it);
		int nxt = next(it) == all.end() ? *all.begin() : *next(it);
		last = nxt;
		all.erase(it);
		to.erase(nxt);
		if (__gcd(a[nxt], a[prv]) == 1)
			to.insert(nxt);
		continue;	
	}
	cout << ans.size();
	for (int i : ans)
		cout << " " << i + 1;
	cout << "\n";
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int t; cin >> t;
	while(t--)
		solve();
	return 0;
}
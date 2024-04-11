#include <bits/stdc++.h>
using namespace std;

signed main() {
	ios::sync_with_stdio(0); cin.tie(0);

	int n; cin >> n;
	vector<long long> a(n);
	vector<long long> b(n);

	map<long long, int> cnt;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
		cnt[a[i]]++;
	}
	for (int i = 0; i < n; i++) {
		cin >> b[i];
	}

	long long sum = 0;
	vector<int> loners;
	set<long long> groups;
	for (int i = 0; i < n; i++) {
		if (cnt[a[i]] > 1) {
			groups.insert(a[i]);
			sum += b[i];
		} else {
			loners.push_back(i);
		}
	}

	vector<long long> gr(groups.begin(), groups.end());
	for (int i: loners) {
		int workable = 0;
		for (long long j: gr) {
			if ((j | a[i]) == j) {
				workable = 1; break;
			}
		}
		sum += b[i] * workable;
	}
	cout << sum;

	return 0;
}
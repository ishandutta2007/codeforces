#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ar array

int n, a[100000];
vector<int> oc[100001];

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n;
	for (int i = 0; i < n; ++i) {
		cin >> a[i], --a[i];
		oc[a[i]].push_back(i);
	}
	for (int i = 0; i <= n; ++i) oc[i].push_back(69696969);
	int ans = 0;
	int last1 = n;
	int last2 = n;
	for (int i = 0; i < n; ++i) {
		if (a[i] != last1 && a[i] != last2) {
			++ans;
			int pos1 = *lower_bound(oc[last1].begin(), oc[last1].end(), i);
			int pos2 = *lower_bound(oc[last2].begin(), oc[last2].end(), i);
			if (pos1 >= pos2) last1 = a[i];
			else last2 = a[i];
		}
	}
	cout << ans;
	return 0;
}
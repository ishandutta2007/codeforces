#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ar array

int n, k;
string s;
vector<int> oc;

void solve() {
	cin >> n >> k >> s;
	oc.clear();
	for (int i = 0; i < n; ++i)
		if (s[i] == '*')
			oc.push_back(i);
	int ans = 1, last = oc[0];
	for (int i = 1; i < oc.size(); ++i) {
		if (i + 1 == oc.size() || oc[i + 1] - last > k) {
			++ans;
			last = oc[i];
		}
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
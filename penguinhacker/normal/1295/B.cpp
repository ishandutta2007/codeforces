#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ar array

string s;
int n, k;

void solve() {
	map<int, int> oc;
	cin >> n >> k >> s;
	int dif = 0;
	for (char c : s) {
		dif += c == '0' ? 1 : -1;
		++oc[dif];
	}
	int ans = k == 0;
	if (dif == 0) {
		if (oc.find(k) != oc.end()) {cout << "-1\n"; return;}
		cout << "0\n"; return;
	}
	int small = oc.begin()->first;
	int big = oc.rbegin()->first;
	if (dif < 0) { //we are moving k upwards
		for (int i = 30; i >= 0; --i) {
			if (k - (ll)(1 << i) * dif < small) k -= dif << i;
		}
		while(k <= big) ans += oc[k], k -= dif;
	}
	if (dif > 0) { //we are moving k downwards
		for (int i = 30; i >= 0; --i) {
			if (k - (ll)(1 << i) * dif > big) k -= dif << i;
		}
		while (k >= small) ans += oc[k], k -= dif;
	}
	cout << ans << "\n";
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int t;
	cin >> t;
	while(t--) solve();
	return 0;
}
#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define arr array

int n;
set<int, greater<int>> even;

void solve() {
	cin >> n;
	for (int i=0; i<n; ++i) {
		int a;
		cin >> a;
		if (!(a&1))
			even.insert(a);
	}
	int cnt=0;
	while (!even.empty()) {
		auto it = even.begin();
		int b = *it/2;
		even.erase(it);
		if (!(b&1))
			even.insert(b);
		cnt++;
	}
	cout << cnt << '\n';
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int t;
	cin >> t;
	while(t--)
		solve();

	return 0;
}
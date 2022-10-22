#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ar array

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int t;
	cin >> t;
	while(t--) {
		int n;
		cin >> n;
		vector<int> v(2*n), cnt(n+1, 0);
		for (auto &i : v) cin >> i;
		for (int i : v) {++cnt[i]; if (cnt[i]==2) {cout << i << ' ';}}
		cout << '\n';
	}
	return 0;
}

/* stuff you should look for
	* int overflow, array bounds
	* special cases (n=1?)
	* do smth instead of nothing and stay organized
	* WRITE STUFF DOWN
*/
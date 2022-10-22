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
		int n, x;
		cin >> n >> x;
		vector<int> v(n);
		for (auto &i : v) cin >> i;
		sort(v.rbegin(), v.rend());
		ll cur=0;
		int ans=0;
		for (int i : v) {
			++cur;
			if (cur*i>=x) {
				++ans;
				cur=0;
			}
		}
		cout << ans << '\n';
	}
	return 0;
}

/* stuff you should look for
	* int overflow, array bounds
	* special cases (n=1?)
	* do smth instead of nothing and stay organized
	* WRITE STUFF DOWN
*/
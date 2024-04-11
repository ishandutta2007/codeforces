#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ar array

int n;
vector<int> ans;

void solve() {
	cin >> n, ans.clear();
	for (int i=0; i*i<=n; ++i) {
		ans.push_back(i);
		if (i)
			ans.push_back(n/i);
	}
	sort(ans.begin(), ans.end());
	auto it=unique(ans.begin(), ans.end());
	ans.resize(it-ans.begin());
	cout << ans.size() << '\n';
	for (int i : ans)
		cout << i << ' ';
	cout << '\n';
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

/* stuff you should look for
	* int overflow, array bounds
	* special cases (n=1?)
	* do smth instead of nothing and stay organized
	* WRITE STUFF DOWN
*/
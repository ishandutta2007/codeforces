#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ar array

int n;
string a, b;

void solve() {
	cin >> n >> a >> b;
	bool x=0;
	vector<int> ans;
	for (int i=0; i<n-1; ++i)
		if (a[i]!=a[i+1])
			ans.push_back(i+1);
	if ((a[n-1]=='1')^(b[n-1]=='1')) ans.push_back(n);
	for (int i=n-2; i>=0; --i)
		if (b[i]!=b[i+1])
			ans.push_back(i+1);
	cout << ans.size() << ' ';
	for (int i: ans)
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
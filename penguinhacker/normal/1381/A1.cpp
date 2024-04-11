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
	for (int i=n-1; ~i; --i) {
		if (a[i]==b[i]) continue;
		if (a[0]==b[i]) {
			ans.push_back(1);
			a[0]=a[0]=='0'?'1':'0';
		}
		ans.push_back(i+1);
		for (int j=0; j<=i; ++j)
			a[j]=a[j]=='0'?'1':'0';
		reverse(a.begin(), a.begin()+i+1);
	}
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
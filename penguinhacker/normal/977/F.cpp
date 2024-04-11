#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ar array

int n, a[200000], dp[200000], last[200000];
map<int, int> loc;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n;
	for (int i=0; i<n; ++i) {
		cin >> a[i];
		loc[a[i]]=i;
		if (loc.find(a[i]-1)!=loc.end()) {
			last[i]=loc[a[i]-1];
			dp[i]=dp[last[i]]+1;
		}
		else {
			last[i]=-1;
			dp[i]=1;
		}
	}
	int temp=0;
	for (int i=1; i<n; ++i)
		if (dp[i]>dp[temp])
			temp=i;
	cout << dp[temp] << '\n';
	stack<int> ans;
	while(temp!=-1) {
		ans.push(temp+1);
		temp=last[temp];
	}
	while(ans.size()) {
		cout << ans.top() << ' ';
		ans.pop();
	}
	return 0;
}

/* stuff you should look for
	* int overflow, array bounds
	* special cases (n=1?)
	* do smth instead of nothing and stay organized
	* WRITE STUFF DOWN
*/
#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ar array

const int mxN=1e5, INF=1e9;
int n, dp[mxN], last[mxN];
ar<int, 4> a[mxN];
map<ar<int, 2>, int> mp;
vector<int> ans;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n;
	for (int i=0; i<n; ++i) {
		for (int j=0; j<4; ++j)
			cin >> a[i][j];
		dp[i]=-INF, last[i]=-1;
		if (a[i][2]==0) {
			dp[i]=a[i][0];
		} else {
			ar<int, 2> c={a[i][2], a[i][1]+a[i][3]};
			if (mp.find(c)!=mp.end()) {
				int x=mp[c];
				dp[i]=dp[x]+a[i][0], last[i]=x;
			}
		}
		if (dp[i]<0)
			continue;
		ar<int, 2> c={a[i][1]+a[i][2], a[i][3]};
		auto it=mp.find(c);
		if (it==mp.end()||dp[it->second]<dp[i])
			mp[c]=i;
	}
	int pos=-1;
	for (int i=0; i<n; ++i)
		if (dp[i]>0&&a[i][3]==0&&(i==-1||dp[i]>dp[pos]))
			pos=i;
	if (pos==-1) {
		cout << 0;
		return 0;
	}
	for (; ~pos; pos=last[pos])
		ans.push_back(pos);
	cout << ans.size() << "\n";
	for (int i=ans.size()-1; ~i; --i)
		cout << ans[i]+1 << " ";
	return 0;
}
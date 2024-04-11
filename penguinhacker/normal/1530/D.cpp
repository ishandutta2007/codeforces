#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ar array

const int mxN=2e5;
int n, a[mxN], ans[mxN];
bool vis[mxN];

void solve() {
	cin >> n;
	for (int i=0; i<n; ++i) {
		cin >> a[i], --a[i];
		vis[i]=0;
		ans[i]=0;
	}
	int cnt=0;
	for (int i=0; i<n; ++i)
		if (!vis[a[i]]) {
			ans[i]=a[i]+1;
			vis[a[i]]=1;
			++cnt;
		}
	vector<int> unvis;
	for (int i=0; i<n; ++i)
		if (!vis[i])
			unvis.push_back(i+1);
	vector<int> bad;
	for (int i=0; i<n; ++i)
		if (!ans[i]) {
			assert(unvis.size());
			ans[i]=unvis.back();
			if (ans[i]==i+1)
				bad.push_back(i);
			unvis.pop_back();
		}
	assert(unvis.empty());
   	if (bad.size()>1) {
		for (int i=0; i<bad.size(); ++i)
			ans[bad[i]]=bad[(i+1)%bad.size()]+1;
	} else if (bad.size()==1) {
		for (int i=0; i<n; ++i) {
			vis[i]=0;
			ans[i]=0;
		}
		ans[bad[0]]=a[bad[0]]+1;
		vis[a[bad[0]]]=1;
		unvis.clear();
		bad.clear();
		cnt=1;
		for (int i=0; i<n; ++i)
			if (!ans[i]&&!vis[a[i]]) {
				ans[i]=a[i]+1;
				vis[a[i]]=1;
				++cnt;
			}
		for (int i=0; i<n; ++i)
			if (!vis[i])
				unvis.push_back(i+1);
		for (int i=0; i<n; ++i)
			if (!ans[i]) {
				assert(unvis.size());
				ans[i]=unvis.back();
				if (ans[i]==i+1)
					bad.push_back(i);
				unvis.pop_back();
			}
		assert(bad.empty());
	}
	cout << cnt << "\n";
	for (int i=0; i<n; ++i)
		cout << ans[i] << " ";
	cout << "\n";
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
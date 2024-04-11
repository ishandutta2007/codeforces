#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ar array

const int mxN=3e5;
int n, a[mxN], prv[mxN], dp[mxN];
map<int, int> mp[mxN];

void solve() {
	cin >> n;
	for (int i=0; i<n; ++i) {
		cin >> a[i];
		prv[i]=-1;
		dp[i]=0;
		mp[i].clear();
	}
	for (int i=1; i<n; ++i) {
		if (a[i]==a[i-1]) {
			prv[i]=i-1;
			if (prv[i]>0) {
				swap(mp[i], mp[prv[i]-1]);
				mp[i][a[prv[i]-1]]=prv[i]-1;
			}
		}
		else {
			auto it=mp[i-1].find(a[i]);
			if (it==mp[i-1].end())
				continue;
			int pos=it->second;
			prv[i]=pos;
			if (pos>0) {
				swap(mp[i], mp[pos-1]);
				mp[i][a[pos-1]]=pos-1;
			}
		}
		/*else {
			int j=i-1;
			while(1) {
				j=prv[j]-1;
				if (j<0)
					break;
				if (a[i]==a[j]) {
					prv[i]=j;
					break;
				}
			}
		}*/
	}
	ll ans=0;
	for (int i=1; i<n; ++i) {
		if (prv[i]==-1)
			continue;
		dp[i]=1;
		if (prv[i]>0)
			dp[i]+=dp[prv[i]-1];
		ans+=dp[i];
	}
	cout << ans << "\n";
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
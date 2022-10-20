#include<bits/stdc++.h>
#define ll long long
using namespace std;

void work() {
	int n;
	ll ans=0;
	string s;
	cin>>n>>s;
	vector<int>vis(n);
	for (int i=1;i<=n;i++) {
		for (int j=i;j<=n;j+=i) {
			if (s[j-1]=='1') {
				break;
			}
			if (!vis[j-1]) {
				vis[j-1]=1;
				ans+=i;
			}
		}
	}
	cout<<ans<<"\n";
}

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	
	int T;
	cin>>T;
	while (T--) {
		work();
	}
	
	return 0;
}
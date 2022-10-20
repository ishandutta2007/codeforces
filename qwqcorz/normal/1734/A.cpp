#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=305;

int n,a[N];
void work() {
	cin>>n;
	for (int i=1;i<=n;i++) {
		cin>>a[i];
	}
	ll ans=1e18;
	sort(a+1,a+1+n);
	for (int i=1;i<=n;i++) {
		for (int j=i+1;j<=n;j++) {
			for (int k=j+1;k<=n;k++) {
				ans=min(ans,0LL+a[k]-a[i]);
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
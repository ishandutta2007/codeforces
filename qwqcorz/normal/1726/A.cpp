#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=2e3+5;

int n,a[N];
void work() {
	cin>>n;
	for (int i=1;i<=n;i++) {
		cin>>a[i];
	}
	int ans=a[n]-a[1];
	for (int i=1;i<n;i++) {
		ans=max(ans,a[n]-a[i]);
	}
	for (int i=2;i<=n;i++) {
		ans=max(ans,a[i]-a[1]);
	}
	for (int i=1;i<n;i++) {
		ans=max(ans,a[i]-a[i+1]);
	}
	cout<<ans<<"\n";
}

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	
	int T=1;
	cin>>T;
	while (T--) {
		work();
	} 
	
	return 0;
}
#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=105;

int n,a[N];
void work() {
	cin>>n;
	int mn=1e7+7;
	for (int i=1;i<=n;i++) {
		cin>>a[i];
		mn=min(mn,a[i]);
	}
	mn=mn*2-1;
	int ans=0;
	for (int i=1;i<=n;i++) {
		ans+=max((a[i]+mn-1)/mn-1,0);
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
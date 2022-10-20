#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=55;

int n,k,a[N];
void work() {
	cin>>n>>k;
	int l=n+1;
	for (int i=1;i<=n;i++) {
		cin>>a[i];
		if (a[i]==1) {
			l=min(l,i==1||i==n?2:3);
		}
	}
	for (int i=l;i<=n;i++) {
		if (i%(k-1)==1%(k-1)) {
			cout<<"YES\n";
			return;
		}
	}
	cout<<"NO\n";
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
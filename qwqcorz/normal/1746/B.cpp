#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=1e5+5;

int n,a[N],pre[N],suf[N];
void work() {
	cin>>n;
	for (int i=1;i<=n;i++) {
		cin>>a[i];
		pre[i]=pre[i-1]+a[i];
	}
	suf[n+1]=0;
	for (int i=n,tot=0;i>=1;i--) {
		if (a[i]) {
			suf[i]=suf[i+1]+tot;
			tot=0;
		} else {
			suf[i]=suf[i+1];
			tot++;
		}
	}
	int ans=n;
	for (int i=0;i<=n;i++) {
		if (pre[i]>=suf[i+1]) {
			ans=min(ans,pre[i]);
		}
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
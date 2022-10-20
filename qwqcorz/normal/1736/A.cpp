#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=105;

int n,a[N],b[N];
void work() {
	cin>>n;
	int cnt=0,tot=0;
	for (int i=1;i<=n;i++) {
		cin>>a[i];
		cnt+=a[i];
	}
	for (int i=1;i<=n;i++) {
		cin>>b[i];
		cnt-=b[i];
		tot+=a[i]^b[i];
	}
	cout<<min(tot,abs(cnt)+1)<<"\n";
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
#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=2e5+5;

int n,a[N],pre[N];
void work() {
	int sum=0;
	string s;
	cin>>n>>s;
	for (int i=1;i<=n;i++) {
		a[i]=s[i-1]=='1';
		sum+=a[i]?1:-1;
	}
	if (sum<0) {
		reverse(a+1,a+1+n);
		for (int i=1;i<=n;i++) {
			a[i]=!a[i];
		}
		sum=-sum;
	}
	int tot=0,len=0;
	for (int i=n;i>=1;i--) {
		if (i<n&&a[i]>a[i+1]) {
			break;
		}
		len++;
		tot+=a[i];
	}
	vector<int>pos(n+1);
	for (int i=1;i<=n;i++) {
		pre[i]=pre[i-1]+(a[i]?1:-1);
	}
	for (int i=n;i>=0;i--) {
		if (pre[i]>=0) {
			pos[pre[i]]=i;
		}
	}
	int ans=0;
	while (sum-tot>0) {
		int h=sum-tot;
		ans++;
		tot+=(n-tot-pos[h])/2;
		len=n-pos[h];
	}
	ans+=len<n;
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
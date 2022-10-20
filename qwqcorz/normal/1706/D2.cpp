#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=1e5+5;

int n,k,a[N],b[N];
vector<int>p[N];
void work() {
	int mn=1e5,ans=1e5;
	cin>>n>>k;
	for (int i=1;i<=n;i++) {
		cin>>a[i];
		b[i]=1;
		p[a[i]].emplace_back(i);
		mn=min(mn,a[i]);
	}
	for (int i=1e5;i>=0;i--) {
		ans=min(ans,i-mn);
		if (i==0) {
			break;
		}
		for (int j:p[i]) {
			b[j]=a[j]/(a[j]/b[j])+1;
			if (b[j]<=k) {
				p[a[j]/b[j]].emplace_back(j);
				mn=min(mn,a[j]/b[j]);
			} else {
				for (int t=i;t>=0;t--) {
					vector<int>().swap(p[t]);
				}
				cout<<ans<<"\n";
				return;
			}
		}
		vector<int>().swap(p[i]);
	}
	vector<int>().swap(p[0]);
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
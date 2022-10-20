#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=1e3+5;
const int K=25;

int n,k,a[N][K],deg[N];
void work() {
	cin>>n>>k;
	map<ll,int>mp;
	for (int i=1;i<=n;i++) {
		ll h=0;
		for (int j=1;j<=k;j++) {
			cin>>a[i][j];
			h=h*3+a[i][j];
		}
		mp[h]=i;
	}
	for (int i=1;i+2<=n;i++) {
		for (int j=i+1;j+1<=n;j++) {
			ll h=0;
			for (int t=1;t<=k;t++) {
				h=h*3+(a[i][t]==a[j][t]?a[i][t]:3^a[i][t]^a[j][t]);
			}
			if (mp.count(h)) {
				int x=mp[h];
				if (x<=j) {
					continue;
				}
				deg[i]++,deg[j]++,deg[x]++;
			}
		}
	}
	ll ans=0;
	for (int i=1;i<=n;i++) {
		ans+=1LL*deg[i]*(deg[i]-1)/2;
	}
	cout<<ans<<"\n";
}

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	
	int T=1;
//	cin>>T;
	while (T--) {
		work();
	}
	
	return 0;
}
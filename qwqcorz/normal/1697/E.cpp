#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=105;
const int mod=998244353;

bool vis[N];
int n,x[N],y[N],mn[N];
vector<int>e[N];
int dis(int i,int j) {
	return abs(x[i]-x[j])+abs(y[i]-y[j]);
}

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	
	cin>>n;
	for (int i=1;i<=n;i++) {
		cin>>x[i]>>y[i];
	}
	vector<int>a;
	for (int i=1;i<=n;i++) {
		mn[i]=1e9+7;
		for (int j=1;j<=n;j++) {
			if (i!=j&&dis(i,j)<=mn[i]) {
				if (dis(i,j)<mn[i]) {
					e[i].clear();
					mn[i]=dis(i,j);
				}
				e[i].emplace_back(j);
			}
		}
	}
	for (int i=1;i<=n;i++) {
		if (vis[i]) {
			continue;
		}
		bool ok=1;
		for (int x:e[i]) {
			if (vis[x]||e[x].size()!=e[i].size()||mn[x]!=mn[i]) {
				ok=0;
				break;
			}
			for (int y:e[i]) {
				if (x!=y&&dis(x,y)!=mn[i]) {
					ok=0;
					break;
				}
			}
			if (!ok) {
				break;
			}
		}
		if (ok) {
			vis[i]=1;
			for (int j:e[i]) {
				vis[j]=1;
			}
			a.emplace_back(e[i].size()+1);
		} else {
			vis[i]=1;
			a.emplace_back(1);
		}
	}
	vector<int>f({1});
	for (int i:a) {
		cerr<<i<<endl;
		vector<int>g(f.size()+i);
		for (int j=0;j<(int)f.size();j++) {
			g[j+1]=(g[j+1]+f[j])%mod;
			if (i>1) {
				g[j+i]=(g[j+i]+f[j])%mod;
			}
		}
		f.swap(g);
	}
	int ans=0,mul=1;
	for (int i=0;i<(int)f.size();i++) {
		ans=(ans+1LL*mul*f[i])%mod;
		mul=1LL*mul*(n-i)%mod;
	}
	cout<<ans<<"\n";
	
	return 0;
}
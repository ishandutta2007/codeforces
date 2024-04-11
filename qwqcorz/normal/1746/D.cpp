#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=2e5+5;

ll s[N];
int n,k,fa[N];
vector<int>e[N];
vector<ll>dfs(int now,int l,int r) {
	int m=e[now].size();
	vector<ll>ret;
	if (m==0) {
		for (int i=l;i<=r;i++) {
			ret.emplace_back(1LL*i*s[now]);
		}
		return ret;
	}
	vector<vector<ll>>a;
	a.reserve(m);
	for (int to:e[now]) {
		a.emplace_back(dfs(to,l/m,(r+m-1)/m));
	}
//	cerr<<now<<':'<<l<<' '<<r<<endl;
	int L=l/m;
	for (int i=l;i<=r;i++) {
		int tot=i%m;
		ll ans=1LL*i*s[now];
		vector<ll>tmp;
		for (int j=0;j<m;j++) {
			ans+=a[j][i/m-L];
			if (tot) {
				tmp.emplace_back(a[j][i/m-L+1]-a[j][i/m-L]);
			}
		}
		if (tot) {
			nth_element(tmp.begin(),tmp.begin()+tot,tmp.end(),greater<ll>());
			for (int j=0;j<tot;j++) {
				ans+=tmp[j];
			}
		}
		ret.emplace_back(ans);
//		cerr<<ans<<",\n"[i==r];
	}
	return ret;
}
void work() {
	cin>>n>>k;
	for (int i=2;i<=n;i++) {
		cin>>fa[i];
		e[fa[i]].emplace_back(i);
	}
	for (int i=1;i<=n;i++) {
		cin>>s[i];
	}
	auto ret=dfs(1,k,k);
	cout<<ret[0]<<"\n";
	for (int i=1;i<=n;i++) {
		e[i].clear();
	}
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
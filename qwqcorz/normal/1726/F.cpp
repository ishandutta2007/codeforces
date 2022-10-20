#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=2e5+5;

ll s[N],f[N];
int n,t,g[N],c[N],d[N],nxt[N];

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	
	cin>>n>>t;
	for (int i=1;i<=n;i++) {
		cin>>g[i]>>c[i];
	}
	vector<pair<int,int>>q;
	for (int i=1;i<n;i++) {
		cin>>d[i];
		s[i+1]=s[i]+d[i];
		q.emplace_back((s[i]+c[i])%t,i);
	}
	for (int i=1;i<=n;i++) {
		q.emplace_back((t-(t-c[i]-s[i])%t)%t,0);
		q.emplace_back((t-(t-c[i]+g[i]-1-s[i])%t)%t,0);
	}
	multiset<int>S;
	sort(q.begin(),q.end());
	for (int i=1;i<=n;i++) {
		S.insert(i);
	}
	set<pair<int,int>>ins,era;
	for (int i=1;i<n;i++) {
		int r=(s[i]+c[i])%t;
		if (r-g[i]+1>=0) {
			ins.insert({r-g[i]+1,i});
			era.insert({r,i});
		} else {
			ins.insert({0,i});
			era.insert({r,i});
			ins.insert({(r-g[i]+1+t)%t,i});
		}
	}
	vector<pair<int,int>>b;
	for (auto [T,id]:q) {
		while (era.size()&&era.begin()->first<T) {
			S.insert(era.begin()->second);
			era.erase(era.begin());
		}
		while (ins.size()&&ins.begin()->first<=T) {
			S.erase(S.find(ins.begin()->second));
			ins.erase(ins.begin());
		}
		if (id) {
			nxt[id]=*S.upper_bound(id);
		} else {
			b.emplace_back(T,*S.upper_bound(id));
		}
	}
	for (int i=n-1;i>=1;i--) {
		int j=nxt[i];
		int tim=(c[j]+s[j]-s[i]-c[i]+2LL*t)%t;
		f[i]=f[j]+(tim<g[j]?0:t-tim);
	}
	ll ans=1e18;
	for (auto [T,j]:b) {
		int tim=(1LL*t-T+c[j]+s[j])%t;
		ans=min(ans,f[j]+(tim<g[j]?0:t-tim));
	}
	cout<<ans+s[n]<<"\n";
	
	return 0;
}
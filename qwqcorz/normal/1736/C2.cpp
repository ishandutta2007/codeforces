#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=2e5+5;

ll sum[N];
int n,a[N],r1[N],r2[N];
vector<int>p[N],pos[N];
vector<ll>s2[N];
void work() {
	cin>>n;
	for (int i=1;i<=n+1;i++) {
		p[i].clear(),pos[i].clear(),s2[i].clear();
	}
	for (int i=1;i<=n;i++) {
		cin>>a[i];
		p[max(i-a[i]+1,1)].emplace_back(i);
	}
	ll ans=0;
	set<int>S;
	for (int i=1;i<=n;i++) {
		S.insert(i);
	}
	for (int i=1;i<=n;i++) {
		for (int j:p[i]) {
			S.erase(j);
		}
		auto now=S.lower_bound(i);
		if (now!=S.end()) {
			r1[i]=*now;
		} else {
			r1[i]=n+1;
		}
		ans+=r1[i]-i;
		auto nxt=S.upper_bound(*now);
		if (nxt!=S.end()) {
			r2[i]=*nxt;
		} else {
			r2[i]=n+1;
		}
		sum[i]=sum[i-1]+r1[i];
		pos[r1[i]].emplace_back(i);
		s2[r1[i]].emplace_back(r2[i]-r1[i]);
	}
	for (int i=1;i<=n;i++) {
		for (int j=1;j<(int)s2[i].size();j++) {
			s2[i][j]+=s2[i][j-1];
		}
	}
	int Q;
	cin>>Q;
	for (int i=1;i<=Q;i++) {
		int x,y;
		cin>>x>>y;
		int u=max(x-a[x]+1,1),v=max(x-y+1,1);
		if (u==v) {
			cout<<ans<<"\n";
		}
		if (u<v) {
			int pos=lower_bound(r1+u,r1+v,x)-r1;
			ll now=ans-(sum[v-1]-sum[pos-1]-1LL*x*(v-pos));
			cout<<now<<"\n";
		}
		if (v<u) {
			int l=lower_bound(pos[x].begin(),pos[x].end(),v)-pos[x].begin()-1;
			int r=lower_bound(pos[x].begin(),pos[x].end(),u)-pos[x].begin()-1;
			if (l>=r) {
				cout<<ans<<"\n";
				continue;
			}
			ll now=ans+s2[x][r]-(l>=0?s2[x][l]:0);
			cout<<now<<"\n";
		}
	}
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
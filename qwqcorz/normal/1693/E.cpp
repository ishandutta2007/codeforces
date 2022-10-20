#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=2e5+5;

struct bit {
	int n,t[N];
	void send(int _n) {
		n=_n,memset(t,0,sizeof(t));
	}
	void add(int x) {
		for (;x<=n;x+=x&-x) {
			t[x]++;
		}
	}
	int query(int x) {
		int ret=0;
		for (;x;x&=x-1) {
			ret+=t[x];
		}
		return ret;
	}
	int query(int l,int r) {
		return query(r)-query(l-1);
	}
}t;
int n,a[N];
vector<int>pos[N];

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	
	cin>>n;
	for (int i=1;i<=n;i++) {
		cin>>a[i];
		pos[a[i]].emplace_back(i);
	}
	t.send(n);
	ll ans=0;
	int L=0,R=n+1;
	for (int i=n;i>=1;i--) {
		if (pos[i].empty()) {
			continue;
		}
		int l=pos[i][0],r=pos[i].back();
		r=max(r,L-1);
		l=min(l,R+1);
		for (int j:pos[i]) {
			t.add(j);
		}
		ans+=t.query(l,r);
		L=l,R=r;
	}
	cout<<ans<<"\n";
	
	return 0;
}
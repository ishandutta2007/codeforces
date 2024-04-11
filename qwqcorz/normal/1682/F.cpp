#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=2e5+5;
const int mod=1e9+7;

void Add(int &x,int y) {
	x+=y;
	if (x>=mod) {
		x-=mod;
	}
}
struct bit {
	int n,t[N];
	void send(int _n) {
		n=_n,memset(t,0,sizeof(t));
	}
	void add(int x,int y) {
		for (;x<=n;x+=x&-x) {
			Add(t[x],y);
		}
	}
	int query(int x) {
		int ret=0;
		for (;x;x&=x-1) {
			Add(ret,t[x]);
		}
		return ret;
	}
	int query(int l,int r) {
		if (l>r) {
			return 0;
		}
		return (query(r)-query(l-1)+mod)%mod;
	}
}t0,t1;
int n,Q,a[N],b[N],p[N],ans[N];
ll pre[N],c[N];

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	
	cin>>n>>Q;
	for (int i=1;i<=n;i++) {
		cin>>a[i];
	}
	for (int i=1;i<=n;i++) {
		cin>>b[i];
		c[i]=pre[i]=pre[i-1]+b[i];
	}
	sort(c+1,c+2+n);
	int cnt=unique(c+1,c+2+n)-c-1;
	for (int i=1;i<=cnt;i++) {
	}
	for (int i=0;i<=n;i++) {
		p[i]=lower_bound(c+1,c+1+cnt,pre[i])-c;
	}
	t0.send(cnt),t1.send(cnt);
	for (int i=n-1;i>=1;i--) {
		t0.add(p[i],a[i+1]-a[i]),t1.add(p[i],(1LL*(a[i+1]-a[i])*(pre[i]%mod)%mod+mod)%mod);
		ans[i]=(
			t1.query(p[i-1]+1,cnt)-1LL*t0.query(p[i-1]+1,cnt)*(pre[i-1]%mod)%mod+
			1LL*t0.query(1,p[i-1]-1)*(pre[i-1]%mod)%mod-t1.query(1,p[i-1]-1)+mod+mod+mod
		)%mod;
	}
	while (Q--) {
		int l,r;
		cin>>l>>r;
		cout<<(ans[l]-ans[r+1]+mod)%mod<<"\n";
	} 
	
	return 0;
}
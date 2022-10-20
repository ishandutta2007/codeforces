#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=5e5+5;
const int M=1e6+5;

struct dsu {
	int fa[N],l[N],r[N];
	void send(int n) {
		for (int i=1;i<=n;i++) {
			fa[i]=l[i]=r[i]=i;
		}
	}
	int find(int x) {
		return x==fa[x]?x:fa[x]=find(fa[x]);
	}
	void merge(int x,int y) {
		x=find(x),y=find(y);
		fa[x]=y;
		l[y]=min(l[x],l[y]);
		r[y]=max(r[x],r[y]);
	}
}d;
bool vis[N];
int n,a[N],l[N],r[N],st[N];
vector<int>p[M];
void work() {
	cin>>n;
	for (int i=1;i<=n;i++) {
		cin>>a[i];
		p[a[i]].emplace_back(i);
	}
	int top=0;
	st[top]=0;
	for (int i=1;i<=n;i++) {
		while (top&&a[st[top]]<a[i]) {
			top--;
		}
		l[i]=st[top]+1;
		st[++top]=i;
	}
	st[top=0]=n+1;
	for (int i=n;i>=1;i--) {
		while (top&&a[st[top]]<=a[i]) {
			top--;
		}
		r[i]=st[top]-1;
		st[++top]=i;
	}
	ll ans=0;
	d.send(n);
	for (int i=1e6;i>=1;i--) {
		for (int j:p[i]) {
			vis[j]=1;
			if (vis[j-1]) {
				d.merge(j,j-1);
			}
			if (vis[j+1]) {
				d.merge(j,j+1);
			}
		}
		for (int j=i;j<=1e6;j+=i) {
			for (int k:p[j]) {
				int x=d.find(k);
				int L=max(d.l[x],l[k]),R=min(d.r[x],r[k]);
				ans+=1LL*(k-L+1)*(R-k+1);
			}
		}
		if (i>1) {
			for (int j=i-1+i-1;j<=1e6;j+=i-1) {
				for (int k:p[j]) {
					int x=d.find(k);
					int L=max(d.l[x],l[k]),R=min(d.r[x],r[k]);
					ans-=1LL*(k-L+1)*(R-k+1);
				}
			}
		}
	}
	cout<<ans<<"\n";
	for (int i=1;i<=n;i++) {
		p[a[i]].clear();
		vis[i]=0;
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
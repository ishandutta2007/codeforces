#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=1e6+5;
const int inf=1e9+7;

int n,d[N];
vector<int>e[N];
void dfs0(int now,int father) {
	d[now]=N;
	for (int to:e[now]) {
		if (to==father) {
			continue;
		}
		dfs0(to,now);
		d[now]=min(d[now],d[to]+1);
	}
	if (d[now]==N) {
		d[now]=0;
	}
}
void dfs1(int now,int father,int w) {
	d[now]=min(d[now],w);
	int mn1=N,mn2=N;
	for (int to:e[now]) {
		if (to==father) {
			continue;
		}
		if (d[to]<mn1) {
			mn2=mn1,mn1=d[to];
		} else {
			if (d[to]<mn2) {
				mn2=d[to];
			}
		}
	}
	for (int to:e[now]) {
		if (to==father) {
			continue;
		}
		dfs1(to,now,min(w,(d[to]==mn1?mn2:mn1)+1)+1);
	}
}
int rt,siz[N],mx[N];
bool vis[N];
int ans[N],deep[N];
void findroot(int now,int father,int n) {
	siz[now]=1,mx[now]=0;
	for (int to:e[now]) {
		if (to==father||vis[to]) {
			continue;
		}
		findroot(to,now,n);
		siz[now]+=siz[to];
		mx[now]=max(mx[now],siz[to]);
	}
	mx[now]=max(mx[now],n-siz[now]);
	if (mx[now]<=n/2) {
		rt=now;
	}
}
int dfs(int now,int father,vector<pair<int,int>>&v) {
	int len=1;
	v.emplace_back(deep[now]=deep[father]+1,d[now]);
	for (int to:e[now]) {
		if (to==father||vis[to]) {
			continue;
		}
		len=max(len,dfs(to,now,v)+1);
	}
	return len;
}
struct cmp {
	bool operator ()(const vector<int>&a,const vector<int>&b) {
		return a.size()>b.size();
	}
};
void dfz(int now,int tot) {
	rt=0,findroot(now,0,tot),findroot(rt,0,tot);
	int x=rt;
	vis[x]=1,deep[x]=0;
	priority_queue<vector<int>,vector<vector<int>>,cmp>q;
	for (int to:e[x]) {
		if (vis[to]) {
			continue;
		}
		vector<pair<int,int>>v;
		int len=dfs(to,x,v);
		vector<int>a(len+1,-inf);
		a[0]=d[x];
		for (auto [x,y]:v) {
			a[x]=max(a[x],y);
		}
		for (int i=len;i>=1;i--) {
			a[i-1]=max(a[i-1],a[i]);
		}
		q.push(a);
	}
	while (q.size()>1) {
		auto A=q.top(); q.pop();
		auto B=q.top(); q.pop();
		vector<pair<int,int>>a,b;
		for (int i=0;i+1<(int)A.size();i++) {
			if (!i||(A[i]==A[i-1]&&A[i+1]!=A[i])) {
				a.emplace_back(i,A[i]);
			}
		}
		for (int i=0;i+1<(int)B.size();i++) {
			if (!i||(B[i]==B[i-1]&&B[i+1]!=B[i])) {
				b.emplace_back(i,B[i]);
			}
		}
		vector<int>c(A.size()+B.size()-1,-inf);
		for (auto [x1,y1]:a) {
			for (auto [x2,y2]:b) {
				c[x1+x2]=max(c[x1+x2],y1+y2);
			}
		}
		for (int i=1;i<(int)c.size();i++) {
			c[i]=max(c[i],c[i-1]-1);
		}
		for (int i=(int)c.size()-1,mx=-inf;i>=0;i--) {
			mx=max(mx,c[i]);
			ans[i]=min(ans[i],max(i-mx,0));
		}
		int n=max(A.size(),B.size());
		vector<int>C(n);
		for (int i=0;i<(int)A.size();i++) {
			C[i]=max(C[i],A[i]);
		}
		for (int i=0;i<(int)B.size();i++) {
			C[i]=max(C[i],B[i]);
		}
		q.push(C);
	}
	for (int to:e[x]) {
		if (vis[to]) {
			continue;
		}
		dfz(to,siz[to]);
	}
}

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	
	cin>>n;
	for (int i=2;i<=n;i++) {
		int fa;
		cin>>fa;
		e[i].emplace_back(fa);
		e[fa].emplace_back(i);
	}
	dfs0(1,0);
	dfs1(1,0,e[1].size()==1?0:N);
	memset(ans,0x3f,sizeof(ans));
	dfz(1,n);
	int Q;
	cin>>Q;
	while (Q--) {
		int x;
		cin>>x;
		int p=upper_bound(ans,ans+n+1,x)-ans-1;
		cout<<p<<" \n"[!Q];
	}
	
	return 0;
}
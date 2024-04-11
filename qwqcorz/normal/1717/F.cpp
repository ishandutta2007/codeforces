#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=1e4+5;

namespace Flow {
	const int V=N;
	const int E=N*6;
	const int inf=1e9+7;
	struct edge {
		int to,nxt,val;
	}e[E*2];
	int head[V],cur[V],cnte;
	int add_edge(int u,int v,int w) {
		e[++cnte].to=v;
		e[cnte].val=w;
		e[cnte].nxt=head[u];
		head[u]=cnte;
		return cnte;
	}
	int add(int u,int v,int w) {
//		cerr<<u<<' '<<v<<' '<<w<<endl;
		add_edge(u,v,w);
		return add_edge(v,u,0);
	}
	int n,S,T;
	void send(int _n,int _S,int _T) {
		n=_n,S=_S,T=_T,cnte=1;
		for (int i=0;i<=n;i++) {
			head[i]=0;
		}
	}
	int deep[V];
	bool bfs() {
		for (int i=0;i<=n;i++) {
			deep[i]=-1;
			cur[i]=head[i];
		}
		queue<int>q;
		q.push(S),deep[S]=0;
		while (!q.empty()) {
			int now=q.front(); q.pop();
			for (int i=head[now];i;i=e[i].nxt) {
				int to=e[i].to,val=e[i].val;
				if (!val||~deep[to]) {
					continue;
				}
				deep[to]=deep[now]+1;
				q.push(to);
			}
		}
		return ~deep[T];
	}
	int dfs(int now,int flow) {
		if (!flow||now==T) {
			return flow;
		}
		int ret=0;
		for (int i=cur[now];i;cur[now]=i=e[i].nxt) {
			int to=e[i].to,val=e[i].val;
			if (!val||deep[to]!=deep[now]+1) {
				continue;
			}
			int tmp=dfs(to,min(flow,val));
			e[i].val-=tmp,e[i^1].val+=tmp;
			flow-=tmp,ret+=tmp;
			if (!flow) {
				return ret;
			}
		}
		return ret;
	}
	int solve() {
		int ret=0;
		while (bfs()) {
			ret+=dfs(S,inf);
		}
		return ret;
	}
}
struct edge {
	int u,v,w;
	edge(int a=0,int b=0,int c=0) {
		u=a,v=b,w=c;
	}
};
vector<edge>e;
int n,m,s[N],a[N],deg[N],d[N];
bool getans(int n,vector<edge>&e) {
	int S=n+1,T=n+2,cnt=0;
	Flow::send(T,S,T);
	vector<int>id(e.size());
	for (auto [u,v,w]:e) {
		d[u]--,d[v]++;
		if (!w) {
			id[cnt]=Flow::add(v,u,1);
		}
		cnt++;
	}
	int all=0;
	for (int i=0;i<=n;i++) {
		if (d[i]&1) {
			return 0;
		}
		d[i]/=2;
		if (d[i]>0) {
			all+=d[i];
			Flow::add(S,i,d[i]);
		}
		if (d[i]<0) {
			Flow::add(i,T,-d[i]);
		}
	}
	int f=Flow::solve();
	if (all==f) {
		for (int i=0;i<(int)e.size();i++) {
			if (!e[i].w&&Flow::e[id[i]].val) {
				swap(e[i].u,e[i].v);
			}
		}
		return 1;
	} else {
		return 0;
	}
}

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	
	cin>>n>>m;
	for (int i=1;i<=n;i++) {
		cin>>s[i];
	}
	for (int i=1;i<=n;i++) {
		cin>>a[i];
	}
	for (int i=1;i<=m;i++) {
		int u,v;
		cin>>u>>v;
		e.emplace_back(u,v,0);
		deg[u]++,deg[v]++;
	}
	for (int i=1;i<=n;i++) {
		if (s[i]) {
			if (abs(a[i])>deg[i]||(deg[i]&1)!=(abs(a[i])&1)) {
				cout<<"NO\n";
				return 0;
			}
			if (a[i]>0) {
				for (int j=1;j<=a[i];j++) {
					e.emplace_back(i,0,1);
				}
			} else {
				for (int j=1;j<=-a[i];j++) {
					e.emplace_back(0,i,1);
				}
			}
		} else {
			for (int j=1;j<=deg[i];j++) {
				e.emplace_back(0,i,0);
			}
		}
	}
//	for (auto [u,v,w]:e) {
//		cout<<u<<','<<v<<' '<<w<<endl;
//	}
	if (getans(n,e)) {
		cout<<"YES\n";
		for (auto [u,v,w]:e) {
			if (!u||!v) {
				continue;
			}
			cout<<u<<' '<<v<<"\n";
		}
	} else {
		cout<<"NO\n";
	}
	
	return 0;
}
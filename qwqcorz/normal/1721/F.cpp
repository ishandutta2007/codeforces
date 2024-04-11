#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=2e5+5;

namespace Flow {
	const int V=N*2;
	const int E=N*3;
	const ll inf=1e18+7;
	struct edge {
		int to,nxt;
		ll val;
	}e[E*2];
	int head[V],cur[V],cnte;
	int add_edge(int u,int v,ll w) {
		e[++cnte].to=v;
		e[cnte].val=w;
		e[cnte].nxt=head[u];
		head[u]=cnte;
		return cnte;
	}
	int add(int u,int v,ll w) {
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
				int to=e[i].to;
				ll val=e[i].val;
				if (!val||~deep[to]) {
					continue;
				}
				deep[to]=deep[now]+1;
				q.push(to);
			}
		}
		return ~deep[T];
	}
	ll dfs(int now,ll flow) {
		if (!flow||now==T) {
			return flow;
		}
		ll ret=0;
		for (int i=cur[now];i;cur[now]=i=e[i].nxt) {
			int to=e[i].to;
			ll val=e[i].val;
			if (!val||deep[to]!=deep[now]+1) {
				continue;
			}
			ll tmp=dfs(to,min(flow,val));
			e[i].val-=tmp,e[i^1].val+=tmp;
			flow-=tmp,ret+=tmp;
			if (!flow) {
				return ret;
			}
		}
		return ret;
	}
	ll solve() {
		ll ret=0;
		while (bfs()) {
			ret+=dfs(S,inf);
		}
		return ret;
	}
	vector<pair<int,int>>getcut() {
		vector<pair<int,int>>ret;
		for (int u=0;u<=n;u++) {
			for (int i=head[u];i;i=e[i].nxt) {
				int v=e[i].to;
				ll val=e[i^1].val;
				if (u>v||!val||(deep[u]==-1)==(deep[v]==-1)) {
					continue;
				}
				ret.emplace_back(u,v);
			}
		}
		return ret;
	}
}
pair<int,int>e[N];
int id[N],val[N+N];

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	
	int n1=1,n2=2e5,m=2e5,Q=2e5;
	cin>>n1>>n2>>m>>Q;
	int S=0,T=n1+n2+1;
	Flow::send(T,S,T);
	for (int i=1;i<=n1;i++) {
		Flow::add(S,i,1);
	}
	for (int i=1;i<=n2;i++) {
		Flow::add(n1+i,T,1);
	}
	for (int i=1;i<=m;i++) {
		int u=1,v=i;
		cin>>u>>v;
		e[i]={u,v};
		id[i]=Flow::add(u,n1+v,Flow::inf);
	}
	int f=Flow::solve();
//	cerr<<":"<<f<<endl;
	auto E=Flow::getcut();
	ll sum=0;
	vector<int>p;
	for (int i=1;i<=m;i++) {
		if (Flow::e[id[i]].val) {
			auto [u,v]=e[i];
			sum+=i,val[u]=val[n1+v]=i;
			p.emplace_back(i);
//			cerr<<u<<' '<<v<<endl;
		}
	}
	vector<int>c;
	for (auto [u,v]:E) {
//		cerr<<u<<','<<v<<endl;
		if (u!=S&&u!=T) {
			c.push_back(u);
		}
		if (v!=S&&v!=T) {
			c.push_back(v);
		}
	}
	while (Q--) {
		int opt;
		cin>>opt;
		if (opt==1) {
			int x=c.back();
			sum-=val[x],val[x]=0;
			x=x<=n1?x:-(x-n1);
			c.pop_back();
			cout<<"1\n"<<x<<"\n"<<sum<<endl;
		} else {
			vector<int>ans;
			for (int i:p) {
				auto [u,v]=e[i];
				if (val[u]&&val[n1+v]) {
					ans.emplace_back(i);
				}
			}
			cout<<ans.size()<<"\n";
			for (int i:ans) {
				cout<<i<<" ";
			}
			cout<<endl;
		}
//		cerr<<"==="<<endl;
	}
	
	return 0;
}
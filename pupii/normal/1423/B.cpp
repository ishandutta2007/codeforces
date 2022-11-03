#include<bits/stdc++.h>
using namespace std;
const int N=1e6+10;
const int inf=1e9;

int to[N],ww[N],nxt[N],tt=1,s,t,h[N],cur[N],dep[N],u[N],v[N],d[N],st[N],tp,m,n;

void adde(int u,int v,int w) {
	to[++tt]=v;ww[tt]=w;nxt[tt]=h[u];h[u]=tt;
	to[++tt]=u;ww[tt]=0;nxt[tt]=h[v];h[v]=tt;
}

bool bfs() {
	memset(dep,0,4*(t+1));
	queue<int> q;q.push(s);dep[s]=1;
	while(!q.empty()) {
		int u=q.front();q.pop();
		for(int i=h[u],v;v=to[i],i;i=nxt[i])
			if(!dep[v]&&ww[i]) {
				dep[v]=dep[u]+1;q.push(v);
				if(v==t) return 1;
			}
	}
	return 0;
}

int dfs(int u,int flow) {
	if(u==t) return flow;
	int ret=0;
	for(int &i=cur[u],v;v=to[i],i;i=nxt[i])
		if(dep[v]==dep[u]+1&&ww[i]) {
			int d=dfs(v,min(flow,ww[i]));
			ww[i]-=d;ww[i^1]+=d;ret+=d;flow-=d;
			if(!flow) break;
		}
	return ret;
}

int dinic() {
	int ret=0;
	while(bfs()) {
		memcpy(cur,h,4*(t+1));
		ret+=dfs(s,inf);
	}
	return ret;
}

bool check(int mid) {
	tt=1;memset(h,0,4*(t+1));
	for(int i=1;i<=n;i++) adde(s,i,1),adde(i+n,t,1);
	for(int i=1;i<=m;i++)
		if(d[i]<=mid) adde(u[i],v[i]+n,1);
	return dinic()==n;
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("a.in","r",stdin);
	freopen("a.out","w",stdout);
#endif
	ios::sync_with_stdio(0);cin.tie(0);
	cin>>n>>m;
	s=0;t=n+n+1;
	for(int i=1;i<=m;i++) cin>>u[i]>>v[i]>>d[i],st[++tp]=d[i];
	sort(st+1,st+tp+1);
	tp=unique(st+1,st+tp+1)-st-1;
	int l=1,r=tp+1;
	while(l<r) {
		int mid=(l+r)>>1;
		if(check(st[mid])) r=mid;
		else l=mid+1;
	}
	if(l==tp+1) cout<<-1;
	else cout<<st[l];
	return 0;
}
#include<bits/stdc++.h>

using namespace std;

struct node{
	int id,dep,val;
	node(int ii=0,int dd=0,int vv=0):id(ii),dep(dd),val(vv){}
	bool operator>(const node comp)const{
		if(dep==comp.dep)
			return val>comp.val;
		return dep>comp.dep;
	}
}d[200005];

int n,tot=0;
int a[200005],dep[200005],v[400005],next[400005],h[200005],f[200005],ans[200005],q[200005];
bool vis[200005];
priority_queue<node,vector<node>,greater<node> > q1;

void addedge(int x,int y){
	v[++tot]=y; next[tot]=h[x]; h[x]=tot;
	v[++tot]=x; next[tot]=h[y]; h[y]=tot;
}

void dfs(int u,int fa){
	for(int p=h[u];p;p=next[p]){
		if(v[p]==fa)
			continue;
		d[v[p]].dep=d[u].dep+1;
		f[v[p]]=u;
		dfs(v[p],u);
	}
}

void bfs(){
	memset(vis,false,sizeof(vis));
	int front=0,rear=0;
	q[rear++]=1;
	vis[1]=true;
	for(int i=1;i<=n;i++){
		ans[i]=q[front++];
		for(int p=h[ans[i]];p;p=next[p])
			if(!vis[v[p]])
				q1.push(d[v[p]]),vis[v[p]]=true;
		while(!q1.empty())
			q[rear++]=q1.top().id,q1.pop();
	}
}

int main(){
	cin>>n;
	int x,y;
	for(int i=1;i<=n-1;i++){
		cin>>x>>y;
		addedge(x,y);
	}
	for(int i=1;i<=n;i++)
		d[i].id=i;
	d[1].dep=1;
	dfs(1,-1);
	for(int i=1;i<=n;i++){
		cin>>a[i];
		d[a[i]].val=i;
		if(vis[a[i]]){
			cout<<"No"<<endl;
			return 0;
		}
		vis[a[i]]=true;
	}
	bfs();
	for(int i=1;i<=n;i++){
		if(ans[i]!=a[i]){
			cout<<"No"<<endl;
			return 0;
		}
	}
	cout<<"Yes"<<endl;
	return 0;
}
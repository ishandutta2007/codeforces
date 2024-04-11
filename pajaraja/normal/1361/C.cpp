#include <bits/stdc++.h>
#define MAXN 1000007
#define MAXT 5000007
#define MAXL 23
using namespace std;
int cx,l[MAXT],r[MAXT],f[MAXT],cnt=1,dsu[MAXN],sz[MAXN],val[MAXN],lok[MAXN];
vector<int> v[MAXT],a[MAXL];
set<int> g[2*MAXN];
stack<int> st;
void add(int x,int ind,int d)
{
	if(d==20) {v[ind].push_back(x); return;} 
	if(val[x]&(1<<d))
	{
		if(!r[ind]) {r[ind]=++cnt; a[d+1].push_back(r[ind]); f[r[ind]]=ind;}
		add(x,r[ind],d+1);
	}
	else
	{
		if(!l[ind]) {l[ind]=++cnt; a[d+1].push_back(l[ind]); f[l[ind]]=ind;}
		add(x,l[ind],d+1);
	}
}
int root(int u)
{
	while(dsu[u]!=u)
	{
		dsu[u]=dsu[dsu[u]];
		u=dsu[u];
	}
	return u;
}
void connect(int u,int v)
{
	int a=root(u),b=root(v);
	if(a==b) return;
	sz[a]+=sz[b];
	dsu[b]=a;
}
void euler(int s)
{
	while(!g[s].empty())
	{
		int t=*g[s].begin();
		g[s].erase(t);
		g[t].erase(s);
		euler(t);
	}
	st.push(s);
}
int main()
{
	int n; scanf("%d",&n);
	for(int i=1;i<2*n;i+=2) scanf("%d%d",&val[i],&val[i+1]);
	for(int i=1;i<=2*n;i++) dsu[i]=i; 
	for(int i=1;i<=2*n;i++) sz[i]=1; 
	for(int i=1;i<2*n;i+=2) {connect(i,i+1); add(i,1,0); add(i+1,1,0); g[i].insert(i+1); g[i+1].insert(i);}
	a[0].push_back(1);
	for(int i=0;i<a[20].size();i++) for(int j=0;j+1<v[a[20][i]].size();j++) connect(v[a[20][i]][j],v[a[20][i]][j+1]);
	for(int rs=20;rs>=0;rs--)
	{
		bool svp=true;
		for(int i=0;i<a[rs].size();i++)
		{
			int x=a[rs][i];
			if(l[x] && r[x]) connect(v[l[x]][0],v[r[x]][0]);
			if(l[x]) {for(int j=0;j<v[l[x]].size();j++) v[x].push_back(v[l[x]][j]); v[l[x]].clear();}
			if(r[x]) {for(int j=0;j<v[r[x]].size();j++) v[x].push_back(v[r[x]][j]); v[r[x]].clear();}
			if(v[x].size()&1) svp=false; 
		}
		if(!svp || sz[root(1)]!=2*n) continue;
		printf("%d\n",rs);
		for(int i=0;i<a[rs].size();i++)
		{
			int x=a[rs][i];
			for(int j=0;j<v[x].size();j++) {g[v[x][j]].insert(2*n+1+i); g[2*n+1+i].insert(v[x][j]);}
		}
		euler(1);
		while(st.size()!=1)
		{
			int u=st.top();
			st.pop();
			if(u<=2*n) printf("%d ",u);
		}
		return 0;
	}
}
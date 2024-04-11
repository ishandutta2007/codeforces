#include <bits/stdc++.h>
using namespace std;
const int N=201010;
int p[N],ord[N],clk,par[N],cur[N],a[N];
vector<int> adj[N],vs[N],q[N];
pair<int,int> ans[N];
void dfs(int u){
	ord[u]=clk++;
	for(auto &x:adj[u]){
		if(x==par[u])continue;
		par[x]=u;
		dfs(x);
	}
}
int main(){
	p[0]=p[1]=1;
	for(int i=2;i<N;i++){
		if(p[i])continue;
		for(int j=i+i;j<N;j+=i)p[j]=1;
	}
	int n;scanf("%d",&n);
	for(int i=0;i<n;i++){
		int x;scanf("%d",&x);
		a[i]=x;
		vs[x].push_back(i);
	}
	for(int i=2;i<N;i++){
		if(p[i])continue;
		for(int j=i;j<N;j+=i)for(auto &x:vs[j])q[i].push_back(x);
	}
	for(int i=1;i<n;i++){
		int u,v;scanf("%d%d",&u,&v);u--;v--;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}
	par[0]=-1;
	dfs(0);
	int dap=-1;
	for(int i=2;i<N;i++){
		if(p[i])continue;
		if(q[i].empty())continue;
		sort(q[i].begin(),q[i].end(),[](int i,int j){return ord[i]>ord[j];});
		for(auto &x:q[i]){
			if(cur[x]!=i){
				cur[x]=i;
				ans[x]={0,0};
			}
			dap=max(dap,ans[x].first+ans[x].second);
			if(par[x]>=0&&a[par[x]]%i==0){
				if(cur[par[x]]!=i){
					cur[par[x]]=i;
					ans[par[x]]={0,0};
				}
				int D=ans[x].first+1;
				if(D>ans[par[x]].first){
					ans[par[x]].second=ans[par[x]].first;
					ans[par[x]].first=D;
				}
				else if(D>ans[par[x]].second){
					ans[par[x]].second=D;
				}
			}
		}
	}
	printf("%d\n",dap+1);
}
#include <bits/stdc++.h>
using namespace std;
const int N=101010;
vector<int> adj[N];
int rnk[N],par[N];
void dfs(int u,int p=-1){
	par[u]=p;
	for(auto &x:adj[u]){
		if(x==p)continue;
		rnk[x]=rnk[u]+1;
		dfs(x,u);
	}
}
int main(){
	int n,k;scanf("%d%d",&n,&k);
	for(int i=1;i<n;i++){
		int u,v;scanf("%d%d",&u,&v);
		u--;v--;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}
	dfs(0);
	int x=max_element(rnk,rnk+n)-rnk;
	rnk[x]=0;
	dfs(x);
	x=max_element(rnk,rnk+n)-rnk;
	if(rnk[x]!=k+k)return puts("No"),0;
	for(int i=0;i<k;i++)x=par[x];
	rnk[x]=0;
	dfs(x);
	for(int i=0;i<n;i++){
		int chc=adj[i].size();if(i!=x)chc--;
		if(chc==0&&rnk[i]!=k)return puts("No"),0;
		if(chc>0&&chc<3)return puts("No"),0;
	}
	puts("Yes");
}
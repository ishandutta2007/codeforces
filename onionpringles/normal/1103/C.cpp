#include <bits/stdc++.h>
using namespace std;
const int N=301010;
vector<int> adj[N],adj2[N],lf;
int rnk[N],par[N],chk[N];
void dfs(int u){
	chk[u]=1;
	int cnt=0;
	for(auto &x:adj[u]){
		if(chk[x])continue;
		par[x]=u;
		rnk[x]=rnk[u]+1;
		dfs(x);
		cnt++;
	}
	if(cnt==0)lf.push_back(u);
}
int rnk2[N],par2[N];
void dfs2(int u){
	for(auto &x:adj2[u]){
		if(x==par2[u])continue;
		par2[x]=u;
		rnk2[x]=rnk2[u]+1;
		dfs2(x);
	}
}
int L;
void diam(int n){
	for(int i=1;i<n;i++){
		adj2[i].push_back(par[i]);
		adj2[par[i]].push_back(i);
	}
	int s=max_element(rnk,rnk+n)-rnk;
	par2[s]=-1;
	dfs2(s);
	int e=max_element(rnk2,rnk2+n)-rnk2;
	if(rnk2[e]>=L){
		puts("PATH");
		printf("%d\n",rnk2[e]+1);
		while(e!=s){
			printf("%d ",e+1);e=par2[e];
		}
		printf("%d\n",s+1);
		exit(0);
	}
}
int main(){
	int n,m,k;scanf("%d%d%d",&n,&m,&k);
	L=(n-1)/k;
	for(int i=0;i<m;i++){
		int u,v;scanf("%d%d",&u,&v);
		u--;v--;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}
	par[0]=-1;
	dfs(0);
	diam(n);
	puts("CYCLES");
	for(int i=0;i<k;i++){
		int u=lf[i];
		vector<int> vs;
		for(auto &x:adj[u]){
			if(x==par[u])continue;
			vs.push_back(x);
			if(vs.size()==2)break;
		}
		int v1=vs[0],v2=vs[1];
		if((rnk[u]-rnk[v1]+1)%3!=0){			
			printf("%d\n",rnk[u]-rnk[v1]+1);
			while(u!=v1){
				printf("%d ",u+1);u=par[u];
			}
			printf("%d\n",v1+1);
		}
		else if((rnk[u]-rnk[v2]+1)%3!=0){			
			printf("%d\n",rnk[u]-rnk[v2]+1);
			while(u!=v2){
				printf("%d ",u+1);u=par[u];
			}
			printf("%d\n",v2+1);
		}
		else{
			if(rnk[v1]<rnk[v2])swap(v1,v2);
			printf("%d\n",rnk[v1]-rnk[v2]+2);
			printf("%d ",u+1);
			while(v1!=v2)printf("%d ",v1+1),v1=par[v1];
			printf("%d\n",v2+1);
		}
	}
	return 0;

}
#include<bits/stdc++.h>
#define N 200010
using namespace std;
int n,i,x,y,S,T,dad[N],a[N],m,vis[N],tot,ans,k,sb;
vector<int>vec[N];
void dfs(int x){
	vis[x]=1;
	for(int i=0;i<vec[x].size();i++){
		int t=vec[x][i];
		if(vis[t]==1)S=x,T=t;
		if(!vis[t])dad[t]=x,dfs(t);
	}
	vis[x]=2;
}
int main(){
	scanf("%d",&n);
	for(i=1;i<=n;i++){
		scanf("%d",&a[i]);
		if(a[i]==i){sb=i;tot++;continue;}
		vec[i].push_back(a[i]);
	}
	for(i=1;i<=n;i++)if(!dad[i]){
		S=0;dad[i]=i;dfs(i);
		if(S)ans++,a[S]=(sb?sb:sb=S);
	}
	for(i=1;i<=n;i++)if(a[i]==i)a[i]=sb;
	printf("%d\n",max(1,tot)+ans-1);
	for(i=1;i<=n;i++)printf("%d ",a[i]);
}
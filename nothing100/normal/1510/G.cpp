#include<bits/stdc++.h>
using namespace std;
int t,n,k,height[110],fa[110],ans,que[110],blo[110];
vector<int> edge[110];
void dfs1(int x){
	if (height[x]>height[ans]) ans=x;
	for (int i=0;i<edge[x].size();i++){
		height[edge[x][i]]=height[x]+1;
		dfs1(edge[x][i]);
	}
}
void dfs2(int x){
	printf("%d ",x);
	for (int i=0;i<edge[x].size();i++){
		if (blo[edge[x][i]]==0&&ans){
			ans--;
			dfs2(edge[x][i]);
			printf("%d ",x);
		}
	}
}
int main(){
	scanf("%d",&t);
	while (t--){
		scanf("%d%d",&n,&k);
		int o;
		height[1]=1;
		for (int i=2;i<=n;i++){
			scanf("%d",&o);
		 	edge[o].push_back(i);
		 	fa[i]=o;
		}
		ans=1;
		dfs1(1);
		o=ans;
		printf("%d\n",2*k-min(k,height[ans])-1);
		int tail=0; 
		while (o){
		 	que[tail]=o;
		 	tail++;
		 	blo[o]=1;
		 	o=fa[o];
		}
		ans=k-min(k,tail);
		for (int i=0;i<min(k,tail);i++){
			dfs2(que[tail-1-i]);
		}
		printf("\n");
		for (int i=1;i<=n;i++) edge[i].clear(),blo[i]=0;
	}
}
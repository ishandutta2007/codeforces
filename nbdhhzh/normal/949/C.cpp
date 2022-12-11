#include<bits/stdc++.h>
#define N 400010
using namespace std;
int n,m,h,a[N],ne[N],v[N],low[N],vis[N],stark[N],dfn[N],l,head[N];
int size[N],ans,top,cnt,cmt,lab[N],i,x,y,j; 
void add(int x,int y){
	//printf("%d %d\n",x,y);
	v[++l]=y;ne[l]=head[x];head[x]=l;
}
void dfs(int x){
	vis[x]=1;
	stark[++top]=x;
	dfn[x]=low[x]=++cnt;
	for(int i=head[x];i;i=ne[i]){
		if(!vis[v[i]])dfs(v[i]);
		if(vis[v[i]]==1)low[x]=min(low[v[i]],low[x]);
	}
	if(dfn[x]==low[x]){
		++cmt;
		for(;stark[top+1]!=x;top--)
			lab[stark[top]]=cmt,size[cmt]++,vis[stark[top]]=2; 
	}
}
int main(){
	scanf("%d%d%d",&n,&m,&h);
	for(i=1;i<=n;i++)
		scanf("%d",&a[i]);
	for(i=1;i<=m;i++){
		scanf("%d%d",&x,&y);
		if((a[x]+1)%h==a[y])add(x,y);
		if((a[y]+1)%h==a[x])add(y,x);
	}
	for(i=1;i<=n;i++)
		if(!vis[i])dfs(i);
	for(i=1;i<=n;i++){
		for(j=head[i];j;j=ne[j])
			if(lab[v[j]]!=lab[i])break;
		if(j)size[lab[i]]=n;
	}
	ans=1;
	for(i=1;i<=cmt;i++)
		if(size[i]<size[ans])ans=i;
	printf("%d\n",size[ans]);
	for(i=1;i<=n;i++)
		if(lab[i]==ans)printf("%d ",i);
	puts("");
}
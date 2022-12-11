#include<bits/stdc++.h>
#define N 200010
using namespace std;
int f[N],head[N],ne[N],v[N],dad[N],l,a[N],n,i,x,y,ans;
void add(int x,int y){v[++l]=y;ne[l]=head[x];head[x]=l;}
void dfs(int x)
{
	f[x]=1;
	for(int i=head[x];i;i=ne[i])
	if(v[i]!=dad[x])
	{
		dad[v[i]]=x;
		dfs(v[i]);
		if(a[v[i]]!=a[x])f[x]=0;
		f[x]&=f[v[i]];
	}
	//printf("%d %d\n",x,f[x]);
}
int dfs1(int x)
{
	//printf("dfs1 %d\n",x);
	int i,j,ans=0;
	for(i=head[x];i;i=ne[i])
		if(v[i]!=dad[x]&&(!f[v[i]]))break;
	if(!i)return x;
	if(a[x]!=a[dad[x]])return 0;
	for(i=head[x];i;i=ne[i])
		if(v[i]!=dad[x]&&((!f[v[i]])||(a[v[i]]!=a[x])))break;
	for(j=ne[i];j;j=ne[j])
		if(v[j]!=dad[x]&&((!f[v[j]])||(a[v[j]]!=a[x])))break;
	//printf("%d %d\n",i,j);
	if(i&&j)return 0;else
	if(!i){for(j=head[x];j;j=ne[j])if(ans=dfs1(v[j]))return ans;}
	else return dfs1(v[i]);
}
int main()
{
	scanf("%d",&n);
	for(i=1;i<n;i++)
		scanf("%d%d",&x,&y),add(x,y),add(y,x);
	for(i=1;i<=n;i++)
		scanf("%d",&a[i]);
	a[0]=a[1];
	dfs(1);
	ans=dfs1(1);
	if(ans)printf("YES\n%d\n",ans);
	else printf("NO\n");
}
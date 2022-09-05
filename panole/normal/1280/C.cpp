#include<bits/stdc++.h>
using namespace std;

long long ans1,ans2;
int T,n,siz[200010],fv[200010],fa[200010],hd[200010],cnt;
struct node{int to,next,val;}e[400010];

void dfs(int x)
{
	siz[x]=1;
	for (int i=hd[x]; i; i=e[i].next)
		if (e[i].to!=fa[x]) fa[e[i].to]=x,fv[e[i].to]=e[i].val,dfs(e[i].to),siz[x]+=siz[e[i].to];
}

int main()
{
	scanf("%d",&T);
	while (T--)
	{
		scanf("%d",&n),cnt=0,n<<=1;
		for (int i=1; i<=n; i++) hd[i]=fa[i]=0;
		for (int i=1; i<n; i++) 
		{
			int x,y,v; scanf("%d%d%d",&x,&y,&v);
			e[++cnt]=(node){y,hd[x],v},hd[x]=cnt;
			e[++cnt]=(node){x,hd[y],v},hd[y]=cnt;
		}
		dfs(1),ans1=ans2=0;
		for (int i=2; i<=n; i++)
		{
			if (siz[i]&1) ans1+=fv[i];
			ans2+=1ll*min(siz[i],n-siz[i])*fv[i];
		}
		printf("%I64d %I64d\n",ans1,ans2);
	}
	return 0;
}
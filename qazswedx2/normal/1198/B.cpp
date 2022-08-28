#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
int n,m,a[1000005],dfn[1000005],st[1000005][2],tp;
int b[1000005];
int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
		scanf("%d",&a[i]);
	scanf("%d",&m);
	for(int i=1;i<=m;i++)
	{
		int op,x,y;
		scanf("%d%d",&op,&x);
		if(op==1)
		{
			scanf("%d",&y);
			a[x]=y;
			dfn[x]=i;
		}
		else
		{
			while(tp>0&&st[tp][0]<x)
				tp--;
			st[++tp][0]=x;
			st[tp][1]=i;
		}
	}
	for(int i=1;i<=tp;i++)
		b[i]=st[i][1];
	for(int i=1;i<=n;i++)
	{
		int nw=a[i],id=lower_bound(b+1,b+tp+1,dfn[i])-b;
		if(id<=tp) nw=max(nw,st[id][0]);
		printf("%d ",nw);
	}
	return 0;
}
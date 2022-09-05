#include<bits/stdc++.h>
using namespace std;

int dis1[200010],dis2[200010],n,m,k,cnt,hd[200010],a[200010],q[200010],l,r,x,y;
struct node{int to,next;}e[400010];

bool cmp(const int &a,const int &b) {return dis1[a]<dis1[b];}

int main()
{
	scanf("%d%d%d",&n,&m,&k);
	for (int i=1; i<=k; i++) scanf("%d",&a[i]);
	for (int i=1; i<=m; i++)
	{
		scanf("%d%d",&x,&y);
		e[++cnt]=(node){y,hd[x]},hd[x]=cnt;
		e[++cnt]=(node){x,hd[y]},hd[y]=cnt;
	}
	q[l=r=1]=1,dis1[1]=0;
	for (int i=2; i<=n; i++) dis1[i]=-1;
	while (l<=r)
	{
		x=q[l++];
		for (int i=hd[x]; i; i=e[i].next)
			if (dis1[e[i].to]==-1) dis1[q[++r]=e[i].to]=dis1[x]+1;
	}
	q[l=r=1]=n,dis2[n]=0;
	for (int i=1; i<n; i++) dis2[i]=-1;
	while (l<=r)
	{
		x=q[l++];
		for (int i=hd[x]; i; i=e[i].next)
			if (dis2[e[i].to]==-1) dis2[q[++r]=e[i].to]=dis2[x]+1;
	}
	int ans=0,nw=0;
	sort(a+1,a+1+k,cmp);
	for (int i=k; i; i--)
	{
		if (i<k) ans=max(ans,dis1[a[i]]+nw+1);
		nw=max(nw,dis2[a[i]]);
	}
	ans=min(ans,dis1[n]);
	printf("%d\n",ans);
	return 0;
}
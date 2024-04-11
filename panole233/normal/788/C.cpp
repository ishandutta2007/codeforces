#include<cstdio>
#include<cstring>

int s,t,n,x,dis[1000001],q[10000001],l,r,maxx,minx;
bool bo[1001],inq[1000001];

int max(int x,int y) {return x>y?x:y;}
int min(int x,int y) {return x>y?y:x;}

int main()
{
	scanf("%d%d",&t,&n);
	s=500000;
	memset(bo,0,sizeof(bo)); minx=1e9; maxx=0;
	for (int i=1; i<=n; i++) scanf("%d",&x),bo[x]=1,maxx=max(maxx,x),minx=min(minx,x);
	for (int i=1; i<=1000000; i++) dis[i]=1e9;
	r=0;
	if (t>maxx) {printf("-1"); return 0;}
	if (t<minx) {printf("-1"); return 0;}
	memset(inq,0,sizeof(inq));
	for (int i=0; i<=1000; i++)
		if (bo[i])
		{
			q[++r]=s+i-t; dis[s+i-t]=1; inq[s+i-t]=1;
		}
	for (l=1; l<=r; l++)
	{
		if (q[l]==s) break;
		for (int i=0; i<=1000; i++)
			if (bo[i])
			{
				x=q[l]+i-t;
				if (x>1000000||x<0) continue;
				if (inq[x]) 
				{
					if (dis[x]>dis[q[l]]+1) dis[x]=dis[q[l]]+1;
					continue;
				}
				dis[x]=dis[q[l]]+1; q[++r]=x; inq[x]=1;
			}
	}
	if (inq[s]) printf("%d\n",dis[s]); else printf("-1\n");
	return 0;
}
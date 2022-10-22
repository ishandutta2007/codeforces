#include<bits/stdc++.h>
using namespace std;

const int N=1e5+1e3+7;

int n,vis[N];

struct P{
	int x,y,z;
	int id;
}p[N],rem;

bool cmp(P a,P b)
{
	if(a.x==b.x&&a.y==b.y)
		return a.z<b.z;
	if(a.x==b.x)
		return a.y<b.y;
	return a.x<b.x;
}

int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
		scanf("%d%d%d",&p[i].x,&p[i].y,&p[i].z),p[i].id=i;
	sort(p+1,p+n+1,cmp);
	int j=1;
	for(int i=1;i<=n;i=j+1)
	{
		j=i;
		while(j<n&&p[j+1].x==p[i].x&&p[j+1].y==p[i].y)
			j++;
		for(int k=i;k+1<=j;k+=2)
			printf("%d %d\n",p[k].id,p[k+1].id),vis[k]=vis[k+1]=1;
	}	
	int tot=0;
	for(int i=1;i<=n;i++)
		if(!vis[i])
			p[++tot]=p[i];
	for(int i=1;i<=n;i++)
		vis[i]=0;
	n=tot;
	for(int i=1;i<=n;i=j+1)
	{
		j=i;
		while(j<n&&p[j+1].x==p[i].x)
			j++;
		for(int k=i;k+1<=j;k+=2)
			printf("%d %d\n",p[k].id,p[k+1].id),vis[k]=vis[k+1]=1;
	}	
	tot=0;
	for(int i=1;i<=n;i++)
		if(!vis[i])
			p[++tot]=p[i];
	n=tot;
	for(int i=1;i<=n;i++)
		vis[i]=0;
	for(int i=1;i<=n;i+=2)
		printf("%d %d\n",p[i].id,p[i+1].id);
}
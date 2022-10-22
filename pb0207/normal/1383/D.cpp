#include<bits/stdc++.h>
using namespace std;

const int N=301;

int n,m,a[N][N],r[N],c[N],vr[N*N],vc[N*N];

int ans[N][N],lim[N][N];

struct node{
	int x,y,v;
}s[N*N];

bool cmp(node a,node b)
{
	if(a.v!=b.v)
		return a.v<b.v;
	if(a.x!=b.x)
		return a.x<b.x;
	return a.y<b.y;
}

int main()
{
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++)
		for(int j=1;j<=m;j++)
			scanf("%d",&a[i][j]);
	for(int i=1;i<=n;i++)
		for(int j=1;j<=m;j++)
			r[i]=max(r[i],a[i][j]),c[j]=max(c[j],a[i][j]);
	for(int i=1;i<=n;i++)
		vr[r[i]]=1;
	for(int i=1;i<=m;i++)
		vc[c[i]]=1;
	int nr=0,nc=0;
	for(int i=n*m;i>=1;i--)
		if(vr[i]||vc[i])
		{
			if(vr[i])
				nr++;
			if(vc[i])
				nc++;
			ans[nr][nc]=i;
		}
	for(int i=1;i<=n;i++)
		for(int j=1;j<=m;j++)
			lim[i][j]=1e9;
	for(int i=1;i<=n;i++)
		for(int j=1;j<=m;j++)
			if(ans[i][j])
			{
				for(int k=1;k<=m;k++)
					if(!ans[i][k])
						lim[i][k]=min(lim[i][k],ans[i][j]);
				for(int k=1;k<=n;k++)
					if(!ans[k][j])
						lim[k][j]=min(lim[k][j],ans[i][j]);
			}
	int tot=0;
	for(int i=1;i<=n;i++)
		for(int j=1;j<=m;j++)
			if(!ans[i][j])
			{
				node tmp;
				tmp.x=i,tmp.y=j,tmp.v=lim[i][j];
				s[++tot]=tmp;
			}
	sort(s+1,s+tot+1,cmp); 
	int now=1;
	int ok=1;
	for(int i=1;i<=tot;i++)
	{
		while(vr[now]||vc[now])
			now++;
		if(s[i].v<now)
			ok=0;
		ans[s[i].x][s[i].y]=now;
		now++;
	}
	if(!ok)
		puts("-1");
	else
	{
		for(int i=1;i<=n;i++,puts(""))
			for(int j=1;j<=m;j++,putchar(' '))
				printf("%d",ans[i][j]);
	}
}
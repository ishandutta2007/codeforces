#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
int n,m,prime[10000005],vis[100005],pt,pn=20000000;
bool p[20000005];
int main()
{
	p[0]=p[1]=1;
	for(int i=2;i<=pn;i++)
	{
		if(!p[i]) prime[++pt]=i;
		for(int j=1;j<=pt&&i*prime[j]<=pn;j++)
		{
			p[i*prime[j]]=1;
			if(i%prime[j]==0) break;
		}
	}
	scanf("%d",&n);
	m=n*(n+1)/2;
	if(n==2)
	{
		printf("1 1");
		return 0;
	}
	if(m%2==0)
	{
		for(int i=1;i<=pt&&prime[i]<=m;i++)
			if(!p[m-prime[i]])
			{
				int nw=prime[i];
				for(int i=n;i>=1;i--)
					if(nw>=i) vis[i]=1,nw-=i;
				break;
			}
		for(int i=1;i<=n;i++)
			printf("%d ",vis[i]+1);
		return 0;
	}
	if(!p[m-2])
	{
		printf("1 2 ");
		for(int i=3;i<=n;i++)
			printf("1 ");
		return 0;
	}
	m-=3;
	for(int i=1;i<=pt&&prime[i]<=m;i++)
		if(!p[m-prime[i]])
		{
			int nw=prime[i];
			for(int i=n;i>=1;i--)
				if(nw>=i) vis[i]=1,nw-=i;
			break;
		}
	if(!vis[1]&&!vis[2]) vis[1]=vis[2]=2;
	else vis[3]=2;
	for(int i=1;i<=n;i++)
		printf("%d ",vis[i]+1);
	return 0;
}
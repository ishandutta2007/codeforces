#include<iostream>
#include<cstring>
#include<cstdio>
using namespace std;

int t(int x)
{
	return x>0?x:-x;
}

int n,m;

int a[10001],vis[20001];

int main()
{
	cin>>n>>m;
	for(int i=1;i<=m;i++)
	{
		int k;
		memset(vis,0,sizeof(vis));
		scanf("%d",&k);
		bool flag=true;
		for(int j=1;j<=k;j++)
			scanf("%d",&a[j]);
		for(int j=1;j<=k;j++)
		{
			if(a[j]>0)
			if(!vis[a[j]+n])
			{
				vis[a[j]+n]=true;
				if(vis[a[j]]==true)
					flag=false;
			}
			if(a[j]<0)
			if(!vis[t(a[j])])
			{
				vis[t(a[j])]=true;
				if(vis[t(a[j])+n]==true)
					flag=false;
			}
		}
		for(int j=1;j<=k;j++)
		{
			if(a[j]>0)
				vis[a[j]+n]=true;
			else
				vis[t(a[j])]=true;
		}
		if(flag)
		{
			printf("YES");
			return 0;
		}
	}
	printf("NO");
}
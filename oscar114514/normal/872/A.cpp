#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<cstdlib>

using namespace std;
int n,m;
int t,s1[12],s2[12];
int main()
{
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&t);
		s1[t]=1;
	}
	for(int i=1;i<=m;i++)
	{
		scanf("%d",&t);
		s2[t]=1;
	}
	for(int i=1;i<=9;i++)
	{
		if(s1[i]==1&&s2[i]==1)
		{
			printf("%d\n",i);
			return 0;
		}
	}
	for(int i=1;i<=9;i++)
	{
		for(int j=1;j<=9;j++)
		{
			if((s1[i]&&s2[j])||(s2[i]&&s1[j]))
			{
				printf("%d%d\n",i,j);
				return 0;
			}
		}
	}
	return 0;
}
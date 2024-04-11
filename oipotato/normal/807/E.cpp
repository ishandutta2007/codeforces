#include<cstdio>
#include<iostream>
using namespace std;
int num[45],r[45],ans[100010],p,n,tot;
long long x,tmp;
bool check(int x)
{
	int rest=num[0]-x;
	for(int i=1;i<=p;i++)
	{
		if(x>num[i])
		{
			rest-=min(x-num[i],rest);
			x=num[i];
		}
		else rest+=num[i]-x;
		rest+=r[i];
	}
	return rest<=x;
}
int main()
{
	scanf("%d",&n);
	tmp=1;
	p=0;
	for(int i=1;i<=n;i++)
	{
		cin>>x;
		if(x==tmp)num[p]++;
		else if(x<tmp)r[p-1]++;
		else
		{
			for(;tmp<x;)
			{
				tmp<<=1;
				p++;
			}
			if(x==tmp)num[p]++;
			else r[p-1]++;
		}
	}
	for(int i=1;i<=num[0];i++)
	if(check(i))
	ans[++tot]=i;
	if(tot)
	{
		for(int i=1;i<tot;i++)printf("%d ",ans[i]);
		printf("%d",ans[tot]);
	}
	else printf("-1");
	return 0;
}
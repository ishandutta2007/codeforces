#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
int n,minn=233333;
int arr[6],vis[6];
void f(int d)
{
	int q=1;
	for(int i=0;i<6;i++)
	{
		if(!vis[i])
		{
			q=0;
			break;
		}
	}
	if(q==1)
	{
		minn=min(minn,d);
		return;
	}
	for(int i=1;i<1<<6;i++)
	{
		int s=0,flag=1;
		for(int b=0;b<6;b++)
		{
			if((i&(1<<b))&&vis[b])
			{
				flag=0;
				break;
			}
			if(i&(1<<b))s+=arr[b];
		}
		if(flag==0||s>n)continue;
		for(int b=0;b<6;b++)
		{
			if(i&(1<<b))vis[b]=1;
		}
		f(d+1);
		for(int b=0;b<6;b++)
		{
			if(i&(1<<b))vis[b]=0;
		}
	}
}
int a,b;
int main()
{
	scanf("%d%d%d",&n,&a,&b);
	for(int i=0;i<=1;i++)arr[i]=b;for(int i=2;i<=5;i++)arr[i]=a;
	f(0);
	printf("%d\n",minn);
	return 0;
}
#include<iostream>
#include<cstdio>
using namespace std;
#define N (int)1e6
int a1[N],b1[N],a,b,num[N]; 
int main()
{
	cin>>a>>b;
/*	if(a==0&&b==0)
	{
		printf("0\n\n0\n\n");
		return 0;
	}*/
	int i,j,sum1=0,sum2=a+b,n;
	for(i=1;;i++)
	{
		sum1+=i;
		if(sum1>sum2)break;
	}
	n=i-1;
	sum1=0,sum2=0;
	for(i=n,j=1;i;i--)
	{
		if(a-i>=0)a1[j++]=i;
		else break;
		a-=i;
		num[i]=1;
	}
	if(a&&i)
	{
		sum1=j;
		a1[j]=a;
		num[a]=1;
	}
	else sum1=j-1;
	sum2=0;
	for(i=1;;i++)
	{
		if(num[i])continue;
		if(b-i>=0)
		{
			b1[++sum2]=i;
			b-=i;
		}
		else break;
	}
	printf("%d\n",sum1);
	if(sum1>0)
	{
		for(i=1;i<=sum1;i++)
	    printf("%d ",a1[i]);
	}
	printf("\n");
	printf("%d\n",sum2);
	if(sum2>0)
	{
		for(i=1;i<=sum2;i++)
	    printf("%d ",b1[i]);
	}
}
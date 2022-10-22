#include<cstdio>
#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std;

const int N=2e5+1e3+7;

int n,a[N];

bool ok=false;

int main()
{
	scanf("%d",&n);
	for(int i=0;i<=n;i++)
	{
		scanf("%d",&a[i]);
		if(i!=0&&a[i]>1&&a[i-1]>1)
			ok=true;
	}
	if(!ok)
	{
		puts("perfect");
		return 0;
	}
	puts("ambiguous");
	printf("0 ");
	int now=1;
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=a[i];j++)
			printf("%d ",now);
		now+=a[i-1];
	}
	puts(""); 
	printf("0 ");
	now=1;
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<a[i];j++)
			printf("%d ",now);
		if(a[i-1]>=2&&a[i]>=2)
			printf("%d ",now+1);
		else
			printf("%d ",now);
		now+=a[i-1];
	}
}
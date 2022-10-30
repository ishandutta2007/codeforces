#include <bits/stdc++.h>
using namespace std;
int a[100007];
int main()
{
	int s=0,n,p,sp=0,sol=-1;
	scanf("%d%d",&n,&p);
	for(int i=0;i<n;i++) scanf("%d",&a[i]);
	for(int i=0;i<n;i++) s=(s+a[i])%p;
	for(int i=0;i<n-1;i++)
	{
		sp=(sp+a[i])%p;
		int x=sp,y=(s+p-sp)%p;
		if(x+y>sol) sol=x+y;
	}
	printf("%d",sol);
}
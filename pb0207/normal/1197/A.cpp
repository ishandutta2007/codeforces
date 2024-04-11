#include<cstdio>
#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std;

const int N=1e5+1e3+7;

int T,n;

int a[N];

int main()
{
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d",&n);
		for(int i=1;i<=n;i++)
			scanf("%d",&a[i]);
		int mx=0,smx=0;
		for(int i=1;i<=n;i++)
			if(a[i]>mx)
				smx=mx,mx=a[i];
			else if(a[i]>smx)
				smx=a[i];
		printf("%d\n",min(smx-1,n-2));
	}
}
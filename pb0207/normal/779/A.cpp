#include<cstdio>
#include<cmath>
#include<iostream>
using namespace std;

int n,tonga[6],tongb[6];

int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
	{
		int x;
		scanf("%d",&x);
		tonga[x]++;
	}
	for(int i=1;i<=n;i++)
	{
		int x;
		scanf("%d",&x);
		tongb[x]++;
	}
	for(int i=1;i<=5;i++)
		if((tonga[i]+tongb[i])&1)
		{
			printf("-1");
			return 0;
		}
	int ans=0;
	for(int i=1;i<=5;i++)
		ans+=abs(tonga[i]-tongb[i]);
	printf("%d",ans/4);
}
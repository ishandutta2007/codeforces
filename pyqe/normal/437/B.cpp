#include <bits/stdc++.h>

using namespace std;

long long n,sm,yk[100069],sq[100069],zs=0;
queue<long long> q[17];

int main()
{
	long long i,k;
	
	scanf("%lld%lld",&sm,&n);
	for(i=0;1<<i<=n;i++)
	{
		yk[1<<i]=i;
	}
	for(i=1;i<=n;i++)
	{
		q[yk[i&-i]].push(i);
	}
	for(i=16;i+1;i--)
	{
		for(;!q[i].empty()&&sm>=1<<i;)
		{
			k=q[i].front();
			q[i].pop();
			zs++;
			sq[zs]=k;
			sm-=1<<i;
		}
	}
	if(sm)
	{
		printf("-1\n");
	}
	else
	{
		printf("%lld\n",zs);
		for(i=1;i<=zs;i++)
		{
			printf("%lld%c",sq[i]," \n"[i==zs]);
		}
	}
}
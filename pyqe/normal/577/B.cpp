#include <bits/stdc++.h>

using namespace std;

long long n,m,fq[1069],nr[1069],inf=1e18;
queue<long long> q;

int main()
{
	long long i,j,k,l;
	
	scanf("%lld%lld",&n,&m);
	for(i=0;i<n;i++)
	{
		scanf("%lld",&k);
		fq[k%m]++;
	}
	for(i=0;i<m;i++)
	{
		nr[i]=inf;
	}
	nr[0]=0;
	for(i=0;i<m;i++)
	{
		for(j=0;j<m;j++)
		{
			if(nr[j]!=inf)
			{
				q.push(j);
				nr[j]=0;
			}
		}
		for(;!q.empty();)
		{
			k=q.front();
			q.pop();
			if(nr[k]==fq[i])
			{
				continue;
			}
			l=(k+i)%m;
			if(!l)
			{
				printf("YES\n");
				return 0;
			}
			if(nr[k]+1<nr[l])
			{
				q.push(l);
				nr[l]=nr[k]+1;
			}
		}
	}
	printf("NO\n");
}
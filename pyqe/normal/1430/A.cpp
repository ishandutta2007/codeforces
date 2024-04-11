#include <bits/stdc++.h>

using namespace std;

long long n,a[3]={3,5,7},pr[1069],sq[3];
queue<long long> q;

int main()
{
	long long t,rr,i,k;
	
	scanf("%lld",&t);
	for(rr=0;rr<t;rr++)
	{
		scanf("%lld",&n);
		for(i=0;i<=n;i++)
		{
			pr[i]=-1;
		}
		q.push(0);
		pr[0]=0;
		for(;!q.empty();)
		{
			k=q.front();
			q.pop();
			for(i=0;i<3;i++)
			{
				if(k+a[i]<=n&&pr[k+a[i]]==-1)
				{
					q.push(k+a[i]);
					pr[k+a[i]]=i;
				}
			}
		}
		if(pr[n]==-1)
		{
			printf("-1\n");
			continue;
		}
		for(i=0;i<3;i++)
		{
			sq[i]=0;
		}
		for(;n;n-=a[pr[n]])
		{
			sq[pr[n]]++;
		}
		for(i=0;i<3;i++)
		{
			printf("%lld%c",sq[i]," \n"[i==2]);
		}
	}
}
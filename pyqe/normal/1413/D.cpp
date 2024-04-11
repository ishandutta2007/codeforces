#include <bits/stdc++.h>

using namespace std;

long long n=0,m=0,nn=0,qq[100069],sk[100069],a[100069];
bitset<200069> spc;
priority_queue<long long> pq;

int main()
{
	long long t,rr,i;
	char ch;
	
	scanf("%lld",&t);
	t*=2;
	for(rr=1;rr<=t;rr++)
	{
		scanf(" %c",&ch);
		if(ch=='+')
		{
			n++;
			nn++;
			sk[nn]=n;
		}
		else
		{
			spc[rr]=1;
			m++;
			scanf("%lld",qq+m);
			if(!nn)
			{
				printf("NO\n");
				return 0;
			}
			a[sk[nn]]=qq[m];
			nn--;
		}
	}
	n=0;
	m=0;
	for(rr=1;rr<=t;rr++)
	{
		if(!spc[rr])
		{
			n++;
			pq.push(-a[n]);
		}
		else
		{
			m++;
			if(qq[m]!=-pq.top())
			{
				printf("NO\n");
				return 0;
			}
			pq.pop();
		}
	}
	printf("YES\n");
	for(i=1;i<=n;i++)
	{
		printf("%lld%c",a[i]," \n"[i==n]);
	}
}
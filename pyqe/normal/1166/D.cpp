#include <bits/stdc++.h>

using namespace std;

long long n,m,d,nn,sq[69];

int main()
{
	long long t,rr,i,k,sm,ps;
	
	scanf("%lld",&t);
	for(rr=0;rr<t;rr++)
	{
		scanf("%lld%lld%lld",&n,&m,&d);
		if(n==m)
		{
			printf("1 %lld\n",n);
			continue;
		}
		sm=n+1;
		for(nn=1;sm*2<=m;sm*=2,nn++);
		sq[1]=n;
		ps=n;
		for(i=2;i<=nn+1;i++)
		{
			k=min(((m-sm)>>(max(nn-i,0ll)))+1,d);
			sq[i]=ps+k;
			sm+=k-1<<(max(nn-i,0ll));
			ps+=sq[i];
		}
		if(sq[nn+1]<m)
		{
			printf("-1\n");
			continue;
		}
		printf("%lld",nn+1);
		for(i=1;i<=nn+1;i++)
		{
			printf(" %lld",sq[i]);
		}
		printf("\n");
	}
}
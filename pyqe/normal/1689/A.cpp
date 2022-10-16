#include <bits/stdc++.h>

using namespace std;

long long n[2],d,a[2][100069];

int main()
{
	long long t,rr,i,ii,l,p[2],e,c;
	char ch;
	
	scanf("%lld",&t);
	for(rr=0;rr<t;rr++)
	{
		scanf("%lld%lld%lld",n,n+1,&d);
		for(ii=0;ii<2;ii++)
		{
			for(i=1;i<=n[ii];i++)
			{
				scanf(" %c",&ch);
				a[ii][i]=ch-'a';
			}
			sort(a[ii]+1,a[ii]+n[ii]+1);
			p[ii]=1;
		}
		l=-1;
		for(;p[0]<=n[0]&&p[1]<=n[1];)
		{
			e=a[1][p[1]]<a[0][p[0]];
			c=c*(e==l)+1;
			if(c>d)
			{
				e^=1;
				c=1;
			}
			printf("%c",(char)(a[e][p[e]]+'a'));
			p[e]++;
			l=e;
		}
		printf("\n");
	}
}
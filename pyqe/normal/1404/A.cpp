#include <bits/stdc++.h>

using namespace std;

long long n,d,a[300069],fq[2];

int main()
{
	long long t,rr,i,ii,k;
	char ch;
	
	scanf("%lld",&t);
	for(rr=0;rr<t;rr++)
	{
		scanf("%lld%lld",&n,&d);
		for(i=0;i<d;i++)
		{
			a[i]=-1;
		}
		for(i=0;i<n;i++)
		{
			scanf(" %c",&ch);
			k=(ch=='1')-(ch=='?');
			if(k+1)
			{
				if(a[i%d]==-1||a[i%d]==k)
				{
					a[i%d]=k;
				}
				else
				{
					a[i%d]=-2;
				}
			}
		}
		for(ii=0;ii<2;ii++)
		{
			fq[ii]=0;
		}
		for(i=0;i<d;i++)
		{
			if(a[i]==-2)
			{
				i=-1;
				break;
			}
			if(a[i]+1)
			{
				fq[a[i]]++;
			}
		}
		if(i!=-1&&max(fq[0],fq[1])*2<=d)
		{
			printf("YES\n");
		}
		else
		{
			printf("NO\n");
		}
	}
}
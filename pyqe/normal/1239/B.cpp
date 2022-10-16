#include <bits/stdc++.h>

using namespace std;

#define mp make_pair
#define fr first
#define sc second

long long n,ps[600069];

int main()
{
	long long i,ii,k,mn=1e18,fq=0,mx,e1,e2,c[2]={-1000000000000000000,-1000000000000000000},ls[2]={-1,-1};
	string s;
	pair<long long,long long> tmp;
	
	scanf("%lld",&n);
	cin>>s;
	for(i=1;i<=n;i++)
	{
		if(s[i-1]=='(')
		{
			k=1;
		}
		else
		{
			k=-1;
		}
		ps[i]=ps[i-1]+k;
		mn=min(mn,ps[i]);
	}
	if(ps[n]!=0)
	{
		printf("0\n1 1\n");
		return 0;
	}
	for(i=n+1;i<=n+n;i++)
	{
		ps[i]=ps[i-n];
		if(ps[i]==mn)
		{
			fq++;
		}
	}
	mx=fq;
	e1=1;
	e2=1;
	for(i=1;i<=n+n;i++)
	{
		for(ii=0;ii<2;ii++)
		{
			if(ps[i]==mn+1+ii)
			{
				c[ii]++;
				if(i>1&&ps[i-1]==mn+ii)
				{
					ls[ii]=i;
				}
				if(i<n+n&&ps[i+1]==mn+ii)
				{
					k=c[ii]+ii*fq;
					if(k>mx)
					{
						mx=k;
						e1=(ls[ii]-1)%n+1;
						e2=i%n+1;
					}
					c[ii]=0;
				}
			}
		}
	}
	printf("%lld\n%lld %lld\n",mx,e1,e2);
}
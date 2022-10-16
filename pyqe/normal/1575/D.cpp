#include <bits/stdc++.h>

using namespace std;

long long n,a[100069];

int main()
{
	long long i,j,ii,k,sm,z=0;
	bool bad,bad2;
	string s;
	
	cin>>s;
	n=s.length();
	for(i=1;i<=n;i++)
	{
		if(s[i-1]=='_')
		{
			a[i]=-1;
		}
		else if(s[i-1]=='X')
		{
			a[i]=-2;
		}
		else
		{
			a[i]=s[i-1]-'0';
		}
	}
	if(n==1)
	{
		z=a[1]<=0;
	}
	else if(!a[1])
	{
		z=0;
	}
	else
	{
		for(i=0;i<100;i+=25)
		{
			if(a[n]==-2&&a[n-1]==-2&&i%10!=i/10)
			{
				continue;
			}
			bad=0;
			for(ii=0,k=i;ii<2;k/=10,ii++)
			{
				if((a[n-ii]>=0&&a[n-ii]!=k%10)||(k%10==0&&(n-ii==1||(a[n-ii]==-2&&a[1]==-2))))
				{
					break;
				}
				bad|=a[n-ii]==-2;
			}
			if(ii<2)
			{
				continue;
			}
			sm=1;
			bad2=0;
			for(j=1;j<=n-2;j++)
			{
				if(a[j]==-1||(a[j]==-2&&!bad2&&!bad))
				{
					sm*=10-(j==1);
					bad2|=a[j]==-2;
				}
			}
			z+=sm;
		}
	}
	printf("%lld\n",z);
}
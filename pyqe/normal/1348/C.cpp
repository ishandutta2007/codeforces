#include <bits/stdc++.h>

using namespace std;

long long n,m,fq[26],sq[100069],zs,inf=1e18;

int main()
{
	long long t,rr,i,j,k,mn,c,ls;
	string s;
	
	scanf("%lld",&t);
	for(rr=0;rr<t;rr++)
	{
		scanf("%lld%lld",&n,&m);
		cin>>s;
		for(i=0;i<26;i++)
		{
			fq[i]=0;
		}
		mn=inf;
		for(i=0;i<n;i++)
		{
			k=s[i]-'a';
			mn=min(mn,k);
			fq[k]++;
		}
		zs=0;
		if(fq[mn]<m)
		{
			c=0;
			for(i=0;i<26;i++)
			{
				c+=fq[i];
				if(c>=m)
				{
					break;
				}
			}
			zs++;
			sq[zs]=i;
		}
		else
		{
			zs++;
			sq[zs]=mn;
			fq[mn]-=m;
			c=0;
			ls=0;
			for(i=0;i<26;i++)
			{
				if(fq[i])
				{
					c++;
					ls=i;
				}
			}
			if(c>1)
			{
				for(i=0;i<26;i++)
				{
					for(j=0;j<fq[i];j++)
					{
						zs++;
						sq[zs]=i;
					}
				}
			}
			else
			{
				for(i=0;i<(fq[ls]+m-1)/m;i++)
				{
					zs++;
					sq[zs]=ls;
				}
			}
		}
		for(i=1;i<=zs;i++)
		{
			printf("%c",(char)sq[i]+'a');
		}
		printf("\n");
	}
}
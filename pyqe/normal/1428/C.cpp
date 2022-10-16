#include <bits/stdc++.h>

using namespace std;

long long n;
bitset<200069> a,vtd;

int main()
{
	long long t,rr,i,j,l,z;
	string s;
	
	scanf("%lld",&t);
	for(rr=0;rr<t;rr++)
	{
		cin>>s;
		n=s.length();
		for(i=1;i<=n;i++)
		{
			a[i]=s[i-1]-'A';
			vtd[i]=0;
		}
		l=0;
		z=0;
		for(j=0,i=1;i<=n;i++)
		{
			if(!a[i])
			{
				for(;j<=n&&(j<=i||!a[j]||vtd[j]);j++);
				if(j<=n)
				{
					vtd[i]=1;
					vtd[j]=1;
				}
			}
			z+=!vtd[i];
			if(!vtd[i])
			{
				if(a[i]&&l)
				{
					z-=2;
					l=0;
				}
				else
				{
					l=a[i];
				}
			}
		}
		printf("%lld\n",z);
	}
}
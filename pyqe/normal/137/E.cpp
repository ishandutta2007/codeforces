#include <bits/stdc++.h>

using namespace std;

long long n,ps[200069],mn[200069],inf=1e18;
string ky="aeiou";
bitset<200069> yk;

int main()
{
	long long i,k,lh,rh,md,zz,z=-inf,c=0;
	string s;
	
	for(i=0;i<5;i++)
	{
		yk[ky[i]-'a']=1;
	}
	cin>>s;
	n=s.length();
	for(i=1;i<=n;i++)
	{
		k=s[i-1]-'a';
		k+=32*(k<0);
		k=yk[k];
		ps[i]=ps[i-1]+!k*3-1;
		mn[i]=min(mn[i-1],ps[i]);
		zz=-1;
		for(lh=0,rh=i-1;lh<=rh;)
		{
			md=(lh+rh)/2;
			if(ps[i]-mn[md]>=0)
			{
				zz=md;
				rh=md-1;
			}
			else
			{
				lh=md+1;
			}
		}
		if(zz!=-1)
		{
			if(i-zz>z)
			{
				z=i-zz;
				c=0;
			}
			c+=i-zz==z;
		}
	}
	if(z==-inf)
	{
		printf("No solution\n");
	}
	else
	{
		printf("%lld %lld\n",z,c);
	}
}
#include <bits/stdc++.h>

using namespace std;

long long n,a[150069],sz[3]={3,3,5},ky[3][5]={{14,13,4,0,0},{19,22,14,0,0},{19,22,14,13,4}};
bitset<150069> sq;

int main()
{
	long long t,rr,i,ii,j,z,ls;
	string s;
	
	scanf("%lld",&t);
	for(rr=0;rr<t;rr++)
	{
		cin>>s;
		n=s.length();
		for(i=1;i<=n;i++)
		{
			a[i]=s[i-1]-'a';
		}
		sq.reset();
		z=0;
		for(ii=0;ii<3;ii++)
		{
			for(i=1;i<=n-sz[ii]+1;i++)
			{
				for(j=0;j<sz[ii];j++)
				{
					if(a[i+j]!=ky[ii][j])
					{
						j=-1;
						break;
					}
				}
				if(j!=-1)
				{
					if(ii<2)
					{
						sq[i+1]=1;
						z++;
					}
					else
					{
						sq[i+1]=0;
						sq[i+3]=0;
						sq[i+2]=1;
						z--;
					}
				}
			}
		}
		printf("%lld\n",z);
		for(i=1;i<=n;i++)
		{
			if(sq[i])
			{
				ls=i;
			}
		}
		for(i=1;i<=n;i++)
		{
			if(sq[i])
			{
				printf("%lld%c",i," \n"[i==ls]);
			}
		}
	}
}
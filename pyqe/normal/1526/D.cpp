#include <bits/stdc++.h>

using namespace std;

long long n,nn,a[100069],pm[4],ca[100069],sq[100069],yk[26];
bitset<4> vtd;
string ky="ANOT";

int main()
{
	long long t,rr,i,j,sm,c,z;
	string s;
	
	yk[0]=0;
	yk[13]=1;
	yk[14]=2;
	yk[19]=3;
	scanf("%lld",&t);
	for(rr=0;rr<t;rr++)
	{
		cin>>s;
		n=s.length();
		for(i=1;i<=n;i++)
		{
			a[i]=yk[s[i-1]-'A'];
		}
		for(i=0;i<4;i++)
		{
			pm[i]=i;
		}
		z=-1;
		for(;1;)
		{
			sm=0;
			vtd.reset();
			nn=0;
			for(i=0;i<4;i++)
			{
				c=0;
				vtd[pm[i]]=1;
				for(j=1;j<=n;j++)
				{
					c+=!vtd[a[j]];
					if(a[j]==pm[i])
					{
						sm+=c;
						nn++;
						ca[nn]=a[j];
					}
				}
			}
			if(sm>z)
			{
				z=sm;
				for(i=1;i<=n;i++)
				{
					sq[i]=ca[i];
				}
			}
			if(!next_permutation(pm,pm+4))
			{
				break;
			}
		}
		for(i=1;i<=n;i++)
		{
			printf("%c",ky[sq[i]]);
		}
		printf("\n");
	}
}
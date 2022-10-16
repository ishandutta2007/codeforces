#include <bits/stdc++.h>

using namespace std;

long long n,nn=0,fq[26],a[27];

int main()
{
	long long t,rr,i,j,ii,k;
	string s;
	bool bad;
	
	scanf("%lld",&t);
	for(rr=0;rr<t;rr++)
	{
		cin>>s;
		n=s.length();
		for(i=0;i<26;i++)
		{
			fq[i]=0;
		}
		for(i=1;i<=n;i++)
		{
			k=s[i-1]-'a';
			fq[k]++;
		}
		nn=0;
		for(i=0;i<26;i++)
		{
			if(fq[i])
			{
				nn++;
				a[nn]=i;
			}
		}
		bad=0;
		if(nn==3)
		{
			if(a[1]+1==a[2])
			{
				if(a[2]+1==a[3])
				{
					bad=1;
				}
				else
				{
					swap(a[1],a[3]);
				}
			}
		}
		else if(nn==2&&a[1]+1==a[2])
		{
			bad=1;
		}
		if(bad)
		{
			printf("No answer\n");
			continue;
		}
		for(i=nn/2+1;i<=nn;i++)
		{
			for(ii=0;ii<=!(i==nn&&nn%2);ii++)
			{
				k=i-nn/2*ii;
				for(j=0;j<fq[a[k]];j++)
				{
					printf("%c",(char)a[k]+'a');
				}
			}
		}
		printf("\n");
	}
}
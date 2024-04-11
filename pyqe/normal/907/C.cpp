#include <bits/stdc++.h>

using namespace std;

long long n,c=26;
bitset<26> spc,vtd;

int main()
{
	long long t,rr,i,k,z=0;
	char ch;
	string s;
	
	for(i=0;i<26;i++)
	{
		spc[i]=1;
	}
	scanf("%lld",&t);
	for(rr=0;rr<t-1;rr++)
	{
		scanf(" %ch",&ch);
		cin>>s;
		n=s.length();
		if(c>1)
		{
			vtd.reset();
			for(i=1;i<=n;i++)
			{
				k=s[i-1]-'a';
				if(ch=='!')
				{
					vtd[k]=1;
				}
				else
				{
					c-=spc[k];
					spc[k]=0;
				}
			}
			if(ch=='!')
			{
				c=0;
				for(i=0;i<26;i++)
				{
					spc[i]=spc[i]&&vtd[i];
					c+=spc[i];
				}
			}
		}
		else
		{
			z+=ch=='!'||ch=='?';
		}
	}
	printf("%lld\n",z);
}
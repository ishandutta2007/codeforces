#include <bits/stdc++.h>

using namespace std;

const long long mm=26;
long long n,m,aa[100069],a[100069];
bitset<100069> spc;
bitset<mm> vtd;

int main()
{
	long long t,rr,i,j;
	bool bad;
	string s;
	
	scanf("%lld",&t);
	for(rr=0;rr<t;rr++)
	{
		cin>>s;
		n=s.length();
		for(i=1;i<=n;i++)
		{
			aa[i]=s[i-1]-'A';
			spc[i]=0;
		}
		cin>>s;
		m=s.length();
		for(i=1;i<=m;i++)
		{
			a[i]=s[i-1]-'A';
		}
		bad=0;
		for(j=n,i=m;i;i--)
		{
			for(;j&&aa[j]!=a[i];j--);
			if(!j)
			{
				bad=1;
				break;
			}
			spc[j]=1;
			j--;
		}
		if(!bad)
		{
			vtd.reset();
			for(i=1;i<=n;i++)
			{
				if(spc[i])
				{
					vtd[aa[i]]=1;
				}
				else if(vtd[aa[i]])
				{
					bad=1;
					break;
				}
			}
		}
		if(!bad)
		{
			printf("YES\n");
		}
		else
		{
			printf("NO\n");
		}
	}
}
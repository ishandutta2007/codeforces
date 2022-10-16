#include <bits/stdc++.h>

using namespace std;

long long n,a[2][100069],fq;

int main()
{
	long long t,rr,i,ii,ls;
	string s;
	bool bad;
	
	scanf("%lld",&t);
	for(rr=0;rr<t;rr++)
	{
		scanf("%lld",&n);
		for(ii=0;ii<2;ii++)
		{
			cin>>s;
			for(i=1;i<=n;i++)
			{
				a[ii][i]=s[i-1]-'a';
			}
		}
		bad=0;
		fq=0;
		for(i=1;i<=n;i++)
		{
			if(a[0][i]!=a[1][i])
			{
				if(fq)
				{
					for(ii=0;ii<2;ii++)
					{
						if(a[ii][i]!=a[ii][ls])
						{
							bad=1;
						}
					}
				}
				fq++;
				ls=i;
			}
		}
		if(!bad&&(!fq||fq==2))
		{
			printf("Yes\n");
		}
		else
		{
			printf("No\n");
		}
	}
}
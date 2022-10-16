#include <bits/stdc++.h>

using namespace std;

long long n,fq[2][26];

int main()
{
	long long t,rr,i,ii,k;
	string s;
	bool bad;
	
	scanf("%lld",&t);
	for(rr=0;rr<t;rr++)
	{
		for(ii=0;ii<2;ii++)
		{
			cin>>s;
			n=s.length();
			for(i=1;i<=n;i++)
			{
				k=s[i-1]-'a';
				fq[ii][k]++;
			}
		}
		bad=1;
		for(i=0;i<26;i++)
		{
			if(fq[0][i]&&fq[1][i])
			{
				bad=0;
			}
			fq[0][i]=0;
			fq[1][i]=0;
		}
		if(bad)
		{
			printf("NO\n");
		}
		else
		{
			printf("YES\n");
		}
	}
}
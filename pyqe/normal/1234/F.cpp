#include <bits/stdc++.h>

using namespace std;

long long a[1000069],fq[26],il=0,dp[1<<20],n20=(1<<20)-1;

int main()
{
	long long i,j,ln,mk,mkk,mx=0;
	string s;
	
	cin>>s;
	ln=s.length();
	for(i=0;i<ln;i++)
	{
		a[i]=s[i]-'a';
	}
	for(i=1;i<=20;i++)
	{
		mk=0;
		il=0;
		for(j=0;j<26;j++)
		{
			fq[j]=0;
		}
		for(j=0;j<ln;j++)
		{
			mk+=1<<a[j];
			fq[a[j]]++;
			if(fq[a[j]]==2)
			{
				il++;
			}
			if(j>=i)
			{
				mk-=1<<a[j-i];
				fq[a[j-i]]--;
				if(fq[a[j-i]]==1)
				{
					il--;
				}
			}
			if(j>=i-1)
			{
				if(!il)
				{
					dp[mk]=i;
				}
			}
		}
	}
	for(mk=0;mk<1<<20;mk++)
	{
		for(i=0;i<20;i++)
		{
			if(mk&(1<<i))
			{
				mkk=mk-(1<<i);
				dp[mk]=max(dp[mk],dp[mkk]);
			}
		}
	}
	for(mk=0;mk<1<<20;mk++)
	{
		mx=max(mx,dp[mk]+dp[n20-mk]);
	}
	printf("%lld\n",mx);
}
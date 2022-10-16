#include <bits/stdc++.h>

using namespace std;

int n,a[3],dp[2][1<<24];
bitset<24> vtd;

int main()
{
	int i,j,mk,mkk,k,ln,c,z=0;
	string s;
	
	scanf("%d",&n);
	for(i=0;i<n;i++)
	{
		cin>>s;
		ln=0;
		vtd.reset();
		for(j=0;j<3;j++)
		{
			k=s[j]-'a';
			if(!vtd[k])
			{
				a[ln]=k;
				ln++;
				vtd[k]=1;
			}
		}
		for(mk=0;mk<1<<ln;mk++)
		{
			c=0;
			mkk=0;
			for(j=0;j<ln;j++)
			{
				k=mk>>j&1;
				c+=k;
				mkk|=k<<a[j];
			}
			if(c)
			{
				dp[0][mkk]+=(c%2)*2-1;
			}
		}
	}
	for(i=0;i<24;i++)
	{
		for(mk=0;mk<1<<24;mk++)
		{
			dp[1][mk]=dp[0][mk]+dp[0][mk^(1<<i)]*(mk>>i&1);
		}
		for(mk=0;mk<1<<24;mk++)
		{
			dp[0][mk]=dp[1][mk];
		}
	}
	for(mk=0;mk<1<<24;mk++)
	{
		z^=dp[0][mk]*dp[0][mk];
	}
	printf("%d\n",z);
}
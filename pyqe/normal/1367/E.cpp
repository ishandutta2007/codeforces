#include <bits/stdc++.h>

using namespace std;

long long n,d,fq[26];

int main()
{
	long long t,rr,i,j,gd,c;
	string s;
	
	scanf("%lld",&t);
	for(rr=0;rr<t;rr++)
	{
		scanf("%lld%lld",&n,&d);
		cin>>s;
		for(i=0;i<26;i++)
		{
			fq[i]=0;
		}
		for(i=0;i<n;i++)
		{
			fq[s[i]-'a']++;
		}
		for(i=n;1;i--)
		{
			gd=__gcd(i,d);
			c=0;
			for(j=0;j<26;j++)
			{
				c+=fq[j]/(i/gd);
			}
			if(c>=gd)
			{
				break;
			}
		}
		printf("%lld\n",i);
	}
}
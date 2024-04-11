#include <bits/stdc++.h>

using namespace std;

long long n,fq[26];

int main()
{
	long long t,rr,i,j,sz;
	string s;
	
	scanf("%lld",&t);
	for(rr=0;rr<t;rr++)
	{
		scanf("%lld",&n);
		for(i=0;i<26;i++)
		{
			fq[i]=0;
		}
		for(i=0;i<n;i++)
		{
			cin>>s;
			sz=s.length();
			for(j=0;j<sz;j++)
			{
				fq[s[j]-'a']++;
			}
		}
		for(i=0;i<26;i++)
		{
			if(fq[i]%n)
			{
				i=-1;
				break;
			}
		}
		if(i!=-1)
		{
			printf("YES\n");
		}
		else
		{
			printf("NO\n");
		}
	}
}
#include <bits/stdc++.h>

using namespace std;

long long n,a[26],fq[26];

int main()
{
	long long t,rr,i,e;
	string s;
	
	scanf("%lld",&t);
	for(rr=0;rr<t;rr++)
	{
		cin>>s;
		n=s.length();
		for(i=0;i<26;i++)
		{
			fq[i]=0;
		}
		for(i=0;i<n;i++)
		{
			a[i]=s[i]-'a';
			fq[a[i]]++;
			if(!a[i])
			{
				e=i;
			}
		}
		for(i=0;i<26;i++)
		{
			if(fq[i]>(i<n))
			{
				break;
			}
		}
		if(i<26)
		{
			printf("NO\n");
			continue;
		}
		for(i=0;i<n;i++)
		{
			if((i<e&&a[i]<a[i+1])||(i>e&&a[i]<a[i-1]))
			{
				break;
			}
		}
		if(i>=n)
		{
			printf("YES\n");
		}
		else
		{
			printf("NO\n");
		}
	}
}
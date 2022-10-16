#include <bits/stdc++.h>

using namespace std;

#define mp make_pair
#define fr first
#define sc second

long long a[200069],z[200069],n;
stack<pair<long long,long long>> sk;

int main()
{
	long long t,rr,i,l;
	bool bad;
	string s;
	
	scanf("%lld",&t);
	for(rr=0;rr<t;rr++)
	{
		scanf("%lld",&n);
		cin>>s;
		for(i=0;i<n;i++)
		{
			a[i]=s[i]-'0';
			z[i]=0;
		}
		for(i=0;i<n;i++)
		{
			for(;!sk.empty()&&sk.top().fr>a[i];sk.pop());
			sk.push({a[i],i});
		}
		for(;!sk.empty();sk.pop())
		{
			z[sk.top().sc]=1;
		}
		l=69;
		for(i=0;i<n;i++)
		{
			if(!z[i])
			{
				l=a[i];
				break;
			}
		}
		for(i=n-1;i>=0&&z[i]&&a[i]>l;i--)
		{
			z[i]=0;
		}
		bad=0;
		for(i=0;i<n;i++)
		{
			if(!z[i])
			{
				if(a[i]<l)
				{
					bad=1;
					break;
				}
				z[i]=2;
				l=a[i];
			}
		}
		if(bad)
		{
			printf("-\n");
			continue;
		}
		for(i=0;i<n;i++)
		{
			printf("%lld",z[i]);
		}
		printf("\n");
	}
}
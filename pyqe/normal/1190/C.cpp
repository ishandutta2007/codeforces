#include <bits/stdc++.h>

using namespace std;

long long n,d;
bitset<100069> a;
multiset<long long> ms[2];
multiset<long long>::iterator it;

int main()
{
	long long i,ii;
	string s;
	bool bad=1;
	
	scanf("%lld%lld",&n,&d);
	cin>>s;
	for(i=0;i<n;i++)
	{
		a[i]=s[i]-'0';
		ms[a[i]].insert(i);
	}
	for(ii=0;ii<2;ii++)
	{
		for(i=0;i<n+d;i++)
		{
			if(i<n&&a[i]==ii)
			{
				ms[ii].erase(ms[ii].find(i));
			}
			if(i>=d&&a[i-d]==ii)
			{
				ms[ii].insert(i-d);
			}
			if(i>=d-1&&i<n)
			{
				if(ms[ii].empty())
				{
					printf("tokitsukaze\n");
					return 0;
				}
				it=ms[ii].end();
				it--;
				if(*it-*ms[ii].begin()+1>d)
				{
					bad=0;
				}
			}
		}
	}
	if(bad)
	{
		printf("quailty\n");
	}
	else
	{
		printf("once again\n");
	}
}
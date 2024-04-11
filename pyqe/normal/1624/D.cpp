#include <bits/stdc++.h>

using namespace std;

const long long mm=26;
long long n,d,fq[mm];

int main()
{
	long long t,rr,i,sm;
	char ch;
	
	scanf("%lld",&t);
	for(rr=0;rr<t;rr++)
	{
		scanf("%lld%lld",&n,&d);
		for(i=0;i<mm;i++)
		{
			fq[i]=0;
		}
		for(i=0;i<n;i++)
		{
			scanf(" %c",&ch);
			fq[ch-'a']++;
		}
		sm=0;
		for(i=0;i<mm;i++)
		{
			sm+=fq[i]/2;
		}
		printf("%lld\n",sm/d*2+(n-sm/d*d*2>=d));
	}
}
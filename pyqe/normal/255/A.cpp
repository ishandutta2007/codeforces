#include <bits/stdc++.h>

using namespace std;

long long n,fq[3];
string ky[3]={"chest","biceps","back"};

int main()
{
	long long i,k,mx=-1e18;
	
	scanf("%lld",&n);
	for(i=0;i<n;i++)
	{
		scanf("%lld",&k);
		fq[i%3]+=k;
	}
	for(i=0;i<3;i++)
	{
		mx=max(mx,fq[i]);
	}
	for(i=0;i<3;i++)
	{
		if(fq[i]==mx)
		{
			printf("%s\n",ky[i].c_str());
		}
	}
}
#include <bits/stdc++.h>

using namespace std;

long long n,inf=1e9;
bool a0;

int main()
{
	long long i,k,lh,rh,md;
	string s;
	
	scanf("%lld",&n);
	printf("%lld 0\n",inf/2);
	fflush(stdout);
	cin>>s;
	a0=s[0]=='w';
	for(i=0,lh=1,rh=inf;i<n-1;i++)
	{
		md=(lh+rh)/2;
		printf("%lld %lld\n",inf/2,md);
		fflush(stdout);
		cin>>s;
		k=s[0]=='w';
		if(k==a0)
		{
			lh=md+1;
		}
		else
		{
			rh=md-1;
		}
	}
	printf("0 %lld %lld %lld\n",lh,inf,rh);
}
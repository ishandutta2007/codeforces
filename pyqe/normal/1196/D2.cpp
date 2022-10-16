#include <bits/stdc++.h>

using namespace std;

long long n,d,a[200069],ps[3][200069];
map<char,long long> ky;

int main()
{
	long long t,rr,i,ii,mn;
	string s;
	
	ky['R']=0;
	ky['G']=1;
	ky['B']=2;
	scanf("%lld",&t);
	for(rr=0;rr<t;rr++)
	{
		scanf("%lld%lld",&n,&d);
		cin>>s;
		for(i=1;i<=n;i++)
		{
			a[i]=ky[s[i-1]];
		}
		for(i=1;i<=n;i++)
		{
			for(ii=0;ii<3;ii++)
			{
				ps[ii][i]=ps[ii][i-1];
			}
			ps[(a[i]+n-i)%3][i]++;
		}
		mn=1e18;
		for(i=d;i<=n;i++)
		{
			for(ii=0;ii<3;ii++)
			{
				mn=min(mn,d-(ps[ii][i]-ps[ii][i-d]));
			}
		}
		printf("%lld\n",mn);
	}
}
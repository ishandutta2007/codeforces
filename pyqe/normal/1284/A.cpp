#include <bits/stdc++.h>

using namespace std;

long long n[2];
string s[2][100069];

int main()
{
	long long t,rr,i,ii,k;
	
	for(ii=0;ii<2;ii++)
	{
		scanf("%lld",n+ii);
	}
	for(ii=0;ii<2;ii++)
	{
		for(i=0;i<n[ii];i++)
		{
			cin>>s[ii][i];
		}
	}
	scanf("%lld",&t);
	for(rr=0;rr<t;rr++)
	{
		scanf("%lld",&k);
		k--;
		printf("%s%s\n",s[0][k%n[0]].c_str(),s[1][k%n[1]].c_str());
	}
}
#include <bits/stdc++.h>

using namespace std;

long long n;
bitset<1000069> a[2],vtd;

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	long long i,ii,z=0;
	string s;
	
	cin>>n;
	for(ii=0;ii<2;ii++)
	{
		cin>>s;
		for(i=1;i<=n;i++)
		{
			a[ii][i]=s[i-1]-'0';
		}
	}
	for(i=1;i<=n;i++)
	{
		if(a[0][i]!=a[1][i]&&!(i>1&&a[0][i]!=a[0][i-1]&&vtd[i-1]))
		{
			z++;
			vtd[i]=1;
		}
	}
	printf("%lld\n",z);
}
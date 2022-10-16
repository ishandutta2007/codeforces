#include <bits/stdc++.h>

using namespace std;

long long n,yk[269];
string ky="0123456789ABCDEF";
bitset<20069> a[20069],spc;

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	long long i,j,r,k,z=0;
	string s;
	
	for(i=0;i<16;i++)
	{
		yk[ky[i]]=i;
	}
	cin>>n;
	for(i=1;i<=n;i++)
	{
		cin>>s;
		for(j=1;j<=n/4;j++)
		{
			k=yk[s[j-1]];
			for(r=0;r<4;r++,k/=2)
			{
				a[i][j*4-r]=k&1;
			}
		}
	}
	for(i=1;i<=n;i++)
	{
		for(j=1;j<=n;j++)
		{
			spc[j]=spc[j]||j==n||a[i][j]!=a[i][j+1];
			spc[i]=spc[i]||i==n||a[i][j]!=a[i+1][j];
		}
	}
	for(i=1;i<=n;i++)
	{
		if(spc[i])
		{
			z=__gcd(z,i);
		}
	}
	cout<<z<<"\n";
}
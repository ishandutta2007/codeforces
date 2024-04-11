#include <bits/stdc++.h>

using namespace std;

long long n,d[169][2];
bitset<169> a;

int main()
{
	long long i,j,mx=0,k;
	string s;
	
	scanf("%lld",&n);
	cin>>s;
	for(i=0;i<n;i++)
	{
		a[i]=s[i]-'0';
		mx+=a[i];
	}
	for(i=0;i<n;i++)
	{
		for(j=0;j<2;j++)
		{
			scanf("%lld",&d[i][j]);
		}
	}
	for(i=1;i<=100000;i++)
	{
		k=0;
		for(j=0;j<n;j++)
		{
			if(i>=d[j][1]&&(i-d[j][1])%d[j][0]==0)
			{
				a[j]=!a[j];
			}
			k+=a[j];
		}
		mx=max(mx,k);
	}
	printf("%lld\n",mx);
}
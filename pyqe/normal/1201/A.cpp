#include <bits/stdc++.h>

using namespace std;

long long n,m,fq[1069][5],mx[1069];

int main()
{
	long long i,j,k,z=0;
	string s;
	
	scanf("%lld%lld",&n,&m);
	for(i=1;i<=n;i++)
	{
		cin>>s;
		for(j=1;j<=m;j++)
		{
			k=s[j-1]-'A';
			fq[j][k]++;
			mx[j]=max(mx[j],fq[j][k]);
		}
	}
	for(i=1;i<=m;i++)
	{
		scanf("%lld",&k);
		z+=k*mx[i];
	}
	printf("%lld\n",z);
}
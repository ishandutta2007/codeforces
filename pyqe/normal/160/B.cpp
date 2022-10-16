#include <bits/stdc++.h>

using namespace std;

long long n,a[2][100069],fq[2];

int main()
{
	long long i,ii;
	string s;
	
	scanf("%lld",&n);
	cin>>s;
	for(i=0;i<n*2;i++)
	{
		a[i/n][i%n]=s[i]-'0';
	}
	for(ii=0;ii<2;ii++)
	{
		sort(a[ii],a[ii]+n);
	}
	for(i=0;i<n;i++)
	{
		if(a[0][i]!=a[1][i])
		{
			fq[a[0][i]<a[1][i]]++;
		}
	}
	if(fq[0]==n||fq[1]==n)
	{
		printf("YES\n");
	}
	else
	{
		printf("NO\n");
	}
}
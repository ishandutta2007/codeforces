#include <bits/stdc++.h>

using namespace std;

long long n,a[1000069],al[1000069][2];
bitset<1000069> dp,spc;

long long qr(long long x)
{
	if(a[x]==1)
	{
		return dp[al[x][0]]&&dp[al[x][1]];
	}
	else if(a[x]==2)
	{
		return dp[al[x][0]]||dp[al[x][1]];
	}
	else if(a[x]==3)
	{
		return dp[al[x][0]]^dp[al[x][1]];
	}
	else if(a[x]==4)
	{
		return !dp[al[x][0]];
	}
	else
	{
		return dp[x];
	}
}

void bd(long long x)
{
	long long i,l;
	
	for(i=0;i<2&&al[x][i];i++)
	{
		l=al[x][i];
		bd(l);
	}
	dp[x]=qr(x);
}

void bd2(long long x)
{
	long long i,k,l;
	
	spc[x]=1;
	for(i=0;i<2&&al[x][i];i++)
	{
		l=al[x][i];
		dp[l]=!dp[l];
		k=qr(x);
		dp[l]=!dp[l];
		if(k!=dp[x])
		{
			bd2(l);
		}
	}
}

int main()
{
	long long i;
	string s;
	
	scanf("%lld",&n);
	for(i=1;i<=n;i++)
	{
		cin>>s;
		scanf("%lld",&al[i][0]);
		if(s[0]=='A')
		{
			scanf("%lld",&al[i][1]);
			a[i]=1;
		}
		else if(s[0]=='O')
		{
			scanf("%lld",&al[i][1]);
			a[i]=2;
		}
		else if(s[0]=='X')
		{
			scanf("%lld",&al[i][1]);
			a[i]=3;
		}
		else if(s[0]=='N')
		{
			a[i]=4;
		}
		else
		{
			a[i]=5;
			dp[i]=al[i][0];
			al[i][0]=0;
		}
	}
	bd(1);
	bd2(1);
	for(i=1;i<=n;i++)
	{
		if(a[i]==5)
		{
			printf("%lld",(long long)dp[1]^spc[i]);
		}
	}
	printf("\n");
}
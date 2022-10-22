#include<cstdio>
#include<iostream>
#include<algorithm>
#include<cstring>
using namespace std;

char s0[101]="What are you doing at the end of the world? Are you busy? Will you save us?";

char f[101]="What are you doing while sending \"";

char s[101]="\"? Are you busy? Will you send \"";

char l[101]="\"?";

long long dp[100001];

int lf=strlen(f),ls=strlen(s),ll=strlen(l);

char solve(int n,long long k)
{
	if(k>dp[n])
		return '.';
	if(!n)
		return s0[k-1];
	if(k<=lf)
		return f[k-1];
	k-=lf;
	if(k<=dp[n-1])
		return solve(n-1,k);
	k-=dp[n-1];
	if(k<=ls)
		return s[k-1];
	k-=ls;
	if(k<=dp[n-1])
		return solve(n-1,k);
	k-=dp[n-1];
	if(k<=ll)
		return l[k-1];
	return '.';
}

int main()
{
	dp[0]=strlen(s0);
	int len=lf+ls+ll;
	for(int i=1;i<=100000;i++)
	{
		dp[i]=dp[i-1]*2+len;
		if(dp[i]>(long long)1e18)
			dp[i]=2e18;
	}
	int q;
	scanf("%d",&q);
	while(q--)
	{
		int n;
		long long k;
		scanf("%d%lld",&n,&k);
		cout<<solve(n,k);
	}
}
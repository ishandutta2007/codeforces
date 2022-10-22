#include<cstdio>
#include<algorithm>
#include<cstring>
#include<iostream>
using namespace std;

const int N=1e6+1e3+7,P=1e9+7;

int pr[N],a[N],n,cnt[N],ct;

long long g[N],f[2][N],bit[N];

bool isprime(int x)
{
	if(x==1)
		return false;
	for(int i=2;i*i<=x;i++)
		if(x%i==0)
			return false;
	return true;
}

long long qpow(long long a,long long b)
{
	long long ret=1;
	while(b)
	{
		if(b&1)
			ret=ret*a%P;
		b>>=1;
		a=a*a%P;
	}
	return ret;
}

int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
		scanf("%d",&a[i]),cnt[a[i]]++;
	bit[0]=1;
	for(int i=1;i<=n;i++)
		bit[i]=bit[i-1]*2%P;
	for(int i=2;i<=70;i++)
		if(isprime(i))
			pr[++ct]=i;
	for(int i=1;i<=70;i++)
	{
		int x=i;
		for(int j=1;j<=ct;j++)
			while(x%pr[j]==0)
				g[i]^=(1<<(j-1)),x/=pr[j];
	}
	int cur=0,last=1;
	f[cur][0]=1;
	for(int i=1;i<=70;i++)
	{
		swap(cur,last);
		for(int j=0;j<=(1<<ct)-1;j++)
		{
			if(!cnt[i])
			{
				f[cur][j]=f[last][j];
				continue;
			}
			long long k=bit[cnt[i]-1];
			f[cur][j]=(f[last][j]*k%P+f[last][j^g[i]]*k%P)%P;
		}
		
	}
	printf("%lld",f[cur][0]-1);
}
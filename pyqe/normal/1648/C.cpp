#include <bits/stdc++.h>

using namespace std;

const long long ma=2e5,dv=998244353;
long long n,m,fq[200069],fc[200069],fw[200069],fi,pwk;

long long pw(long long x,long long y)
{
	if(!y)
	{
		return 1;
	}
	pwk=pw(x,y/2);
	pwk=pwk*pwk%dv;
	if(y%2)
	{
		pwk=pwk*x%dv;
	}
	return pwk;
}

inline void ud(long long x,long long w)
{
	for(fi=x;fi<=ma;fi+=fi&-fi)
	{
		fw[fi]+=w;
	}
}

inline long long qr(long long x)
{
	long long z=0;
	
	for(fi=x;fi;fi-=fi&-fi)
	{
		z+=fw[fi];
	}
	return z;
}

int main()
{
	long long i,k,ml=1,z=0;
	
	scanf("%lld%lld",&n,&m);
	fc[0]=1;
	for(i=1;i<=n;i++)
	{
		fc[i]=fc[i-1]*i%dv;
	}
	for(i=1;i<=n;i++)
	{
		scanf("%lld",&k);
		fq[k]++;
		ml=ml*pw(fq[k],dv-2)%dv;
		ud(k,1);
	}
	for(i=1;i<=min(n,m);i++)
	{
		scanf("%lld",&k);
		z=(z+fc[n-i]*ml%dv*qr(k-1))%dv;
		if(!fq[k])
		{
			break;
		}
		ml=ml*fq[k]%dv;
		fq[k]--;
		ud(k,-1);
	}
	if(i>min(n,m)&&m>n)
	{
		z=(z+1)%dv;
	}
	printf("%lld\n",z);
}
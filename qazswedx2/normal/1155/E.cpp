#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
typedef long long ll;
ll n=11,a[2000005],inv[2000005],mod=1e6+3,infr[2000005],fr[2000005];
ll fpow(ll x,ll y)
{
	ll ans=1;
	while(y)
	{
		if(y&1) ans=ans*x%mod;
		x=x*x%mod;
		y/=2;
	}
	return ans;
}
/*ll getf(ll x)
{
	ll ans=0;
	for(int i=0;i<n;i++)
	{
		ll mul=a[i];
		for(int j=0;j<n;j++)
			if(j!=i)
			{
				if(i<j) mul=(mod-mul*(x-j)%mod*inv[j-i]%mod)%mod;
				else mul=mul*(x-j)%mod*inv[i-j]%mod;
			}
		ans=(ans+mul+mod)%mod;
	}
	return ans;
}*/
ll getf(ll x)
{
	ll ans=0,mul=1;
	for(int i=0;i<n;i++)
		mul=mul*(x-i)%mod;
	mul=(mul%mod+mod)%mod;
	for(int i=0;i<n;i++)
	{
		mul=mul*inv[x-i]%mod;
		ans=(ans+a[i]*mul%mod*infr[i]%mod*infr[n-i-1]%mod*(i%2?1:-1)%mod+mod)%mod;
		mul=mul*(x-i)%mod;
	} 
	return ans;
}
int main()
{
	fr[0]=infr[0]=1;
	for(int i=1;i<=n;i++)
	{
		printf("? %d\n",i-1);
		fflush(stdout);
		scanf("%I64d",&a[i-1]);
		if(a[i-1]==0)
		{
			printf("! %d\n",i-1);
			fflush(stdout);
			return 0;
		}
	}
	for(int i=1;i<mod;i++)
	{
		//printf("i=%d\n",i);
		inv[i]=fpow(i,mod-2);
		fr[i]=fr[i-1]*i%mod;
		infr[i]=fpow(fr[i],mod-2);
		//if(i<30) printf("i=%d,inv=%I64d,fr=%I64d,infr=%I64d\n",i,inv[i],fr[i],infr[i]);
	}
	//for(int i=30;i<=40;i++)
	//	printf("f=%I64d\n",getf(i));
	for(int i=n;i<mod;i++)
	{
		//if(i!=0&&i<n) continue;
		if(!getf(i))
		{
			printf("! %d\n",i);
			fflush(stdout);
			return 0;
		}
	}
	printf("! -1\n");
	fflush(stdout);
	return 0;
}
//ANMHLIJKTJIY!
#pragma GCC optimize(2)
#include <bits/stdc++.h>
#define INF 1000000000
#define LINF 1000000000000000000
#define MOD 1000000007
#define mod 998244353
#define F first
#define S second
#define ll long long
#define N 600010
using namespace std;
ll rint(){
	ll ret=0;
	char c=getchar();
	while(!isdigit(c)) c=getchar();
	while(isdigit(c)) ret=ret*10+(c-'0'),c=getchar();
	return ret;
}
ll n,m,sum[N],vis[N],pre=0;
ll getsum(ll l,ll r)
{
	ll dif=r-l+1,i,nl=0,nr=0;
	for(i=0;i<20;i++)
	{
		if((1<<i)>=dif)
		{
			nl+=((pre^l)&(1<<i));
			nr+=((pre^l)&(1<<i));
		}
		else
		{
			nr+=(1<<i);
		}
	}
	return sum[nr]-(nl==0?0:sum[nl-1]);
}
int main(){
	ll i,x;
	n=rint(),m=rint();
	for(i=0;i<n;i++)
	{
		x=rint();
		vis[x]=1;
	}
	sum[0]=vis[0];
	for(i=1;i<N;i++)
	{
		sum[i]=sum[i-1]+vis[i];
	}
	while(m--)
	{
		x=rint();
		pre^=x;
		ll res=0;
		for(i=19;i>=0;i--)
		{
			if(getsum(res,res+(1<<i)-1)==(1<<i))
			{
				res+=(1<<i);
			}
		}
		printf("%lld\n",res);
	}
	return 0;
}
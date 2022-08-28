#include<cstdio>
#include<cstdlib>
#include<algorithm>
using namespace std;
typedef long long ll;
ll n,b,ans=-1;
ll cntzo(ll x,ll y)
{
	//printf("%lld,%lld\n",x,y);
	if(x/y==0) return 0;
	return x/y+cntzo(x/y,y);
}
int main()
{
	scanf("%I64d%I64d",&n,&b);
	for(ll i=2;i*i<=b;i++)
	{
		ll nans=0,c;
		while(b%i==0)
		{
			b/=i;
			nans++;
		}
		if(nans==0) continue;
		c=cntzo(n,i)/nans;
		if(ans==-1) ans=c;
		else if(c<ans) ans=c;
		//printf("i=%lld,b=%lld\n",i,b);
	} 
	if(b!=1)
	{
		ll c;
		c=cntzo(n,b);
		if(ans==-1) ans=c;
		else if(c<ans) ans=c;
	}
	printf("%I64d",ans);
	return 0;
}
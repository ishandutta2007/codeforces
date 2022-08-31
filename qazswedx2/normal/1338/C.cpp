#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
typedef long long ll;
ll n;
int qwq[4]={0,2,3,1};
int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
	scanf("%lld",&n);
	ll a=(n-1)/3+1;
	int b=n%3;
	ll lim=1;
	while(lim/3<a) lim*=4;
	lim/=4;
	ll dis=(a-lim/3-1),nw=0;
	for(ll j=60;j>=0;j-=2)
		nw+=((ll)qwq[(dis>>j)&3])<<j;
	ll f=lim+dis,f2=lim*2+nw;
	//printf("a=%lld,lim=%lld,dis=%lld,f=%lld,f2=%lld\n",a,lim,dis,f,f2);
	if(b==1) printf("%lld\n",f);
	else if(b==2) printf("%lld\n",f2);
	else printf("%lld\n",f^f2);
	}
	return 0; 
}
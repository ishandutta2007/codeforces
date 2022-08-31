#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
typedef long long ll;
struct pt
{
	int id,val;
	pt(int id=0,int val=0):id(id),val(val){}
	bool operator<(const pt x) const
	{
		return val<x.val;
	}
}p[1000005];
int tt,n,m,a,b;
int main()
{
	scanf("%d",&tt);
	while(tt--)
	{
		scanf("%d%d%d%d",&n,&m,&a,&b);
		ll ctb=0,cta=0,suma=0,sumb=0;
		for(int i=1;i<=n;i++)
		{
			scanf("%d",&p[i].id);
			if(!p[i].id) suma++;
			else sumb++;
		}
		for(int i=1;i<=n;i++)
			scanf("%d",&p[i].val);
		sort(p+1,p+n+1);
		p[n+1].val=m+1;
		ll tans=0;
		for(int i=1;i<=n+1;i++)
		{
			ll nw=1ll*ctb*b+1ll*cta*a;
			if(nw>=p[i].val) 
			{
				if(!p[i].id) cta++;
				else ctb++;
				continue;
			}
			//printf("cta=%d,ctb=%d,nw=%lld\n",cta,ctb,nw);
			nw=p[i].val-1-nw;
			if(nw/a<=suma-cta) tans=max(tans,cta+ctb+nw/a);
			else
			{
				nw-=(suma-cta)*a;
				tans=max(tans,suma+ctb+min(sumb-ctb,nw/b));
			}
			if(!p[i].id) cta++;
			else ctb++;
		}
		printf("%I64d\n",tans);
	}
	return 0;
}
#include <bits/stdc++.h>
#define INF 1000000000
#define LINF 1000000000000000000
#define MOD 1000000007
#define mod 1000007
#define INF63 1061109567
#define INF127 9187201950435737471
#define UINF 18446744073709551615
#define F first
#define S second
#define ll long long
#define N 100010
using namespace std;
ll n,a,r,m,qdh[N],aa[N],rr[N],dif[N],df[N],ans=LINF;
vector<ll> h;
int main(){
	ll i,j,cla,clr;
	scanf("%lld%lld%lld%lld",&n,&a,&r,&m);
	for(i=0;i<n;i++)
	{
		scanf("%lld",&j);
		h.push_back(j);
	}
	sort(h.begin(),h.end());
	for(i=0;i<n;i++)
	{
		if(i==0)
		{
			qdh[i]=h[i];
		}
		else
		{
			qdh[i]=qdh[i-1]+h[i];
		}
	}
	for(i=0;i<n;i++)
	{
		aa[i]=h[i]*(i+1)-qdh[i];
		if(i>0)
		{
			rr[i]=qdh[n-1]-qdh[i-1]-h[i]*(n-i);
		}
		else
		{
			rr[i]=qdh[n-1]-h[i]*(n-i);
		}
		ans=min(ans,aa[i]*a+rr[i]*r);
		if(aa[i]>rr[i])
		{
			ans=min(ans,rr[i]*m+(aa[i]-rr[i])*a);
		}
		else
		{
			ans=min(ans,aa[i]*m+(rr[i]-aa[i])*r);
		}
		dif[i]=rr[i]-aa[i];
	}
	if(m<a+r)
	{
		for(i=0;i+1<n;i++)
		{
			if(dif[i]>=0&&dif[i+1]<=0)
			{
				j=dif[i]/n;
				clr=rr[i]-j*(n-i-1);
				cla=aa[i]+j*(i+1);
				if(cla<=aa[i+1]&&clr>=rr[i+1])
				{
					if(cla>clr)
					{
						ans=min(ans,clr*m+(cla-clr)*a);
					}
					else
					{
						ans=min(ans,cla*m+(clr-cla)*r);
					}
				}
				j++;
				clr=rr[i]-j*(n-i-1);
				cla=aa[i]+j*(i+1);
				if(cla<=aa[i+1]&&clr>=rr[i+1])
				{
					if(cla>clr)
					{
						ans=min(ans,clr*m+(cla-clr)*a);
					}
					else
					{
						ans=min(ans,cla*m+(clr-cla)*r);
					}
				}
				j-=2;
				clr=rr[i]-j*(n-i-1);
				cla=aa[i]+j*(i+1);
				if(cla<=aa[i+1]&&clr>=rr[i+1])
				{
					if(cla>clr)
					{
						ans=min(ans,clr*m+(cla-clr)*a);
					}
					else
					{
						ans=min(ans,cla*m+(clr-cla)*r);
					}
				}
			}
		}
	}
	printf("%lld\n",ans);
	return 0;
}
#include<bits/stdc++.h>
using namespace std;

int n,tp,sk[1000010],po[1000010],l,r,mid,an,nwk;
long long sb[1000010],nwb,ans;
struct node{int x,y; long long val;}a[1000010];
bool cmp(node a,node b) {return a.x<b.x;}

int main()
{
	scanf("%d",&n),ans=0;
	for (int i=1; i<=n; i++) scanf("%d%d%I64d",&a[i].x,&a[i].y,&a[i].val);
	sort(a+1,a+1+n,cmp),tp=0;
	sb[++tp]=0,sk[tp]=0,po[tp]=1000000000;
	for (int i=1; i<=n; i++)
	{
		l=1,r=tp;
		while (l<=r)
		{
			mid=(l+r)>>1;
			if (po[mid]>=a[i].y) an=mid,l=mid+1; else r=mid-1;
		}
		nwb=1ll*sk[an]*a[i].y+1ll*a[i].x*a[i].y-a[i].val+sb[an];
		ans=max(ans,nwb),nwk=-a[i].x;
		while (tp)
		{
			if (1ll*po[tp]*sk[tp]+sb[tp]<=1ll*po[tp]*nwk+nwb) {tp--; continue;}
			if (sb[tp]>=nwb) break;
			int p=(nwb-sb[tp])/(sk[tp]-nwk);
			sk[++tp]=nwk,sb[tp]=nwb,po[tp]=p;
			break;
		}
		if (!tp) sk[++tp]=nwk,sb[tp]=nwb;
	}
	printf("%I64d\n",ans);
	return 0;
}
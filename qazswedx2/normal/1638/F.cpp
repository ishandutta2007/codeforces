#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
typedef long long ll;
int n,L[100005],R[100005],st[100005],tp;
ll a[100005],pre[100005],suf[100005];
int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
		scanf("%lld",&a[i]);
	tp=0;
	for(int i=1;i<=n;i++)
	{
		while(tp&&a[st[tp]]>=a[i]) tp--;
		L[i]=st[tp]+1;
		st[++tp]=i; 
	}
	tp=0;
	st[tp]=n+1;
	for(int i=n;i>0;i--)
	{
		while(tp&&a[st[tp]]>=a[i]) tp--;
		R[i]=st[tp]-1;
		st[++tp]=i;
	}
	ll ans=0;
	for(int i=1;i<=n;i++)
	{
		ans=max(ans,(R[i]-L[i]+1)*a[i]);
		for(int j=i+1;j<=n;j++)
		{
			ans=max(ans,(R[i]-L[i]+1)*a[i]+(R[j]-L[j]+1)*a[j]-max(min(R[i],R[j])-max(L[i],L[j])+1,0)*min(a[i],a[j]));
		}
	}
	for(int i=1;i<=n;i++)
	{
		int l=L[i],r=R[i];
		pre[l]=a[i];
		for(int j=l-1;j>0;j--)
			pre[j]=min(pre[j+1],a[j]);
		suf[r]=a[i];
		for(int j=r+1;j<=n;j++)
			suf[j]=min(suf[j-1],a[j]);
		int nw=n;
		ll q=-1e18;
		for(int j=l-1;j>0;j--)
		{
			while(pre[j]+suf[nw]<a[i])
			{
				q=max(q,(nw-l+1)*suf[nw]);
				nw--;
			}
			ans=max(ans,q+(r-j+1)*pre[j]);
			ans=max(ans,(l-j)*pre[j]+(nw-r)*(a[i]-pre[j])+(r-l+1)*a[i]);
		}
		nw=1,q=-1e18;
		for(int j=r+1;j<=n;j++)
		{
			while(pre[nw]+suf[j]<a[i])
				nw++;
			ans=max(ans,(l-nw)*(a[i]-suf[j])+(j-r)*suf[j]+(r-l+1)*a[i]);
		}
	}
	printf("%lld\n",ans);
	return 0;
}
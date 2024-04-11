#include<bits/stdc++.h>
using namespace std;

int a[100010],h[100010],n,m,k,p,t[5010];
long long l,r,mid,ans,sum,cnt;

bool check(long long mid)
{
	sum=0;
	memset(t,0,sizeof(t));
	for (int i=1; i<=n; i++)
	{
		if (mid>=h[i]+1ll*a[i]*m) cnt=0;
		else cnt=(h[i]+1ll*a[i]*m-mid+p-1)/p;
		if ((sum+=cnt)>m*k) return 0;
		for (int j=1; j<=cnt; j++) 
			if ((mid+1ll*(j-1)*p)/a[i]<m) t[(mid+1ll*(j-1)*p)/a[i]]++;
	}
	int nw=0;
	for (int i=0; i<m; i++) 
	{
		nw+=t[i];
		if (nw>i*k) return 0;
	}
	return 1;
}

int main()
{
	scanf("%d%d%d%d",&n,&m,&k,&p);
	for (int i=1; i<=n; i++) scanf("%d%d",&h[i],&a[i]);
	l=0,r=10000000000000ll,ans=-1;
	while (l<=r)
	{
		mid=(l+r)>>1;
		if (check(mid)) r=mid-1,ans=mid; else l=mid+1;
	}
	printf("%I64d\n",ans);
	return 0;
}
#include<cstdio>
#include<cstring>
#include<algorithm>

using namespace std;

int l,r,n,a[300001],k,mid,ans,s,la,ll,rr,midd,anss,f[300001],mi[300001];
bool bo[300002];

bool check(int x)
{
	for (int i=1; i<=n-k+1; i++)
	{
		ll=i+1; rr=n; anss=i; 
		while (ll<=rr)
		{
			midd=(ll+rr)>>1;
			if (a[midd]-a[i]<=x) ll=midd+1,anss=midd; else rr=midd-1;
		}
		f[i]=anss;
	}
	for (int i=1; i<=k; i++) mi[i]=1;
	for (int i=k+1; i<=n-k+1; i++)
		if (f[mi[i-k]]+1>=i) mi[i]=i;
		else mi[i]=mi[i-1];
	return f[mi[n-k+1]]==n;
}

int main()
{
	scanf("%d%d",&n,&k);
	for (int i=1; i<=n; i++) scanf("%d",&a[i]);
	sort(a+1,a+1+n);
	l=0; r=a[n]-a[1];
	while (l<=r)
	{
		mid=(l+r)>>1;
		if (check(mid)) ans=mid,r=mid-1; else l=mid+1;
	}
	printf("%d\n",ans);
	return 0;
}
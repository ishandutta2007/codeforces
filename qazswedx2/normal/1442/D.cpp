#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
typedef long long ll;
int n,m,len[3005];
ll sum[3005],a[3005][3005],f[3005],st[5000005][2],ans;
int tp;
void upd(int x)
{
	for(int i=m;i>=len[x];i--)
	{
		ll q=f[i-len[x]]+sum[x];
		if(q>f[i])
		{
			st[++tp][0]=i;
			st[tp][1]=f[i];
			f[i]=q;
		}
	}
}
void getback(int x)
{
	while(tp>x)
	{
		f[st[tp][0]]=st[tp][1];
		tp--;
	}
}
void solve(int l,int r)
{
	if(l==r)
	{
		for(int i=0;i<=m;i++)
			ans=max(ans,f[i]+a[l][m-i]);
		return;
	}
	int mid=(l+r)/2,las=tp;
	for(int i=l;i<=mid;i++)
		upd(i);
	solve(mid+1,r);
	getback(las);
	for(int i=mid+1;i<=r;i++)
		upd(i);
	solve(l,mid);
	getback(las);
}
int main()
{
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&len[i]);
		for(int j=1;j<=min(m,len[i]);j++)
		{
			scanf("%lld",&a[i][j]),sum[i]+=a[i][j];
			a[i][j]+=a[i][j-1];
		}
		for(int j=min(m,len[i])+1;j<=len[i];j++)
		{
			int x;
			scanf("%d",&x);
		}
		len[i]=min(len[i],m);
	}
	solve(1,n);
	printf("%lld\n",ans);
	return 0;
}
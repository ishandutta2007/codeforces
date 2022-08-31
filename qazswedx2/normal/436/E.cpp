#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
typedef long long ll;
struct pt
{
	int x,y,id;
}a[1000005],b[1000005],f[1000005];
int n,m,bt,ft,pre[1000005],suf[1000005],vis[1000005];
ll sumb[1000005],sumf[1000005];
bool cmp(const pt p,const pt q)
{
	return p.x+p.y<q.x+q.y;
}
int main()
{
	memset(suf,0x3f,sizeof(suf));
	memset(sumb,0x3f,sizeof(sumb));
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++)
		scanf("%d%d",&a[i].x,&a[i].y),a[i].y-=a[i].x,a[i].id=i;
	for(int i=1;i<=n;i++)
		if(a[i].x>=a[i].y) b[++bt]=a[i];
		else
		{
			f[++ft].x=a[i].x;
			f[ft].id=i;
			f[++ft].x=a[i].y;
			f[ft].id=i;
		}
	sort(f+1,f+ft+1,cmp);
	sort(b+1,b+bt+1,cmp);
	for(int i=1;i<=bt;i++)
		pre[i]=b[i].y,suf[i]=b[i].x;
	for(int i=1;i<=bt;i++)
		pre[i]=max(pre[i],pre[i-1]);
	for(int i=bt-1;i>0;i--)
		suf[i]=min(suf[i],suf[i+1]);
	for(int i=1;i<=ft;i++)
		sumf[i]=f[i].x+sumf[i-1];
	sumb[0]=0;
	for(int i=1;i<=bt;i++)
		sumb[i]=b[i].x+b[i].y+sumb[i-1];
//	for(int i=1;i<=bt;i++)
	//	printf("i=%d,pre=%d,suf=%d,sumb=%lld\n",i,pre[i],suf[i],sumb[i]);
	ll tans=1e18;
	int id=0;
	//printf("ft=%d,bt=%d\n",ft,bt);
	for(int i=0;i<=ft&&i<=m;i++)
	{
		int nw=m-i;
		ll nans=sumf[i];
		if(nw%2==0) nans+=sumb[nw/2];
		else nans+=min(sumb[nw/2]+suf[nw/2+1],sumb[nw/2+1]-pre[nw/2+1]);
	//	printf("i=%d,nans=%lld,nw=%d\n",i,nans,nw);
		if(nans<tans)
		{
			tans=nans;
			id=i;
		}
	}
	printf("%lld\n",tans);
	int nw=m-id;
	for(int i=1;i<=id;i++)
		vis[f[i].id]++;
	if(nw%2==0)
	{
		for(int i=1;i<=nw/2;i++)
			vis[b[i].id]+=2;
	}
	else
	{
		if(sumb[nw/2]+suf[nw/2+1]<sumb[nw/2+1]-pre[nw/2+1])
		{
			for(int i=1;i<=nw/2;i++)
				vis[b[i].id]+=2;
			for(int i=nw/2+1;i<=n;i++)
				if(b[i].x==suf[nw/2+1])
				{
					vis[b[i].id]++;
					break;
				}
		}
		else
		{
			for(int i=1;i<=nw/2+1;i++)
				vis[b[i].id]+=2;
			for(int i=1;i<=nw/2+1;i++)
				if(b[i].y==pre[nw/2+1])
				{
					vis[b[i].id]--;
					break;
				}
		}
	}
	for(int i=1;i<=n;i++)
		printf("%d",vis[i]);
	return 0;
}
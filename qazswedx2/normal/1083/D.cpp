#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
typedef long long ll;
const int mod=1e9+7;
ll sum[1000005][3],lazy[1000005][2];
void pushup(int x)
{
	sum[x][0]=sum[x*2][0]+sum[x*2+1][0];
	sum[x][1]=sum[x*2][1]+sum[x*2+1][1];
	sum[x][2]=sum[x*2][2]+sum[x*2+1][2];
}
void col0(int x,int l,int r,ll v)
{
	sum[x][0]+=(r-l+1)*v;
	sum[x][2]+=sum[x][1]*v;
	lazy[x][0]+=v;
}
void col1(int x,int l,int r,ll v)
{
	sum[x][1]+=(r-l+1)*v;
	sum[x][2]+=sum[x][0]*v;
	lazy[x][1]+=v;
}
void pushdown(int x,int l,int r)
{
	int mid=(l+r)/2;
	if(lazy[x][0])
	{
		col0(x*2,l,mid,lazy[x][0]);
		col0(x*2+1,mid+1,r,lazy[x][0]);
		lazy[x][0]=0;
	}
	if(lazy[x][1])
	{
		col1(x*2,l,mid,lazy[x][1]);
		col1(x*2+1,mid+1,r,lazy[x][1]);
		lazy[x][1]=0;
	}
}
void modify(int x,int l,int r,int ql,int qr,ll v,int fl)
{
//	if(x==1) printf("modify:ql=%d,qr=%d,v=%lld,fl=%d\n",ql,qr,v,fl); 
	if(l>qr||r<ql) return;
	if(ql<=l&&r<=qr)
	{
		if(fl==0) col0(x,l,r,v);
		else col1(x,l,r,v);
		return;
	}
	pushdown(x,l,r);
	int mid=(l+r)/2;
	modify(x*2,l,mid,ql,qr,v,fl);
	modify(x*2+1,mid+1,r,ql,qr,v,fl);
	pushup(x);
}
ll query(int x,int l,int r,int ql,int qr)
{
	if(l>qr||r<ql) return 0;
	if(ql<=l&&r<=qr) return sum[x][2];
	pushdown(x,l,r);
	int mid=(l+r)/2;
	return query(x*2,l,mid,ql,qr)+query(x*2+1,mid+1,r,ql,qr);
}
int n,a[100005],b[100005],bt,pre[100005],nxt[100005],vis[100005];
int st0[100005],tp0,st1[100005],tp1;
int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&a[i]);
		b[++bt]=a[i];
	}
	sort(b+1,b+bt+1);
	bt=unique(b+1,b+bt+1)-b-1;
	for(int i=1;i<=n;i++)
		a[i]=lower_bound(b+1,b+bt+1,a[i])-b;
	for(int i=1;i<=n;i++)
	{
		if(vis[a[i]])
		{
			pre[i]=vis[a[i]];
			nxt[vis[a[i]]]=i;
		}
		vis[a[i]]=i;
	}
	int ans=0,las=0;
	for(int i=1;i<=n;i++)
	{
	//	if(pre[i])
		{
		//	int las=i-1;
			while(tp0&&pre[st0[tp0]]<pre[i])
			{
				modify(1,1,n,st0[tp0-1]+1,st0[tp0],pre[st0[tp0]]-pre[i],0);
				tp0--;
			}
			st0[++tp0]=i;
			modify(1,1,n,i,i,i-pre[i]-1,0);
		}
		if(!nxt[i]) nxt[i]=n+1;
		while(tp1&&nxt[st1[tp1]]>nxt[i])
		{
			modify(1,1,n,st1[tp1-1]+1,st1[tp1],nxt[i]-nxt[st1[tp1]],1);
			tp1--;
		}
		st1[++tp1]=i;
		modify(1,1,n,1,i-1,-1,1);
		modify(1,1,n,i,i,nxt[i]-i-1,1);
		las=max(las,pre[i]+1);
		ll nw=query(1,1,n,las,i);
	//	printf("query:l=%d,r=%d\n",las,i);
	//	printf("i=%d,pre=%d,nxt=%d,nw=%lld,tp=%d,%d\n",i,pre[i],nxt[i],nw,tp0,tp1);
		ans=(ans+nw)%mod;
	}
	printf("%d\n",ans);
	return 0;
}
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int B=316;
int n,m,a[100005],fir[100005],b[100005],ft,sum[1000005],c[100005],d[100005],lim;
/*void pushup(int x)
{
	sum[x]=sum[x*2]+sum[x*2+1];
}
void modify(int x,int l,int r,int qx,int v)
{
	if(l>qx||r<qx) return;
	if(l==r)
	{
		sum[x]=v;
		return;
	}
	int mid=(l+r)/2;
	modify(x*2,l,mid,qx,v);
	modify(x*2+1,mid+1,r,qx,v);
	pushup(x);
}
int query(int x,int l,int r,int k)
{
	if(l==r) return l;
	int mid=(l+r)/2;
	if(sum[x*2]>=k) return query(x*2,l,mid,k);
	return query(x*2+1,mid+1,r,k-sum[x*2]);
}*/
inline int lowbit(int x)
{
	return x&-x;
}
void modify(int x,int v)
{
//	printf("modify:x=%d,v=%d\n",x,v);
	for(int i=x;i<=n;i+=lowbit(i))
		sum[i]+=v;
}
int query(int k)
{
	int x=0;
	for(int i=lim;i;i>>=1)
	{
	//	printf("query:x=%d,i=%d,k=%d,sum=%d\n",x,i,k,sum[x+i]); 
		if(x+i<=n&&sum[x+i]<=k)
		{
			k-=sum[x+i];
			x+=i;
		}
	}
	return x;
}
void build(int x)
{
	for(int i=fir[x+1]-1;i>=fir[x];i--)
	{
		c[i]=query(a[i]-1)+1;
		modify(c[i],-1);
	}
	for(int i=fir[x];i<fir[x+1];i++)
		modify(c[i],1),d[i]=c[i];
	sort(c+fir[x],c+fir[x+1]);
}
int query(int x,int v)
{
	int l=fir[x],r=fir[x+1]-1,mid;
	while(l<=r)
	{
		mid=(l+r)/2;
		if(c[mid]-(mid-fir[x]+1)>=v) r=mid-1;
		else l=mid+1;
	}
	return v+r-fir[x]+1;
}
int main()
{
//	freopen("CF1540D.in","r",stdin);
//	freopen("CF1540D.out","w",stdout);
	scanf("%d",&n);
	lim=1;
	while(lim<=n) lim<<=1;
	lim>>=1;
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&a[i]);
		a[i]=i-a[i];
	}
	for(int i=1;i<=n;i++)
	{
		b[i]=(i-1)/B+1;
		if(!fir[b[i]]) fir[b[i]]=i,ft++;
	}
	fir[ft+1]=n+1;
	for(int i=1;i<=n;i++)
		modify(i,1);
	for(int i=1;i<=ft;i++)
		build(i);
	scanf("%d",&m);
	for(int i=1;i<=m;i++)
	{
		int op,x,y;
		scanf("%d%d",&op,&x);
		if(op==1)
		{
			scanf("%d",&y);
			a[x]=x-y;
			build(b[x]);
		}
		else
		{
			int ans=d[x];
			for(int j=b[x]+1;j<=ft;j++)
				ans=query(j,ans);
			printf("%d\n",ans);
		}
	}
	return 0;
}
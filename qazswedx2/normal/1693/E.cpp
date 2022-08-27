#include<cstdio>
#include<cstring>
#include<algorithm>
#include<queue>
using namespace std;
typedef long long ll;
struct mat
{
	int v[2][2];
	mat(){memset(v,0x3f,sizeof(v));}
};
mat operator*(const mat a,const mat b)
{
	mat c;
	for(int i=0;i<2;i++)
		for(int j=0;j<2;j++)
			for(int k=0;k<2;k++)
				c.v[i][j]=min(c.v[i][j],a.v[i][k]+b.v[k][j]);
	return c;
}
mat sum[1000005],s[4];
void pushup(int x)
{
	sum[x]=sum[x*2]*sum[x*2+1];
}
void modify(int x,int l,int r,int qx,int v)
{
//	if(x==1) printf("modify:qx=%d,v=%d\n",qx,v);
	if(l>qx||r<qx) return;
	if(l==r)
	{
		sum[x]=s[v];
		return;
	}
	int mid=(l+r)/2;
	modify(x*2,l,mid,qx,v);
	modify(x*2+1,mid+1,r,qx,v);
	pushup(x);
//		printf("modify:x=%d,l=%d,r=%d,sum=%d,%d,%d,%d\n",x,l,r,sum[x].v[0][0],sum[x].v[0][1],sum[x].v[1][0],sum[x].v[1][1]);
}
mat query(int x,int l,int r,int ql,int qr)
{
	if(l>qr||r<ql) return s[0];
	if(ql<=l&&r<=qr)
	{
		return sum[x];
	}
	int mid=(l+r)/2;
	return query(x*2,l,mid,ql,qr)*query(x*2+1,mid+1,r,ql,qr);
}
int n,a[1000005],vis[1000005][2];
void upd(int x,int fl,int v)
{
	vis[x][fl]+=v;
	int u=0;
	if(vis[x][0]) u|=1;
	if(vis[x][1]) u|=2;
	modify(1,0,n,x,u);
}
int main()
{
	s[0].v[0][0]=s[0].v[0][1]=s[0].v[1][0]=s[0].v[1][1]=0;
	s[1].v[0][0]=s[1].v[0][1]=1,s[1].v[1][0]=s[1].v[1][1]=0;
	s[2].v[0][0]=s[2].v[0][1]=0,s[2].v[1][0]=s[2].v[1][1]=1;
	s[3].v[0][0]=s[3].v[0][1]=s[3].v[1][0]=s[3].v[1][1]=1;
	s[1].v[1][0]=1e9;
	s[2].v[0][1]=1e9;
	s[0].v[0][1]=s[0].v[1][0]=1e9;
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
		scanf("%d",&a[i]);
	for(int i=0;i<=n;i++)
		modify(1,0,n,i,0);
	upd(0,0,1);
	upd(0,1,1);
	for(int i=2;i<=n;i++)
		upd(a[i],1,1);
	long long ans=0;
	for(int i=1;i<=n;i++)
	{
		mat q=query(1,0,n,0,a[i]-1);
		int nans=0;
		nans=min(min(q.v[0][0],q.v[0][1]),min(q.v[1][0],q.v[1][1]));
	//	printf("i=%d,nans=%d,%d,%d,%d,%d\n",i,nans,q.v[0][0],q.v[0][1],q.v[1][0],q.v[1][1]); 
		ans+=nans;
		upd(a[i+1],1,-1);
		upd(a[i],0,1);
	}
	printf("%lld\n",ans);
	return 0;
}
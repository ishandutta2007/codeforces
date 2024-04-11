#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
struct pt
{
	int l,r,id;
	pt(int l=0,int r=0,int id=0):l(l),r(r),id(id){}
	bool operator<(const pt x) const
	{
		return r==x.r?l>x.l:r<x.r;
	}
}a[100005];
struct edge
{
	int v,w,nxt;
}e[2000005];
int L,R,n,m,e2[500005][2],h[500005],t,dis[500005],g[100005],gt,vis[500005];
int q[1000005],head,tail,st[1000005],tp,f[100005][4],re[100005];
int b[100005];
void add(int u,int v,int w)
{
//	printf("%d %d %d\n",u,v,w);
	e[++t].v=v;
	e[t].w=w;
	e[t].nxt=h[u];
	h[u]=t;
}
void bfs(int s)
{
	head=tail=5e5;
	q[++tail]=s;
	vis[s]=2;
	tp=1;
	st[1]=s;
	while(head<tail)
	{
		head++;
		int u=q[head];
		for(int i=h[u];i;i=e[i].nxt)
		{
			int v=e[i].v,w=e[i].w;
			if(vis[v]) continue;
			vis[v]=vis[u]^w;
			if(v<=n) st[++tp]=v;
			if(w) q[++tail]=v;
			else q[head--]=v;
		}
	}
}
int main()
{
	scanf("%d%d%d%d",&L,&R,&n,&m);
	for(int i=1;i<=n;i++)
		scanf("%d%d",&a[i].l,&a[i].r),a[i].id=i;
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++)
		re[a[i].id]=i;
	//for(int i=1;i<=n;i++)
	//	printf("i=%d,a=%d,%d,%d\n",i,a[i].l,a[i].r,a[i].id);
	for(int i=1;i<=m;i++)
	{
		int u,v;
		scanf("%d%d",&u,&v);
		add(u,v,1);
		add(v,u,1);
		e2[i][0]=u,e2[i][1]=v;
	}
	for(int i=1;i<=n;i++)
	{
		add(n+i,a[i].id,0);
		add(a[i].id,2*n+i,0);
		if(i>1) add(n+i,n+i-1,0);
		if(i<n) add(2*n+i,2*n+i+1,0);
	}
	for(int i=1;i<=n;i++)
	{
		int nw=lower_bound(a+1,a+n+1,pt(-1,a[i].l-1))-a-1;
		if(nw)
		{
			add(a[i].id,n+nw,1);
			add(2*n+nw,a[i].id,1);
		}
	}
	for(int i=1;i<=n;i++)
		if(!vis[i])
		{
			gt++;
			bfs(i);
			f[gt][0]=f[gt][2]=0;
			f[gt][1]=f[gt][3]=1e9;
			//printf("i=%d\n",i);
		//	printf("st=");
			for(int j=1;j<=tp;j++)
			{
				int u=st[j],v=re[u];
		//		printf("%d ",u);
				g[u]=gt;
				if(vis[u]==3)
				{
					f[gt][0]=max(f[gt][0],a[v].l);
					f[gt][1]=min(f[gt][1],a[v].r);
				}
				else
				{
					f[gt][2]=max(f[gt][2],a[v].l);
					f[gt][3]=min(f[gt][3],a[v].r);
				}
			}
		//	printf("\nf=%d,%d,%d,%d\n",f[gt][0],f[gt][1],f[gt][2],f[gt][3]);
			if(f[gt][0]>f[gt][1]||f[gt][2]>f[gt][3])
			{
				printf("IMPOSSIBLE\n");
				return 0;
			}
		}
	for(int i=1;i<=m;i++)
	{
		int u=e2[i][0],v=e2[i][1];
		if(vis[u]==vis[v])
		{
			printf("IMPOSSIBLE\n");
			return 0;
		}
	}
	int nw1=0,nw2=0;
	while(nw1<n&&vis[a[nw1+1].id]==3) nw1++;
	while(nw2<n&&vis[a[nw2+1].id]==2) nw2++;
	/*printf("nw1=%d,nw2=%d\n",nw1,nw2);
	for(int i=1;i<=n;i++)
		printf("%d ",vis[i]);
	printf("\n");*/
	for(int i=1;i<=n;i++)
	{
		int nw=lower_bound(a+1,a+n+1,pt(-1,a[i].l-1))-a-1;
	//	printf("i=%d,l=%d,r=%d,vis=%d,nw=%d,id=%d\n",i,a[i].l,a[i].r,vis[a[i].id],nw,a[i].id);
		if((vis[a[i].id]==3&&nw2<nw)||(vis[a[i].id]==2&&nw1<nw))
		{
			printf("IMPOSSIBLE\n");
			return 0;
		}
	}
	int mxl=-1,idl=0,ql,mnr=1e9+1,idr=0,qr;
	for(int i=1;i<=gt;i++)
	{
		if(f[i][0]>mxl)
		{
			mxl=f[i][0];
			idl=0;
		}
		if(f[i][2]>mxl)
		{
			mxl=f[i][2];
			idl=1;
		}
		if(f[i][1]<mnr)
		{
			mnr=f[i][1];
			idr=0;
		}
		if(f[i][3]<mnr)
		{
			mnr=f[i][3];
			idr=1;
		}
	//	printf("i=%d,mnr=%d,f=%d,%d,%d,%d\n",i,mnr,f[i][0],f[i][1],f[i][2],f[i][3]);
	}
	ql=R-mxl,qr=L-mnr;
//	printf("mxl=%d,idl=%d,ql=%d,mnr=%d,idr=%d,qr=%d\n",mxl,idl,ql,mnr,idr,qr);
	int l=0,r=1e9,ll=0,rr=1e9;
	for(int i=1;i<=gt;i++)
	{
		int nw=0;
		if(f[i][0]>ql) nw|=idl+1;
		if(f[i][2]>ql) nw|=(idl^1)+1;
		if(f[i][1]<qr) nw|=idr+1;
		if(f[i][3]<qr) nw|=(idr^1)+1;
		if(nw==3)
		{
			printf("IMPOSSIBLE\n");
			return 0;
		}
		if(nw==2)
		{
			b[i]=1;
			swap(f[i][0],f[i][2]);
			swap(f[i][1],f[i][3]);
		}
		else b[i]=0;
	//	printf("i=%d,b=%d,f=%d,%d,%d,%d\n",i,b[i],f[i][0],f[i][1],f[i][2],f[i][3]);
		l=max(l,f[i][0]);
		r=min(r,f[i][1]);
		ll=max(ll,f[i][2]);
		rr=min(rr,f[i][3]);
	}
	//printf("l=%d,r=%d,ll=%d,rr=%d\n",l,r,ll,rr);
	int ans1=-1,ans2=-1,fll=0;
	printf("POSSIBLE\n");
	if(r-l+1>rr-ll+1) swap(l,ll),swap(r,rr),fll=1;
	if(L-l>=ll&&L-l<=rr) ans1=l,ans2=L-l;
	else if(R-l>=ll&&R-l<=rr) ans1=l,ans2=R-l;
	else if(l+ll>=L&&l+ll<=R) ans1=l,ans2=ll;
	else if(l+rr>=L&&l+rr<=R) ans1=l,ans2=rr;
	else if(L-r>=ll&&L-r<=rr) ans1=r,ans2=L-r;
	else if(R-r>=ll&&R-r<=rr) ans1=r,ans2=R-r;
	else if(r+ll>=L&&r+ll<=R) ans1=r,ans2=ll;
	else if(r+rr>=L&&r+rr<=R) ans1=r,ans2=rr;
	//printf("ans1=%d,ans2=%d\n",ans1,ans2);
	if(fll==1) swap(ans1,ans2);
	printf("%d %d\n",ans1,ans2);
	for(int i=1;i<=n;i++)
		printf("%d",(b[g[i]]^(vis[i]-2)^1)+1);
	return 0;
}
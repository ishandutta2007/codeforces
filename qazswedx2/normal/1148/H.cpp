#include<cstdio>
#include<cstring>
#include<algorithm>
#include<vector>
using namespace std;
typedef long long ll;
struct pt
{
	int val,id;
	pt(int val=0,int id=0):val(val),id(id){}
	bool operator<(const pt x) const
	{
		return val<x.val;
	}
};
int n,mn[1000005],rt[2000005],t,ct,ls[20000005],rs[20000005];
int b[200005][2];
ll sum2[20000005],lazy2[20000005],lazy[20000005],sum[20000005];
vector<pt> val[200005];
void pushup2(int x,int l,int r)
{
	sum[x]=sum[ls[x]]+sum[rs[x]]+(r-l+1)*lazy[x];
	sum2[x]=sum2[ls[x]]+sum2[rs[x]]+(r-l+1)*lazy2[x];
}
int nwpt(int x)
{
	ct++;
	sum[ct]=sum[x];
	sum2[ct]=sum2[x];
	lazy[ct]=lazy[x];
	lazy2[ct]=lazy2[x];
	ls[ct]=ls[x];
	rs[ct]=rs[x];
	return ct;
}
int modify2(int x,int l,int r,int ql,int qr,ll v,ll v2)
{
	if(l>qr||r<ql) return x;
	x=nwpt(x);
	if(ql<=l&&r<=qr)
	{
		lazy[x]+=v;
		lazy2[x]+=v2;
		sum[x]+=v*(r-l+1);
		sum2[x]+=v2*(r-l+1);
		return x;
	}
	int mid=(l+r)/2;
	ls[x]=modify2(ls[x],l,mid,ql,qr,v,v2);
	rs[x]=modify2(rs[x],mid+1,r,ql,qr,v,v2);
	pushup2(x,l,r);
	return x;
}
ll query2(int x,int l,int r,int ql,int qr,int v)
{
	if(l>qr||r<ql||!x) return 0;
	if(ql<=l&&r<=qr) return 1ll*sum[x]*(v+1)-sum2[x];
	int mid=(l+r)/2;
	return query2(ls[x],l,mid,ql,qr,v)+query2(rs[x],mid+1,r,ql,qr,v)
		   +1ll*(min(r,qr)-max(l,ql)+1)*(1ll*lazy[x]*(v+1)-lazy2[x]);
}
void pushup(int x)
{
	mn[x]=min(mn[x*2],mn[x*2+1]);
}
void modify(int x,int l,int r,int qx,int v)
{
	if(l>qx||r<qx) return;
	if(l==r)
	{
		mn[x]=v;
		return;
	}
	int mid=(l+r)/2;
	modify(x*2,l,mid,qx,v);
	modify(x*2+1,mid+1,r,qx,v);
	pushup(x);
	//printf("modify:x=%d,l=%d,r=%d,qx=%d,v=%d,mn=%d\n",x,l,r,qx,v,mn[x]);
}
int d[1000005][2],dt;
void query(int x,int l,int r,int ql,int qr,int tl,int tr)
{
	if(l>qr||r<ql) return;
	if(ql<=l&&r<=qr)
	{
		if(mn[x]>=tr) return;
		if(l==r)
		{
			if(mn[x]>=tl)
			{
		//		printf("query:x=%d,l=%d,r=%d,tl=%d,tr=%d\n",x,l,r,tl,tr);
				d[++dt][0]=l-1;
				d[dt][1]=mn[x];
			}
			return;
		}
	}
	int mid=(l+r)/2;
	query(x*2,l,mid,ql,qr,tl,tr);
	if(mn[x*2]>=tl) query(x*2+1,mid+1,r,ql,qr,tl,min(tr,mn[x*2]));
}
int query3(int x,int l,int r,int k)
{
	//printf("x=%d,l=%d,r=%d,k=%d,sum=%d\n",x,l,r,k,mn[x]);
	if(l==r) return l;
	int mid=(l+r)/2;
	if(mn[x*2]<k) return query3(x*2,l,mid,k);
	return query3(x*2+1,mid+1,r,k);
}
void ins(int u,int x,int tl=0,int tr=0)
{
	int l=b[u][0],r=b[u][1];
	if(tl) l=tl,r=tr;
	t++;
	int pre;
	if(val[u].size()) pre=(--val[u].end())->id;
	else pre=0;
	//if(!u) printf("ins:u=%d,x=%d,l=%d,r=%d\n",u,x,l,r);
	val[u].push_back(pt(x,t));
	rt[t]=modify2(rt[pre],1,n,l,r,1,x);
}
void del(int u,int x)
{
	int l=b[u][0],r=b[u][1];
	t++;
	int pre;
	if(val[u].size()) pre=(--val[u].end())->id;
	else pre=0;
	val[u].push_back(pt(x,t));
	//if(!u) printf("del:u=%d,x=%d,l=%d,r=%d\n",u,x,l,r);
	rt[t]=modify2(rt[pre],1,n,l,r,-1,-x);
}
int main()
{
	//freopen("CF1148H.in","r",stdin);
	//freopen("CF1148H.out","w",stdout);
	scanf("%d",&n);
	ll las=0;
	for(int i=1;i<=n;i++)
	{
		int a,l,r,k;
		scanf("%d%d%d%d",&a,&l,&r,&k);
		a=(a+las)%(n+1);
		l=(l+las)%i+1;
		r=(r+las)%i+1;
		k=(k+las)%(n+1);
		//if(i%1000==0) fprintf(stderr,"i=%d,t=%d,ct=%d,k=%d\n",i,t,ct,k);
		//printf("i=%d,a=%d,l=%d,r=%d,k=%d\n",i,a,l,r,k);
		if(l>r) swap(l,r);
		modify(1,1,n+1,a+1,i);
		if(b[a][0])
		{
			dt=0;
			query(1,1,n+1,a+1,n+1,b[a][0],b[a][1]);
			int nw=b[a][1];
			for(int j=1;j<=dt;j++)
			{
				int ll=d[j][1]+1,rr=nw,v=d[j][0];
				b[v][0]=ll,b[v][1]=rr;
				ins(v,i);
				nw=ll-1;
			}
			int pre=query3(1,1,n+1,b[a][0])-1;
		//	printf("pre=%d\n",pre);
			if(b[pre][0])
			{
				ins(pre,i,b[pre][1]+1,nw);
				b[pre][1]=nw;
			}
			else
			{
				b[pre][0]=1,b[pre][1]=nw;
				ins(pre,i);
			}
			del(a,i);
			b[a][0]=b[a][1]=0;
		}
		int tnw=(!a?1:0);
		if(b[tnw][0])
		{
			ins(tnw,i,b[tnw][1]+1,i);
			b[tnw][1]=i;
		}
		else
		{
			b[tnw][0]=b[tnw][1]=i;
			ins(tnw,i);
		}
		vector<pt>::iterator u=upper_bound(val[k].begin(),val[k].end(),pt(r));
		if(u==val[k].begin()) las=0;
		else
		{
			u--;
			int id=u->id;
		//	printf("query2:rt=%d,id=%d,l=%d,r=%d\n",rt[id],id,l,r);
			las=query2(rt[id],1,n,l,r,r);
		}
		printf("%lld\n",las);
	}
}
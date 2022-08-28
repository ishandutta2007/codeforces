#include<cstdio>
#include<cstring>
#include<algorithm>
#include<map>
using namespace std;
struct pt
{
	int val,id;
	pt(int val=0,int id=0):val(val),id(id){};
	bool operator<(const pt x) const
	{
		return id<x.id;
	}
};
struct qn
{
	int l,r,id;
	bool operator<(const qn x) const
	{
		return r<x.r;
	}
}q0[6000005],q1[6000005],tq[6000005];
struct sg
{
	int l,r;
	bool operator<(const sg x) const
	{
		return l<x.l;
	}
}p[500005];
int n,m,a[100005],rt[100005],sum[10000005],ls[10000005],rs[10000005],cnt,val=1e9+1;
int cl[100005],cu[100005],qt0,qt1,sum2[1000005],qans[500005],ct;
int c[100005];
map<int,int> mp;
pt b[100005];
bool cmp(const pt x,const pt y)
{
	return x.val==y.val?x.id<y.id:x.val<y.val;
}
bool cmp2(const pt x,const pt y)
{
	return x.val<y.val;
}
void pushup(int x)
{
	sum[x]=sum[ls[x]]+sum[rs[x]];
}
int modify(int x,int l,int r,int qx)
{
	if(l>qx||r<qx) return x;
	int y=++cnt;
	sum[y]=sum[x];
	if(l==r)
	{
		sum[y]++;
		return y;
	}
	int mid=(l+r)/2;
	ls[y]=modify(ls[x],l,mid,qx);
	rs[y]=modify(rs[x],mid+1,r,qx);
	pushup(y);
	return y;
}
int querypre(int x,int y,int l,int r,int qx)
{
	if(!(sum[y]-sum[x])||qx<=l) return -1;
	if(l==r) return l;
	int mid=(l+r)/2;
	if(qx<=mid) return querypre(ls[x],ls[y],l,mid,qx);
	else
	{
		int q=querypre(rs[x],rs[y],mid+1,r,qx);
		if(q!=-1) return q;
		return querypre(ls[x],ls[y],l,mid,qx);
	}
}
int querynxt(int x,int y,int l,int r,int qx)
{
	if(!(sum[y]-sum[x])||qx>=r) return -1;
	if(l==r) return l;
	int mid=(l+r)/2;
	if(qx>mid) return querynxt(rs[x],rs[y],mid+1,r,qx);
	else
	{
		int q=querynxt(ls[x],ls[y],l,mid,qx);
		if(q!=-1) return q;
		return querynxt(rs[x],rs[y],mid+1,r,qx);
	}
}
int findid(int x,int y)
{
	int nw=mp[y];
	return lower_bound(b+cl[nw],b+cu[nw],pt(0,x))->id;
}
void tpushup(int x)
{
	sum2[x]=min(sum2[x*2],sum2[x*2+1]);
}
void tmodify(int x,int l,int r,int qx,int v)
{
	//if(x==1) printf("tmodify:x=%d,v=%d\n",qx,v);
	if(l>qx||r<qx) return;
	if(l==r)
	{
		sum2[x]=min(sum2[x],v);
		return;
	}
	int mid=(l+r)/2;
	tmodify(x*2,l,mid,qx,v);
	tmodify(x*2+1,mid+1,r,qx,v);
	tpushup(x);
}
int tquery(int x,int l,int r,int ql,int qr)
{
	if(l>qr||r<ql) return 1e9;
	if(ql<=l&&r<=qr) return sum2[x];
	int mid=(l+r)/2,q1,q2;
	q1=tquery(x*2,l,mid,ql,qr);
	q2=tquery(x*2+1,mid+1,r,ql,qr);
	return min(q1,q2);
}
int main()
{
	memset(sum2,0x3f,sizeof(sum2));
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&a[i]),a[i]++;
		b[i]=pt(a[i],i);
		c[i]=a[i];
	}
	sort(b+1,b+n+1,cmp);
	sort(c+1,c+n+1);
	ct=unique(c+1,c+n+1)-c-1;
	//for(int i=1;i<=n;i++)
	//	if(!mp.count(a[i]))
	//		mp[a[i]]=i;
	int bnw=1;
	for(int i=1;i<=ct;i++)
	{
		rt[i]=rt[i-1];
		while(bnw<=n&&b[bnw].val==c[i])
		{
			rt[i]=modify(rt[i],1,n,b[bnw].id);
		//	printf("i=%d,bnw=%d,id=%d\n",i,bnw,b[bnw].id);
			bnw++;
		}
	}
	//for(int i=1;i<=n;i++)
	//	printf("i=%d,id=%d,val=%d\n",i,b[i].id,b[i].val);
	for(int i=1;i<=n;i++)
		cl[i]=lower_bound(c+1,c+ct+1,a[i])-c;
	/*for(int i=1;i<=n;i++)
	{
		cl[i]=lower_bound(b+1,b+n+1,pt(a[i],0),cmp2)-b;
		cu[i]=upper_bound(b+1,b+n+1,pt(a[i],0),cmp2)-b;
		printf("i=%d,cl=%d,cu=%d\n",i,cl[i],cu[i]);
	}
	for(int i=1;i<=n;i++)
		rt[i]=modify(rt[i-1],1,val,a[i]);*/
	for(int i=1;i<=n;i++)
	{
		int v=ct,nw=i;
		while(1)
		{
			int u=querynxt(rt[cl[i]-1],rt[v],1,n,nw);
			if(u==-1) break;
			nw=u;
			q0[++qt0].l=i;
			q0[qt0].r=u;
		//	printf("q0:i=%d,nw=%d,u=%d,v=%d,cl=%d\n",i,nw,u,v,cl[i]);
			v=upper_bound(c+1,c+ct+1,(a[i]+a[u]-1)/2)-c-1;
			if(v<cl[i]) break;
		}
		v=1,nw=i;
		while(1)
		{
			int u=querynxt(rt[v-1],rt[cl[i]],1,n,nw);
			if(u==-1) break;
			nw=u;
			q1[++qt1].l=i;
			q1[qt1].r=u;
			v=lower_bound(c+1,c+ct+1,(a[i]+a[u])/2+1)-c;
		//	printf("q1:i=%d,nw=%d,u=%d,v=%d,cl=%d\n",i,nw,u,v,cl[i]);
			if(v>cl[i]) break;
		}
	}
	sort(q0+1,q0+qt0+1);
	sort(q1+1,q1+qt1+1);
	scanf("%d",&m);
	for(int i=1;i<=m;i++)
		scanf("%d%d",&tq[i].l,&tq[i].r),tq[i].id=i;
	sort(tq+1,tq+m+1);
	int nq0=1,nq1=1,ntq=1;
	for(int i=1;i<=n;i++)
	{
		while(nq0<=qt0&&q0[nq0].r==i)
		{
		//	printf("nq0=%d,l=%d,r=%d\n",nq0,q0[nq0].l,q0[nq0].r);
			tmodify(1,1,n,q0[nq0].l,a[q0[nq0].r]-a[q0[nq0].l]);
			nq0++;
		}
		while(nq1<=qt1&&q1[nq1].r==i)
		{
		//	printf("nq1=%d,l=%d,r=%d\n",nq1,q1[nq1].l,q1[nq1].r);
			tmodify(1,1,n,q1[nq1].l,a[q1[nq1].l]-a[q1[nq1].r]);
			nq1++;
		}
		while(ntq<=m&&tq[ntq].r==i)
		{
			qans[tq[ntq].id]=tquery(1,1,n,tq[ntq].l,tq[ntq].r);
		//	printf("ntq=%d,l=%d,r=%d,ans=%d\n",ntq,tq[ntq].l,tq[ntq].r,qans[tq[ntq].id]);
			ntq++;
		}
	}
	for(int i=1;i<=m;i++)
		printf("%d\n",qans[i]);
	return 0;
}
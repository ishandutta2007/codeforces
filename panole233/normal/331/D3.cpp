#include<bits/stdc++.h>
using namespace std;

//up down left right
const long long inf=100000000000000000ll;
struct ele{int x,y,d; long long T;}q[100010];
struct mogic{int xl,yl,xr,yr,d;}s[100010];
struct seg{int y,l,r,ord;}a[100010];
struct que{int x,y,ord;}d[200001];
struct node{int l,r,val;}t[500010];
int n,Q,f[100001][61],pt[100010],cnta,cntd,nwa,nwd,nw,m;
long long g[100001][61];
char str[5];

int getabs(int x) {return (x<0)?(-x):(x);}
bool cmp1(seg a,seg b) {return a.y<b.y;}
bool cmp2(que a,que b) {return a.y<b.y;}

void build(int i,int l,int r)
{
	t[i].l=l,t[i].r=r,t[i].val=0;
	if (l==r) return;
	int mid=(l+r)>>1;
	build(i<<1,l,mid),build(i<<1|1,mid+1,r);
}

void pushdown(int i)
{
	if (!t[i].val) return;
	t[i<<1].val=t[i<<1|1].val=t[i].val;
	t[i].val=0;
}

void change(int i,int l,int r,int v)
{
	if (t[i].l==l&&t[i].r==r) {t[i].val=v; return;}
	pushdown(i); int mid=(t[i].l+t[i].r)>>1;
	if (r<=mid) change(i<<1,l,r,v); else
	if (l>mid) change(i<<1|1,l,r,v); else
	change(i<<1,l,mid,v),change(i<<1|1,mid+1,r,v);
}

int query(int i,int x)
{
	if (t[i].l==t[i].r) return t[i].val;
	pushdown(i); int mid=(t[i].l+t[i].r)>>1;
	if (x<=mid) return query(i<<1,x);
	else return query(i<<1|1,x);
}

int main()
{
//	freopen("duan.in","r",stdin);
//	freopen("duan.out","w",stdout);
	scanf("%d%d",&n,&m);
	for (int i=1; i<=n; i++) 
	{
		scanf("%d%d%d%d",&s[i].xl,&s[i].yl,&s[i].xr,&s[i].yr);
		if (s[i].xl==s[i].xr) s[i].d=(s[i].yl>s[i].yr);
		else s[i].d=(s[i].xl<s[i].xr)+2;
	}
	scanf("%d",&Q);
	for (int i=1; i<=Q; i++) 
	{
		scanf("%d%d%s%lld",&q[i].x,&q[i].y,str,&q[i].T);
		if (str[0]=='U') q[i].d=0;
		if (str[0]=='D') q[i].d=1;
		if (str[0]=='L') q[i].d=2;
		if (str[0]=='R') q[i].d=3;
	}
	//up
	build(1,0,m),cnta=cntd=0;
	for (int i=1; i<=n; i++) 
		if (s[i].d==0) d[++cntd]=(que){s[i].xl,m-s[i].yr,i}; else
		if (s[i].d==1) a[++cnta]=(seg){m-s[i].yl,s[i].xl,s[i].xl,i}; else
		if (s[i].d==2) a[++cnta]=(seg){m-s[i].yl,s[i].xr,s[i].xl,i}; else
		if (s[i].d==3) a[++cnta]=(seg){m-s[i].yl,s[i].xl,s[i].xr,i};
	for (int i=1; i<=Q; i++) if (q[i].d==0) d[++cntd]=(que){q[i].x,m-q[i].y,-i};
	sort(a+1,a+1+cnta,cmp1),sort(d+1,d+1+cntd,cmp2);
	nwa=nwd=1;
	for (int i=0; i<=m; i++)
	{
		while (nwa<=cnta&&a[nwa].y==i) change(1,a[nwa].l,a[nwa].r,a[nwa].ord),nwa++;
		while (nwd<=cntd&&d[nwd].y==i) 
		{
			if (d[nwd].ord<0) pt[-d[nwd].ord]=query(1,d[nwd].x);
			else f[d[nwd].ord][0]=query(1,d[nwd].x);
			nwd++;
		}
	}
	//down
	build(1,0,m),cnta=cntd=0;
	for (int i=1; i<=n; i++) 
		if (s[i].d==0) a[++cnta]=(seg){s[i].yl,s[i].xl,s[i].xl,i}; else
		if (s[i].d==1) d[++cntd]=(que){s[i].xl,s[i].yl,i}; else
		if (s[i].d==2) a[++cnta]=(seg){s[i].yl,s[i].xr,s[i].xl,i}; else
		if (s[i].d==3) a[++cnta]=(seg){s[i].yl,s[i].xl,s[i].xr,i};
	for (int i=1; i<=Q; i++) if (q[i].d==1) d[++cntd]=(que){q[i].x,q[i].y,-i};
	sort(a+1,a+1+cnta,cmp1),sort(d+1,d+1+cntd,cmp2);
	nwa=nwd=1;
	for (int i=0; i<=m; i++)
	{
		while (nwa<=cnta&&a[nwa].y==i) change(1,a[nwa].l,a[nwa].r,a[nwa].ord),nwa++;
		while (nwd<=cntd&&d[nwd].y==i) 
		{
			if (d[nwd].ord<0) pt[-d[nwd].ord]=query(1,d[nwd].x);
			else f[d[nwd].ord][0]=query(1,d[nwd].x);
			nwd++;
		}
	}
	//left
	build(1,0,m),cnta=cntd=0;
	for (int i=1; i<=n; i++) 
		if (s[i].d==0) a[++cnta]=(seg){s[i].xl,s[i].yl,s[i].yr,i}; else
		if (s[i].d==1) a[++cnta]=(seg){s[i].xl,s[i].yr,s[i].yl,i}; else
		if (s[i].d==2) d[++cntd]=(que){s[i].yl,s[i].xl,i}; else
		if (s[i].d==3) a[++cnta]=(seg){s[i].xl,s[i].yl,s[i].yl,i};
	for (int i=1; i<=Q; i++) if (q[i].d==2) d[++cntd]=(que){q[i].y,q[i].x,-i};
	sort(a+1,a+1+cnta,cmp1),sort(d+1,d+1+cntd,cmp2);
	nwa=nwd=1;
	for (int i=0; i<=m; i++)
	{
		while (nwa<=cnta&&a[nwa].y==i) change(1,a[nwa].l,a[nwa].r,a[nwa].ord),nwa++;
		while (nwd<=cntd&&d[nwd].y==i) 
		{
			if (d[nwd].ord<0) pt[-d[nwd].ord]=query(1,d[nwd].x);
			else f[d[nwd].ord][0]=query(1,d[nwd].x);
			nwd++;
		}
	}
	//right
	build(1,0,m),cnta=cntd=0;
	for (int i=1; i<=n; i++) 
		if (s[i].d==0) a[++cnta]=(seg){m-s[i].xl,s[i].yl,s[i].yr,i}; else
		if (s[i].d==1) a[++cnta]=(seg){m-s[i].xl,s[i].yr,s[i].yl,i}; else
		if (s[i].d==2) a[++cnta]=(seg){m-s[i].xl,s[i].yl,s[i].yl,i}; else
		if (s[i].d==3) d[++cntd]=(que){s[i].yl,m-s[i].xl,i};
	for (int i=1; i<=Q; i++) if (q[i].d==3) d[++cntd]=(que){q[i].y,m-q[i].x,-i};
	sort(a+1,a+1+cnta,cmp1),sort(d+1,d+1+cntd,cmp2);
	nwa=nwd=1;
	for (int i=0; i<=m; i++)
	{
		while (nwa<=cnta&&a[nwa].y==i) change(1,a[nwa].l,a[nwa].r,a[nwa].ord),nwa++;
		while (nwd<=cntd&&d[nwd].y==i) 
		{
			if (d[nwd].ord<0) pt[-d[nwd].ord]=query(1,d[nwd].x);
			else f[d[nwd].ord][0]=query(1,d[nwd].x);
			nwd++;
		}
	}
	for (int i=1; i<=n; i++)
		g[i][0]=getabs(s[i].xr-s[f[i][0]].xr)+getabs(s[i].yr-s[f[i][0]].yr);
	for (int j=1; j<=60; j++)
		for (int i=1; i<=n; i++)
			f[i][j]=f[f[i][j-1]][j-1],g[i][j]=min(inf,g[i][j-1]+g[f[i][j-1]][j-1]);
	for (int i=1; i<=Q; i++)
	{
		if (!pt[i])
		{
			if (q[i].d==0) printf("%d %lld\n",q[i].x,min(1ll*m,q[i].y+q[i].T)); else
			if (q[i].d==1) printf("%d %lld\n",q[i].x,max(0ll,q[i].y-q[i].T)); else
			if (q[i].d==2) printf("%lld %d\n",max(0ll,q[i].x-q[i].T),q[i].y); else
			if (q[i].d==3) printf("%lld %d\n",min(1ll*m,q[i].x+q[i].T),q[i].y);
			continue;
		}
		if (getabs(q[i].x-s[pt[i]].xr)+getabs(q[i].y-s[pt[i]].yr)>=q[i].T)
		{
			if (q[i].d==0)
			{
				if (s[pt[i]].d==1) 
				{
					if (s[pt[i]].xl==q[i].x&&s[pt[i]].yl>=q[i].y&&s[pt[i]].yr<=q[i].y) printf("%d %lld\n",q[i].x,q[i].y-q[i].T);
					else printf("%d %lld\n",q[i].x,q[i].y+q[i].T);
				} else
				{
					if (s[pt[i]].yl-q[i].y>=q[i].T) printf("%d %lld\n",q[i].x,q[i].y+q[i].T); else
					{
						if (s[pt[i]].d==2) printf("%lld %d\n",q[i].x-(q[i].T-(s[pt[i]].yl-q[i].y)),s[pt[i]].yl);
						else printf("%lld %d\n",q[i].x+(q[i].T-(s[pt[i]].yl-q[i].y)),s[pt[i]].yl);
					}
				}
			} else
			if (q[i].d==1)
			{
				if (s[pt[i]].d==0) 
				{
					if (s[pt[i]].xl==q[i].x&&s[pt[i]].yr>=q[i].y&&s[pt[i]].yl<=q[i].y) printf("%d %lld\n",q[i].x,q[i].y+q[i].T);
					else printf("%d %lld\n",q[i].x,q[i].y-q[i].T); 
				} else
				{
					if (q[i].y-s[pt[i]].yl>=q[i].T) printf("%d %lld\n",q[i].x,q[i].y-q[i].T); else
					{
						if (s[pt[i]].d==2) printf("%lld %d\n",q[i].x-(q[i].T+(s[pt[i]].yl-q[i].y)),s[pt[i]].yl);
						else printf("%lld %d\n",q[i].x+(q[i].T+(s[pt[i]].yl-q[i].y)),s[pt[i]].yl);
					}
				}
			} else
			if (q[i].d==2)
			{
				if (s[pt[i]].d==3) 
				{
					if (s[pt[i]].yl==q[i].y&&s[pt[i]].xr>=q[i].x&&s[pt[i]].xl<=q[i].x) printf("%lld %d\n",q[i].x+q[i].T,q[i].y);
					else printf("%lld %d\n",q[i].x-q[i].T,q[i].y); 
				} else
				{
					if (q[i].x-s[pt[i]].xl>=q[i].T) printf("%lld %d\n",q[i].x-q[i].T,q[i].y); else
					{
						if (s[pt[i]].d==0) printf("%d %lld\n",s[pt[i]].xl,q[i].y+(q[i].T-(q[i].x-s[pt[i]].xl)));
						else printf("%d %lld\n",s[pt[i]].xl,q[i].y-(q[i].T-(q[i].x-s[pt[i]].xl)));
					}
				}
			} else
			{
				if (s[pt[i]].d==2) 
				{
					if (s[pt[i]].yl==q[i].y&&s[pt[i]].xr<=q[i].x&&s[pt[i]].xl>=q[i].x) printf("%lld %d\n",q[i].x-q[i].T,q[i].y);
					else printf("%lld %d\n",q[i].x+q[i].T,q[i].y); 
				} else
				{
					if (s[pt[i]].xl-q[i].x>=q[i].T) printf("%lld %d\n",q[i].x+q[i].T,q[i].y); else
					{
						if (s[pt[i]].d==0) printf("%d %lld\n",s[pt[i]].xl,q[i].y+(q[i].T+(q[i].x-s[pt[i]].xl)));
						else printf("%d %lld\n",s[pt[i]].xl,q[i].y-(q[i].T+(q[i].x-s[pt[i]].xl)));
					}
				}
			}
			continue;
		}
		q[i].T-=(getabs(q[i].x-s[pt[i]].xr)+getabs(q[i].y-s[pt[i]].yr)),nw=pt[i];
		for (int j=60; j>=0; j--)
			if (f[nw][j]&&g[nw][j]<=q[i].T) q[i].T-=g[nw][j],nw=f[nw][j];
		q[i].d=s[nw].d,q[i].x=s[nw].xr,q[i].y=s[nw].yr,pt[i]=f[nw][0];
		if (!pt[i])
		{
			if (q[i].d==0) printf("%d %lld\n",q[i].x,min(1ll*m,q[i].y+q[i].T)); else
			if (q[i].d==1) printf("%d %lld\n",q[i].x,max(0ll,q[i].y-q[i].T)); else
			if (q[i].d==2) printf("%lld %d\n",max(0ll,q[i].x-q[i].T),q[i].y); else
			if (q[i].d==3) printf("%lld %d\n",min(1ll*m,q[i].x+q[i].T),q[i].y);
			continue;
		}
		if (q[i].d==0)
		{
			if (s[pt[i]].d==1) printf("%d %lld\n",q[i].x,q[i].y+q[i].T); else
			{
				if (s[pt[i]].yl-q[i].y>=q[i].T) printf("%d %lld\n",q[i].x,q[i].y+q[i].T); else
				{
					if (s[pt[i]].d==2) printf("%lld %d\n",q[i].x-(q[i].T-(s[pt[i]].yl-q[i].y)),s[pt[i]].yl);
					else printf("%lld %d\n",q[i].x+(q[i].T-(s[pt[i]].yl-q[i].y)),s[pt[i]].yl);
				}
			}
		} else
		if (q[i].d==1)
		{
			if (s[pt[i]].d==0) printf("%d %lld\n",q[i].x,q[i].y-q[i].T); else
			{
				if (q[i].y-s[pt[i]].yl>=q[i].T) printf("%d %lld\n",q[i].x,q[i].y-q[i].T); else
				{
					if (s[pt[i]].d==2) printf("%lld %d\n",q[i].x-(q[i].T+(s[pt[i]].yl-q[i].y)),s[pt[i]].yl);
					else printf("%lld %d\n",q[i].x+(q[i].T+(s[pt[i]].yl-q[i].y)),s[pt[i]].yl);
				}
			}
		} else
		if (q[i].d==2)
		{
			if (s[pt[i]].d==3) printf("%lld %d\n",q[i].x-q[i].T,q[i].y); else
			{
				if (q[i].x-s[pt[i]].xl>=q[i].T) printf("%lld %d\n",q[i].x-q[i].T,q[i].y); else
				{
					if (s[pt[i]].d==0) printf("%d %lld\n",s[pt[i]].xl,q[i].y+(q[i].T-(q[i].x-s[pt[i]].xl)));
					else printf("%d %lld\n",s[pt[i]].xl,q[i].y-(q[i].T-(q[i].x-s[pt[i]].xl)));
				}
			}
		} else
		{
			if (s[pt[i]].d==2) printf("%lld %d\n",q[i].x+q[i].T,q[i].y); else
			{
				if (s[pt[i]].xl-q[i].x>=q[i].T) printf("%lld %d\n",q[i].x+q[i].T,q[i].y); else
				{
					if (s[pt[i]].d==0) printf("%d %lld\n",s[pt[i]].xl,q[i].y+(q[i].T+(q[i].x-s[pt[i]].xl)));
					else printf("%d %lld\n",s[pt[i]].xl,q[i].y-(q[i].T+(q[i].x-s[pt[i]].xl)));
				}
			}
		}
	}
	return 0;
}
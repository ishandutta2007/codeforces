#include<bits/stdc++.h>
#define ls (w*2)
#define rs (w*2+1)
#define mid ((l+r)/2)
#define ll long long
using namespace std;
const int N=2e3+5;
const ll mod=1e9+7;
const int inf=1e9+7;

int read()
{
	int s=0;
	char c=getchar(),lc='+';
	while (c<'0'||'9'<c) lc=c,c=getchar();
	while ('0'<=c&&c<='9') s=s*10+c-'0',c=getchar();
	return lc=='-'?-s:s;
}
void write(int x)
{
	if (x<0)
	{
		putchar('-');
		x=-x;
	}
	if (x<10) putchar(x+'0');
	else
	{
		write(x/10);
		putchar(x%10+'0');
	}
}
void print(int x=-1,char c='\n')
{
	write(x);
	putchar(c);
}
inline void add(ll &x,ll y)
{
	x+=y;
	if (x>=mod) x-=mod;
}
int n,k,L;
struct node
{
	int x,y,c;
}a[N],b[N],qwq;
bool cmpX(const node &u,const node &v)
{
	return u.x<v.x;
}
bool cmpY(const node &u,const node &v)
{
	return u.y<v.y;
}
int X[N],Y[N],cntX,cntY,m;
vector<int>p[N];
map<int,int>q[N];
int tot[N],now;
void _add(int x)
{
	now+=!tot[x];
	tot[x]++;
}
int Min[N];
ll ans=0;
struct sgt
{
	int Min1,Min2,tot1,tag;
	ll sum;
	sgt()
	{
		tag=-inf;
		sum=tot1=0;
		Min1=Min2=inf;
	}
	void cover(int x)
	{
		if (Min1<x&&x<Min2)
		{
			add(sum,mod-1LL*(x-Min1)*tot1%mod);
			Min1=x;
		}
		tag=max(tag,x);
	}
}t[N*4],null;
sgt make(int x,int y)
{
	sgt ret;
	ret.Min1=x;
	ret.sum=1LL*(L-x)*(Y[y]-Y[y-1])%mod;
	ret.Min2=inf;
	ret.tot1=Y[y]-Y[y-1];
	ret.tag=-inf;
	return ret;
}
sgt operator +(const sgt &a,const sgt &b)
{
	sgt ret;
	ret.sum=(a.sum+b.sum)%mod;
	if (a.Min1<b.Min1)
	{
		ret.Min1=a.Min1;
		ret.tot1=a.tot1;
		ret.Min2=min(a.Min2,b.Min1);
	}
	if (a.Min1>b.Min1)
	{
		ret.Min1=b.Min1;
		ret.tot1=b.tot1;
		ret.Min2=min(a.Min1,b.Min2);
	}
	if (a.Min1==b.Min1)
	{
		ret.Min1=a.Min1;
		ret.tot1=a.tot1+b.tot1;
		ret.Min2=min(a.Min2,b.Min2);
	}
	return ret;
}
inline void push_down(int w)
{
	if (t[w].tag==-inf) return;
	t[ls].cover(t[w].tag);
	t[rs].cover(t[w].tag);
	t[w].tag=inf;
}
void build(int w,int l,int r)
{
	if (l==r) return void(t[w]=make(Y[Min[l]],l));
	build(ls,l,mid);
	build(rs,mid+1,r);
	t[w]=t[ls]+t[rs];
}
void change(int w,int l,int r,int L,int R,int x)
{
	if (r<L||R<l) return;
	if (L<=l&&r<=R)
	{
		if (x<=t[w].Min1) return;
		if (t[w].Min1<x&&x<t[w].Min2) return t[w].cover(x);
	}
	push_down(w);
	change(ls,l,mid,L,R,x);
	change(rs,mid+1,r,L,R,x);
	t[w]=t[ls]+t[rs];
}

signed main(signed Recall,char *_902_[])
{
	(void)Recall,(void)_902_;
	n=read();
	k=read();
	L=read();
	for (int i=1;i<=n;i++)
	{
		X[++cntX]=a[i].x=read();
		Y[++cntY]=a[i].y=read();
		a[i].c=read();
	}
	sort(a+1,a+1+n,cmpX);
	sort(X+1,X+1+cntX);
	sort(Y+1,Y+1+cntY);
	cntX=unique(X+1,X+1+cntX)-X-1;
	cntY=unique(Y+1,Y+1+cntY)-Y-1;
	X[0]=Y[0]=-1;
	X[cntX+1]=Y[cntY+1]=L;
	for (int i=1;i<=n;i++) a[i].x=lower_bound(X+1,X+1+cntX,a[i].x)-X;
	for (int i=1;i<=n;i++) a[i].y=lower_bound(Y+1,Y+1+cntY,a[i].y)-Y;
	for (int i=1,ii=1;i<=cntX;i++)
	{
		now=m=0;
		while (a[ii].x<i) ii++;
		for (int j=1;j<=n;j++) p[j].clear();
		for (int j=1;j<=k;j++) q[j].clear();
		for (int j=ii;j<=n;j++) p[a[j].x].push_back(j);
		for (int j=ii;j<=n;j++) q[a[j].c][a[j].y]++;
		for (int j=ii;j<=n;j++) b[++m]=a[j];
		sort(b+1,b+1+m,cmpY);
		for (int j=1;j<=k;j++) tot[j]=0;
		for (int j=cntY,l=m,r=m;j>=1;j--)
		{
			while (r&&b[r].y>=j) _add(b[r--].c);
			while (l>r&&tot[b[l].c]>1) tot[b[l--].c]--;
			if (now==k) Min[j]=b[l].y;
				   else Min[j]=cntY+1;
		}
		build(1,1,cntY);
		for (int j=cntX;j>=i;j--)
		{
			add(ans,t[1].sum*(X[j+1]-X[j])%mod*(X[i]-X[i-1])%mod);
			for (int k=0;k<(int)p[j].size();k++)
			{
				qwq=a[p[j][k]];
				if (q[qwq.c][qwq.y]>1) q[qwq.c][qwq.y]--;
				else
				{
					q[qwq.c].erase(qwq.y);
					int pre=q[qwq.c].lower_bound(qwq.y)!=q[qwq.c].begin()&&
							--q[qwq.c].lower_bound(qwq.y)!=q[qwq.c].end()?
							(--q[qwq.c].lower_bound(qwq.y))->first:
							0;
					int suf=q[qwq.c].upper_bound(qwq.y)!=q[qwq.c].end()?
							q[qwq.c].upper_bound(qwq.y)->first:
							cntY+1;
					change(1,1,cntY,pre+1,qwq.y,Y[suf]);//max 
				}
			}
		}
	}
	print(ans);

	return 0;
}
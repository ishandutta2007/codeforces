#include<cstdio>
#include<cstring>
#include<algorithm>
#include<set>
using namespace std;
struct pt
{
	int u,v,w,id;
	pt(int u=0,int v=0,int w=0,int id=0):u(u),v(v),w(w),id(id){}
	bool operator<(const pt x) const
	{
		if(w!=x.w) return w<x.w;
		if(u!=x.u) return u<x.u;
		return v<x.v;
	}
};
set<pt> st;
int n,m,sz[500005],lsz[500005],ch[500005][2],rev[500005],mx[500005],mxid[500005];
int f[500005],ct,e[500005][3],ppt;
inline int nroot(int x)
{
	return ch[f[x]][0]==x||ch[f[x]][1]==x;
}
void pushup(int x)
{
	sz[x]=lsz[x]+sz[ch[x][0]]+sz[ch[x][1]]+(x<=n);
	mx[x]=max(max(mx[ch[x][0]],mx[ch[x][1]]),e[x][2]);
	if(mx[x]==mx[ch[x][0]]) mxid[x]=mxid[ch[x][0]];
	else if(mx[x]==mx[ch[x][1]]) mxid[x]=mxid[ch[x][1]];
	else mxid[x]=x;
}
void pushr(int x)
{
	rev[x]^=1;
	swap(ch[x][0],ch[x][1]);
}
void pushdown(int x)
{
	if(rev[x])
	{
		if(ch[x][0]) pushr(ch[x][0]);
		if(ch[x][1]) pushr(ch[x][1]);
		rev[x]^=1;
	}
}
void pushall(int x)
{
	if(nroot(x)) pushall(f[x]);
	pushdown(x);
}
void rotate(int x)
{
	int y=f[x],z=f[y],k=ch[y][1]==x,r=ch[x][!k];
	if(nroot(y)) ch[z][ch[z][1]==y]=x;
	ch[x][!k]=y;
	ch[y][k]=r;
	f[r]=y;
	f[y]=x;
	f[x]=z;
	pushup(y);
	pushup(x);
}
void splay(int x)
{
	pushall(x);
	while(nroot(x))
	{
		int y=f[x],z=f[y];
		if(nroot(y)) rotate((ch[y][1]==x)^(ch[z][1]==y)?x:y);
		rotate(x);
	}
}
void access(int x)
{
	for(int y=0;x;y=x,x=f[x])
	{
		splay(x);
		lsz[x]+=sz[ch[x][1]];
		ch[x][1]=y;
		lsz[x]-=sz[y];
		pushup(x);
	}
}
void makeroot(int x)
{
	access(x);
	splay(x);
	pushr(x);
}
int findroot(int x)
{
	access(x);
	splay(x);
	while(ch[x][0]) pushdown(x),x=ch[x][0];
	return x;
}
void link(int x,int y)
{
	makeroot(x);
	if(findroot(y)==x) return;
//	printf("link:x=%d,y=%d\n",x,y);
	f[x]=y;
	lsz[y]+=sz[x];
}
void cut(int x,int y)
{
	//printf("cut:x=%d,y=%d\n",x,y);
	makeroot(x);
	access(y);
	splay(y);
	ch[y][0]=f[x]=0;
	pushup(y);
}
int getsz(int x)
{
	makeroot(x);
	return sz[x];
}
bool check(int x,int y)
{
	makeroot(x);
	return findroot(y)!=x;
}
int split(int x,int y)
{
	makeroot(x);
	access(y);
	splay(y);
	return mxid[y];
}
void cut2(int q)
{
	cut(e[q][0],q);
	cut(e[q][1],q);
	st.erase(pt(e[q][0],e[q][1],e[q][2]));
}
int main()
{
	scanf("%d%d",&n,&m);
	ct=ppt=n;
	for(int i=1;i<=n;i++)
		sz[i]=1;
	int las=-1;
	for(int i=1;i<=m;i++)
	{
		int u,v,w,fl=0;
		scanf("%d%d%d",&u,&v,&w);
		if(!check(u,v))
		{
			fl=1;
			int q=split(u,v);
			if(e[q][2]>w) cut2(q);
			else
			{
				printf("%d\n",las);
				continue;
			}
		}
		int q1=getsz(u),q2=getsz(v);
		if(q1%2&&q2%2&&ct&&!fl) ct-=2;
	//	printf("u=%d,v=%d,q=%d,%d,ct=%d\n",u,v,q1,q2,ct);
		ppt++;
		e[ppt][0]=u,e[ppt][1]=v,e[ppt][2]=w;
		link(ppt,u);
		link(ppt,v);
		st.insert(pt(u,v,w,ppt));
		while(!ct&&!st.empty())
		{
			pt p=*--st.end();
			split(p.u,p.v);
			if(sz[p.u]%2==0&&sz[p.v]%2==0)
				cut2(p.id);
			else break;
		}
	//	printf("i=%d,ct=%d\n",i,ct);
		if(ct) printf("-1\n");
		else printf("%d\n",las=(--st.end())->w);
	//	for(int j=1;j<=ppt;j++)
	//		printf("j=%d,ch=%d,%d,f=%d,sz=%d,lsz=%d,mx=%d,mxid=%d\n",
	//				j,ch[j][0],ch[j][1],f[j],sz[j],lsz[j],mx[j],mxid[j]);
	}
	return 0;
}
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int B=2150;
struct pt
{
	int l,r,k,id;
	bool operator<(const pt x) const
	{
		if(l/B!=x.l/B) return l<x.l;
		if(r/B!=x.r/B) return r<x.r;
		return id<x.id;
	}
}q[100005];
struct ptt
{
	int val,id;
	bool operator<(const ptt x) const
	{
		return id<x.id;
	}
}b[100005];
int n,m,a[100005],tmp[100005],c[100005][3],qt,qans[100005];
int vis[100005],vis2[100005],L[100005],R[100005],s,bt;
int l,r,k;
void ins(int x)
{
//	printf("-ins:x=%d\n",x);
	x=a[x];
//	printf("ins:x=%d\n",x);
	vis2[vis[x]]--;
	if(vis[x]&&vis2[vis[x]]==0)
	{
		int u=vis[x];
		L[R[u]]=L[u];
		R[L[u]]=R[u];
	}
	vis[x]++;
	if(vis2[vis[x]]==0)
	{
		int u=vis[x],v=R[s];
		L[u]=s,R[s]=u;
		L[v]=u,R[u]=v;
	}
	vis2[vis[x]]++;
}
void del(int x)
{
	x=a[x];
//	printf("del:x=%d\n",x);
	vis2[vis[x]]--;
	if(vis2[vis[x]]==0)
	{
		int u=vis[x];
		L[R[u]]=L[u];
		R[L[u]]=R[u];
	}
	vis[x]--;
	if(vis[x]&&vis2[vis[x]]==0)
	{
		int u=vis[x],v=R[s];
		L[u]=s,R[s]=u;
		L[v]=u,R[u]=v;
	}
	vis2[vis[x]]++;
}
void insk(int x)
{
	int u=c[x][0];
	if(!u) return;
	if(l<=u&&u<=r) del(u);
	a[u]=c[x][1];
	if(l<=u&&u<=r) ins(u);
}
void delk(int x)
{
	int u=c[x][0];
	if(!u) return;
	if(l<=u&&u<=r) del(u);
	a[u]=c[x][2];
	if(l<=u&&u<=r) ins(u);
}
int solve(int x)
{
	bt=0;
	for(int i=R[s];i!=s;i=R[i])
	{
		b[++bt].id=i;
		b[bt].val=vis2[i];
	}
	sort(b+1,b+bt+1);
/*	printf("solve:x=%d,b=",x);
	for(int i=1;i<=bt;i++)
		printf("(%d,%d) ",b[i].id,b[i].val);
	printf("\n");*/
	int nw=0,ct=0,ans=1e9;
	for(int i=1;i<=bt;i++)
	{
		while(ct<x&&nw<bt)
		{
			nw++;
			ct+=b[nw].val;
		}
		if(ct<x) break;
		ans=min(ans,b[nw].id-b[i].id);
		ct-=b[i].val;
	}
	if(ans>1e8) return -1;
	return ans;
}
int main()
{
	scanf("%d%d",&n,&m);
	s=n+1;
	L[s]=R[s]=s;
	for(int i=1;i<=n;i++)
		scanf("%d",&a[i]);
	for(int i=1;i<=m;i++)
	{
		int op,x,y,z;
		scanf("%d%d%d",&op,&x,&y);
		if(op==1)
		{
			scanf("%d",&z);
			qt++;
			q[qt].l=x,q[qt].r=y,q[qt].k=z;
			q[qt].id=i;
		}
		else
		{
			c[i][0]=x,c[i][1]=y;
		}
	}
	memcpy(tmp,a,sizeof(a));
	for(int i=1;i<=m;i++)
		if(c[i][0])
		{
			c[i][2]=tmp[c[i][0]];
			tmp[c[i][0]]=c[i][1];
		}
	sort(q+1,q+qt+1);
	l=1,r=0,k=0;
	for(int i=1;i<=qt;i++)
	{
		int ql=q[i].l,qr=q[i].r,qk=q[i].id;
	//	printf("i=%d,ql=%d,qr=%d,qk=%d\n",i,ql,qr,qk);
		while(k<qk) insk(++k);
		while(k>qk) delk(k--);
		while(r<qr) ins(++r);
		while(l>ql) ins(--l);
		while(r>qr) del(r--);
		while(l<ql) del(l++);
		qans[q[i].id]=solve(q[i].k);
	}
	for(int i=1;i<=m;i++)
		if(!c[i][0])
			printf("%d\n",qans[i]);
	return 0;
}
#include <bits/stdc++.h>
using namespace std;
const int N=500005,inf=1e9;
int a[N],pre[N],ppp[N];
struct ST
{
	int l,r;
	int sum;
	#define l(x) tree[x].l
	#define r(x) tree[x].r
	#define sum(x) tree[x].sum
}tree[4*N];
struct question
{
	int id,l,r;
}b[N];
int n,m,ans[N];
map<int,int>q;
void build(int u,int l,int r)
{
	if (l==r) 
	{
		l(u)=l,r(u)=r,sum(u)=pre[l];
		return;
	}
	int mid=(l+r)/2;
	l(u)=l,r(u)=r;
	build(u*2,l,mid);
	build(u*2+1,mid+1,r);
	sum(u)=min(sum(u*2),sum(u*2+1));
}
void change(int u,int x,int k)
{
	if (l(u)==x&&r(u)==x)
	{
		sum(u)=k;
		return;
	}
	int mid=(l(u)+r(u))/2;
	if (x<=mid) change(u*2,x,k);
	if (mid<x) change(u*2+1,x,k);
	sum(u)=min(sum(u*2),sum(u*2+1));
}
int ask(int u,int l,int r)
{
	if (l(u)>=l&&r(u)<=r) return sum(u);
	int mid=(l(u)+r(u))/2;
	int res=inf;
	if (l<=mid) res=min(ask(u*2,l,r),res);
	if (mid<r) res=min(ask(u*2+1,l,r),res);
	return res;
}
inline int read()
{
    int F=1,ANS=0;
	char C=getchar();
    while (C<'0'||C>'9')
	{
		if (C=='-') F=-1;
		C=getchar();
	}
    while (C>='0'&&C<='9')
	{
		ANS=ANS*10+C-'0';
		C=getchar();
	}
    return F*ANS;
}
bool cmp(question x,question y)
{
	if (x.l==y.l) return x.r<y.r;
	return x.l<y.l;
}
int main()
{
	n=read(),m=read();
	for (int i=1;i<=n;i++)
	{
		a[i]=read();
		int p=q[a[i]];
		if (p==0) pre[i]=inf;
		else pre[i]=i-p,ppp[p]=i;
		q[a[i]]=i;
	}
	build(1,1,n);
	for (int i=1;i<=m;i++)
	{
		b[i].l=read(),b[i].r=read(),b[i].id=i;
	}
	sort(b+1,b+m+1,cmp);
	int nxt=1;
	for (int i=1;i<=m;i++)
	{
		//cout << "ppp" << nxt << endl << b[i].l << endl;
		while (nxt<b[i].l) 
		{
			if (ppp[nxt]) change(1,ppp[nxt],inf);
			//cout << "ppp" << ppp[nxt] << endl;
			nxt++;
		}
		ans[b[i].id]=ask(1,b[i].l,b[i].r);
	}
	for (int i=1;i<=m;i++) 
	{
		if (ans[i]==inf) puts("-1");
		else printf("%d\n",ans[i]);
	}
	return 0;
}
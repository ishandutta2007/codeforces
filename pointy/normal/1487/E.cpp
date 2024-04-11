#include<bits/stdc++.h>
using namespace std;
#define mem(x) memset(x,0,sizeof(x))
int n[5];
const int inf=1000000000;
const int N=300009;
int a[N][5];
int t[N],nxt[N],h[N],cnt;
void add(int x,int y)
{
	t[++cnt]=y;
	nxt[cnt]=h[x];
	h[x]=cnt;
}
struct ST
{
	int l,r;
	int sum;
	#define l(x) tree[x].l
	#define r(x) tree[x].r
	#define sum(x) tree[x].sum
}tree[4*N];
inline int read()
{
	char C;
	int F=1,ANS=0;
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
void build(int p,int l,int r,int t)
{
	l(p)=l,r(p)=r;
	if (l==r)
	{
		sum(p)=a[l][t];
		return;
	}
	int mid=(l+r)/2;
	build(p*2,l,mid,t);
	build(p*2+1,mid+1,r,t); 
	sum(p)=min(sum(p*2),sum(p*2+1));
}
void change(int u,int x,int y)
{
	if (l(u)==r(u))
	{
		sum(u)=y;
		return;
	}
	int mid=(l(u)+r(u))/2;
	if (x<=mid) change(u*2,x,y);
	else change(u*2+1,x,y);
	sum(u)=min(sum(u*2),sum(u*2+1));
}
int main()
{
	for (int i=1;i<=4;i++) n[i]=read();
	for (int i=1;i<=4;i++)
	{
		for (int j=1;j<=n[i];j++) a[j][i]=read();
	}
	for (int i=2;i<=4;i++)
	{
		mem(tree);
		mem(t);
		mem(nxt);
		mem(h);
		cnt=0;
		build(1,1,n[i-1],i-1);
		int m=read();
		for (int j=1;j<=m;j++)
		{
			int x=read(),y=read();
			add(y,x);
		}
		for (int j=1;j<=n[i];j++)
		{
			for (int k=h[j];k;k=nxt[k])
			{
				change(1,t[k],inf);
			}
			a[j][i]+=sum(1);
			for (int k=h[j];k;k=nxt[k])
			{
				change(1,t[k],a[t[k]][i-1]);
			}
		}
	}
	int ans=inf;
	for (int i=1;i<=n[4];i++) ans=min(ans,a[i][4]);
	if (ans==inf) cout <<-1;
	else cout << ans;
	return 0;
}
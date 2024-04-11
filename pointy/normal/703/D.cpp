#include <bits/stdc++.h>
using namespace std;
const int N=1000006;
int n,m,tree[N];
int col[N],pre[N],s[N];
inline int lowbit(int x)
{
	return x&(-x);
}
void add(int x,int k)
{
	if (x==0) return;
	for (;x<=n;x+=lowbit(x)) tree[x]^=k;
}
int ask(int x)
{
	int res=0;
	for (;x;x-=lowbit(x)) res^=tree[x];
	return res;
}
struct ques
{
	int l,r,id;
}q[N];
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
bool cmp(ques x,ques y)
{
	return x.r<y.r;
}
int ans[N];
map<int,int>a;
int main()
{
	n=read();
	for (int i=1;i<=n;i++)
	{
		col[i]=read();
		s[i]=s[i-1]^col[i];
		pre[i]=a[col[i]];
		a[col[i]]=i;
	}
	m=read();
	for (int i=1;i<=m;i++)
	{
		q[i].id=i,q[i].l=read(),q[i].r=read();
	}
	sort(q+1,q+m+1,cmp);
	int tot=0;
	for (int i=1;i<=m;i++)
	{
		while (tot<q[i].r)
		{
			tot++;
			add(tot,col[tot]),add(pre[tot],col[pre[tot]]);
		}
		ans[q[i].id]=ask(q[i].r)^ask(q[i].l-1)^s[q[i].r]^s[q[i].l-1];
	}
	for (int i=1;i<=m;i++) printf("%d\n",ans[i]);
	return 0;
}
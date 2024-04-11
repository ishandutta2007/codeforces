#include<bits/stdc++.h>
using namespace std;
const int N=2e5+5;

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
	if (x<0) putchar('-'),x=-x;
	if (x<10) putchar(x+'0');
	else write(x/10),putchar(x%10+'0');
}
void print(int x,char c='\n')
{
	write(x);
	putchar(c);
}
int mx[N][20],Log[N],p[N],l[N],pl[N][20];
int queryMax(int l,int r)
{
	int k=Log[r-l+1];
	return max(pl[l][k],pl[r-(1<<k)+1][k]);
}
int query(int l,int r)
{
	int k=Log[r-l+1];
	return max(mx[l][k],mx[r-(1<<k)+1][k]);
}
int fa[N],sum[N],ans[N],st[N];
vector<pair<int,int>>q[N];
int find(int x){return x==fa[x]?x:fa[x]=find(fa[x]);}

signed main(signed bangumi,char *ss969[])
{
	(void)bangumi,(void)ss969;
	int n=read();
	for (int i=1;i<=n;i++) p[i]=read(),l[i]=read(),pl[i][0]=p[i]+l[i];
	for (int i=2;i<=n;i++) Log[i]=Log[i/2]+1;
	for (int j=1;j<20;j++)
	for (int i=1;i+(1<<j)-1<=n;i++)
	pl[i][j]=max(pl[i][j-1],pl[i+(1<<j-1)][j-1]);
	for (int i=n;i>=1;i--)
	{
		int pos=upper_bound(p+1,p+1+n,p[i]+l[i])-p-1;
		mx[i][0]=pos>i?query(i+1,pos):i;
		for (int j=1;i+(1<<j)-1<=n;j++)
		mx[i][j]=max(mx[i][j-1],mx[i+(1<<j-1)][j-1]);
	}
	int Q=read();
	for (int i=1;i<=Q;i++)
	{
		int l=read(),r=read();
		q[l].push_back(make_pair(r,i));
	}
	int top=0;
	for (int i=n;i>=1;i--)
	{
		fa[i]=i,sum[i]=sum[find(i+1)]+max(p[i+1]-p[i]-l[i],0);
		st[++top]=i;
		while (top>1&&st[top-1]<=mx[i][0]) fa[st[top]]=st[top-1],top--;
		sum[st[top]]=sum[st[top-1]]+max(p[st[top]+1]-queryMax(i,st[top]),0);
		for (auto j:q[i]) ans[j.second]=sum[find(i)]-sum[find(j.first)];
//		for (int j=1;j<=n;j++) print(sum[find(j)]," \n"[j==n]);
	}
	for (int i=1;i<=Q;i++) print(ans[i]);
	
	return 0;
}
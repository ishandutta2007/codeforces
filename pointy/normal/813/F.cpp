// By: Little09
// Problem: P5787  /
// Contest: Luogu
// URL: https://www.luogu.com.cn/problem/P5787
// Memory Limit: 256 MB
// Time Limit: 1000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

#include <bits/stdc++.h>
using namespace std;
int n,m,k;
const int N=4e5+5;
struct edge
{
	int x,y;
}e[N];
vector<int>t[N*4];
map<int,int>q;
int fa[N],d[N];
struct point
{
	int x,y,z;
};
point st[N*4];
int top;
inline void push(int x,int y,int z)
{
	point u;
	u.x=x,u.y=y,u.z=z;
	st[++top]=u;
}
int find(int x)
{
	while (x!=fa[x]) x=fa[x];
	return fa[x];
}
void merge(int x,int y)
{
	int x1=find(x),y1=find(y);
	if (d[x1]>d[y1]) swap(x1,y1);
	push(x1,y1,d[x1]==d[y1]);
	fa[x1]=y1;
	if (d[x1]==d[y1]) d[y1]++;
}
void update(int u,int L,int R,int l,int r,int x)
{
	if (l<=L&&R<=r)
	{
		t[u].push_back(x);
		return;
	}
	int mid=(L+R)>>1;
	if (l<=mid) update(u*2,L,mid,l,r,x);
	if (mid<r) update(u*2+1,mid+1,R,l,r,x);
}
void solve(int u,int l,int r)
{
	int tot=top;
	bool flag=0;
	for (int i=0;i<t[u].size();i++)
	{
		int x=e[t[u][i]].x,y=e[t[u][i]].y;
		int x1=find(x),y1=find(y);
		if (x1==y1)
		{
			for (int j=l;j<=r;j++) printf("NO\n");
			flag=1;
			break;
		}
		merge(x,y+n),merge(y,x+n);
	}
	if (flag==0)
	{
		if (l==r) printf("YES\n");
		else
		{
			int mid=(l+r)>>1;
			solve(u*2,l,mid),solve(u*2+1,mid+1,r);
		}
	}
	while (top>tot)
	{
		d[fa[st[top].x]]-=st[top].z;
		fa[st[top].x]=st[top].x;
		top--;
	}
	return;
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

int main()
{
	n=read(),k=read();
	for (int i=1;i<=k;i++)
	{
		e[i].x=read(),e[i].y=read();
		int tmp=e[i].x*n+e[i].y;
		if (q[tmp]==0) q[tmp]=i;
		else 
		{
			update(1,1,k,q[tmp],i-1,i);
			q[tmp]=0;
		}
	}
	for (int i=1;i<=k;i++)
	{
		int tmp=e[i].x*n+e[i].y;
		if (q[tmp]!=0)
		{
			update(1,1,k,q[tmp],k,i);
			q[tmp]=0;
		}
	}
	for (int i=1;i<=m;i++)
	{
		e[i].x=read(),e[i].y=read();
		int l=read()+1,r=read();
		update(1,1,k,l,r,i);
	}
	for (int i=1;i<=2*n;i++) fa[i]=i,d[i]=1;
	solve(1,1,k);
	return 0;
}
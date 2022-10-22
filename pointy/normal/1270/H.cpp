// Author: Little09
// Problem: CF1270H Number of Components
// Contest: Luogu
// URL: https://www.luogu.com.cn/problem/CF1270H
// Memory Limit: 250 MB
// Time Limit: 8000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

#include <bits/stdc++.h>
using namespace std;
int n,q,m;
const int N=1e6+50;
int s[N*4],mn[N*4],add[N*4],a[N];
inline void push_down(int u)
{
	if (add[u]==0) return;
	mn[u*2]+=add[u],mn[u*2+1]+=add[u];
	add[u*2]+=add[u],add[u*2+1]+=add[u];
	add[u]=0;
}
inline void push_up(int u)
{
	if (s[u*2]==0) mn[u]=mn[u*2+1],s[u]=s[u*2+1];
	else if (s[u*2+1]==0) mn[u]=mn[u*2],s[u]=s[u*2];
	else if (mn[u*2]<mn[u*2+1]) mn[u]=mn[u*2],s[u]=s[u*2];
	else if (mn[u*2]>mn[u*2+1]) mn[u]=mn[u*2+1],s[u]=s[u*2+1];
	else mn[u]=mn[u*2],s[u]=s[u*2]+s[u*2+1];
}
void update(int u,int L,int R,int l,int r,int x)
{
	if (l<=L&&R<=r)
	{
		mn[u]+=x,add[u]+=x;
		return;
	}
	push_down(u);
	int mid=(L+R)>>1;
	if (l<=mid) update(u*2,L,mid,l,r,x);
	if (mid<r) update(u*2+1,mid+1,R,l,r,x);
	push_up(u);
}
void modify(int u,int l,int r,int x,int y)
{
	if (l==r)
	{
		s[u]+=y;
		return;
	}
	push_down(u);
	int mid=(l+r)>>1;
	if (x<=mid) modify(u*2,l,mid,x,y);
	else modify(u*2+1,mid+1,r,x,y);
	push_up(u);
}
inline void change(int x,int y)
{
	if (a[x]<a[x+1]) return;
	update(1,0,m,a[x+1],a[x]-1,y);
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cin >> n >> q;
	m=1e6+3;
	for (int i=1;i<=n;i++) cin >> a[i];
	a[0]=m,a[n+1]=0;
	for (int i=0;i<=n;i++) change(i,1);
	for (int i=1;i<=n;i++) modify(1,0,m,a[i],1);
	for (int i=1;i<=q;i++)
	{
		int x,y;
		cin >> x >> y;
		change(x,-1),change(x-1,-1);
		modify(1,0,m,a[x],-1);
		a[x]=y;
		change(x,1),change(x-1,1);
		modify(1,0,m,a[x],1);
		cout << s[1] << "\n";
	}
	return 0;
}
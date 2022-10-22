// Author: Little09
// Problem: CF1172F Nauuo and Bug
// Contest: Luogu
// URL: https://www.luogu.com.cn/problem/CF1172F
// Memory Limit: 1000 MB
// Time Limit: 4000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

#include <bits/stdc++.h>
using namespace std;
#define ll long long
const ll inf=1000000000000000000;
const int N=1e6+5;
vector<ll>c[N*4];
ll sum[N*4],a[N];
int n,m;
ll p;
inline void push_up(int u,int lenl,int lenr)
{
	sum[u]=sum[u*2]+sum[u*2+1];
	int y=0;
	for (int x=0;x<=lenl;x++)
	{
		if (y>lenr) y--;
		while (y<=lenr)
		{
			if (c[u*2][x+1]-1+sum[u*2]-p*x<c[u*2+1][y])
			{
				if (y>0) y--;
				break;
			} 
			c[u][x+y]=min(c[u][x+y],max(c[u*2][x],c[u*2+1][y]-sum[u*2]+p*x));
			y++;
		}
	}
}
void build(int u,int l,int r)
{
	for (int i=l;i<=r+2;i++) c[u].push_back(inf);
	c[u][0]=-inf;
	if (l==r)
	{
		c[u][1]=p-a[l];
		sum[u]=a[l];
		return;
	}
	int mid=(l+r)>>1;
	build(u*2,l,mid),build(u*2+1,mid+1,r);
	push_up(u,mid-l+1,r-mid);
}
ll ask(int u,int L,int R,int l,int r,ll x)
{
	if (l<=L&&R<=r)
	{
		ll t=upper_bound(c[u].begin(),c[u].end(),x)-c[u].begin()-1;
		return x+sum[u]-t*p;
	}
	int mid=(L+R)>>1;
	if (l<=mid) x=ask(u*2,L,mid,l,r,x);
	if (mid<r) x=ask(u*2+1,mid+1,R,l,r,x);
	return x;
}


int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cin >> n >> m >> p;
	for (int i=1;i<=n;i++) cin >> a[i];
	build(1,1,n);
	for (int i=1;i<=m;i++)
	{
		int l,r;
		cin >> l >> r;
		cout << ask(1,1,n,l,r,0) << endl;
	}
	return 0;
}
// Author: Little09
// Problem: CF1638E Colorful Operations
// Contest: Luogu
// URL: https://www.luogu.com.cn/problem/CF1638E
// Memory Limit: 250 MB
// Time Limit: 4000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

#include <bits/stdc++.h>
using namespace std;
int n,m;
#define ll long long
#define lowbit(x) (x&(-x))
const int N=1e6+5;
ll tree[N],tag[N];
inline void add(int x,ll k)
{
	for (;x<=n;x+=lowbit(x)) tree[x]+=k;
}
inline ll ask(int x)
{
	ll ans=0;
	for (;x;x-=lowbit(x)) ans+=tree[x];
	return ans;
}
struct node
{
	int l,r;
	mutable int v;
	node(int x=-1,int y=-1,int z=0)
	{
		l=x,r=y,v=z;
	}
	bool operator < (const node &x) const
	{
		return l<x.l;
	}
};
set<node>odt;
auto spilt(int x)
{
	if (x>n) return odt.end();
	auto it=odt.lower_bound(node(x));
	if (it!=odt.end()&&it->l==x) return it;
	it--;
	int l=it->l,r=it->r,v=it->v;
	odt.erase(it);
	odt.insert(node(l,x-1,v));
	return odt.insert(node(x,r,v)).first;
}
void assign(int l,int r,int c)
{
	auto itr=spilt(r+1),itl=spilt(l);
	for (auto it=itl;it!=itr;it++)
	{
		add(it->l,tag[it->v]);
		add(it->r+1,-tag[it->v]);
	}
	odt.erase(itl,itr);
	odt.insert(node(l,r,c));
	add(l,-tag[c]),add(r+1,tag[c]);
}
ll calc(int x)
{
	auto it=--odt.upper_bound(node(x));
	return tag[it->v];
}


int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cin >> n >> m;
	odt.insert(node(1,n,1));
	for (int i=1;i<=m;i++)
	{
		string s;
		cin >> s;
		if (s=="Color")
		{
			int l,r,x;
			cin >> l >> r >> x;
			assign(l,r,x);
		}
		else if (s=="Query")
		{
			int x;
			cin >> x;
			cout << calc(x)+ask(x) << endl;
		}
		else
		{
			ll x,y;
			cin >> x >> y;
			tag[x]+=y;
		}
	}
	return 0;
}
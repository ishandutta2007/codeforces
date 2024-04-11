// This amazing code is by Eric Sunli Chen.
#include <algorithm>
#include <bitset>
#include <cmath>
#include <cstring>
#include <cstdio>
#include <cstdlib>
#include <ctime>
#include <iomanip>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <string>
#include <utility>
#include <vector>
using namespace std;
template<typename T> void get_int(T &x)
{
	char t=getchar();
	bool neg=false;
	x=0;
	for(; (t>'9'||t<'0')&&t!='-'; t=getchar());
	if(t=='-')neg=true,t=getchar();
	for(; t<='9'&&t>='0'; t=getchar())x=x*10+t-'0';
	if(neg)x=-x;
}
template<typename T> void print_int(T x)
{
	if(x<0)putchar('-'),x=-x;
	short a[20]= {},sz=0;
	while(x>0)a[sz++]=x%10,x/=10;
	if(sz==0)putchar('0');
	for(int i=sz-1; i>=0; i--)putchar('0'+a[i]);
}
#define ff first
#define ss second
#define pb push_back
#define mp make_pair
#define get1(a) get_int(a)
#define get2(a,b) get1(a),get1(b)
#define get3(a,b,c) get1(a),get2(b,c)
#define printendl(a) print_int(a),puts("")
typedef long long LL;
typedef unsigned long long uLL;
typedef pair<int,int> pii;
const int inf=0x3f3f3f3f;
const LL Linf=1ll<<62;
const double pi=acos(-1.0);

vector<int>g[100111];
int n,r[100111],ans;
#define inc orzyjz
#define dec yjzorz
set<pii>inc[100111],dec[100111];
void ins(set<pii>&s,pii t)
{
	set<pii>::iterator it=s.lower_bound(mp(t.ff,inf)),it2;
	if(it!=s.begin())
	{
		it--;
		if(it->ss>=t.ss)return;
		it++;
	}
	while(it!=s.end())
	{
		if(it->ss<=t.ss)
		{
			it2=it;it2++;
			s.erase(it);it=it2;
		}
		else break;
	}
	s.insert(t);
}
int sz[100111];
void dfs(int x,int f=0)
{
	sz[x]=1;int mx=0;
	int vinc=1,vdec=1;
	for(int i=0;i<(int)g[x].size();i++)
	{
		int&v=g[x][i];if(v==f)continue;
		dfs(v,x);
		auto it=inc[v].lower_bound(mp(r[x],0));
		int tinc=vinc,tdec=vdec;
		if(it!=inc[v].begin()){it--;vinc=max(vinc,it->ss+1);}
		it=dec[v].lower_bound(mp(-r[x],0));
		if(it!=dec[v].begin()){it--;vdec=max(vdec,it->ss+1);}
		sz[x]+=sz[v];
		if(sz[v]>sz[mx])mx=v;
	}
	ans=max(ans,max(vinc,vdec));
	if(mx)
	{
		inc[x].swap(inc[mx]);
		dec[x].swap(dec[mx]);
	}
	ins(inc[x],mp(r[x],vinc));
	ins(dec[x],mp(-r[x],vdec));
	for(auto v:g[x])if(v!=f&&v!=mx)
	{
		for(auto it:inc[v])
		{
			auto it2=dec[x].lower_bound(mp(-it.ff,0));
			if(it2!=dec[x].begin())
			{
				it2--;
				ans=max(ans,it2->ss+it.ss);
			}
		}
		for(auto it:dec[v])
		{
			auto it2=inc[x].lower_bound(mp(-it.ff,0));
			if(it2!=inc[x].begin())
			{
				it2--;
				ans=max(ans,it2->ss+it.ss);
			}
		}
		for(auto it:inc[v])ins(inc[x],it);
		for(auto it:dec[v])ins(dec[x],it);
	}
}
int main()
{
	get1(n);
	for(int i=1;i<=n;i++)get1(r[i]);
	for(int i=1,u,v;i<n;i++)
	{
		get2(u,v);
		g[u].pb(v);g[v].pb(u);
	}
	dfs(1);
	printendl(ans);
	return 0;
}
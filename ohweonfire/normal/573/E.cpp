#include<bits/stdc++.h>
using namespace std;
#define ff first
#define ss second
#define pb push_back
#define mp make_pair
typedef long long LL;
typedef unsigned long long uLL;
typedef pair<int,int> pii;

const int maxn=100111;

mt19937 rng;
struct node
{
	int sz,rk,ls,rs;
	LL val,dlt;
	node(){sz=rk=ls=rs=val=dlt=0;}
	void add(LL x){val+=x;dlt+=x;}
};
node a[maxn];
void push(int t)
{
	if(a[t].dlt)
	{
		if(a[t].ls)a[a[t].ls].add(a[t].dlt);
		if(a[t].rs)a[a[t].rs].add(a[t].dlt);
		a[t].dlt=0;
	}
}
void pull(int t){a[t].sz=a[a[t].ls].sz+a[a[t].rs].sz+1;}

int find(int o,int v,int sz)
{
	if(!o)return sz;
	push(o);
	int id=a[a[o].ls].sz+sz+1;
	if(a[o].val>(LL)v*id)return find(a[o].rs,v,id);
	else return find(a[o].ls,v,sz);
}

int merge(int k1,int k2)
{
	if(!k1||!k2)return k1|k2;
	if(a[k1].rk<a[k2].rk)
	{
		push(k1);
		a[k1].rs=merge(a[k1].rs,k2);
		pull(k1);return k1;
	}
	else
	{
		push(k2);
		a[k2].ls=merge(k1,a[k2].ls);
		pull(k2);return k2;
	}
}
void split(int o,int sz,int&k1,int&k2)
{
	if(!o){k1=k2=0;return;}
	push(o);
	if(a[a[o].ls].sz>=sz)
	{
		k2=o;
		split(a[o].ls,sz,k1,a[o].ls);
	}
	else
	{
		k1=o;
		split(a[o].rs,sz-a[a[o].ls].sz-1,a[o].rs,k2);
	}
	pull(o);
}

int n,val[maxn];
LL f[maxn],ans,sum;

void dfs(int o)
{
	if(!o)return;
	push(o);
	dfs(a[o].ls);
	sum+=a[o].val;
	ans=max(ans,sum);
	dfs(a[o].rs);
}

int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++)scanf("%d",val+i);
	
	for(int i=1;i<=n;i++)
	{
		a[i].rk=rng();
		a[i].sz=1;
	}
	int rt=1,rt2;a[rt].val=val[1];
	
	for(int i=2;i<=n;i++)
	{
		int sz=find(rt,val[i],0);
		a[i].val=(LL)val[i]*(sz+1);
		
		split(rt,sz,rt,rt2);
		if(rt2)a[rt2].add(val[i]);
		rt=merge(rt,merge(i,rt2));
	}
	ans=0;
	dfs(rt);
	printf("%lld\n",ans);
	return 0;
}
//ANMHLIJKTJIY!
#pragma GCC optimize(2)
#pragma GCC optimize("Ofast")
#pragma GCC optimize("inline","fast-math","unroll-loops","no-stack-protector")
#pragma GCC diagnostic error "-fwhole-program"
#pragma GCC diagnostic error "-fcse-skip-blocks"
#pragma GCC diagnostic error "-funsafe-loop-optimizations"
#include <bits/stdc++.h>
#define INF 1000000000
#define LINF 1000000000000000000
#define MOD 1000000007
#define mod 998244353
#define F first
#define S second
#define ll int
#define N 200010
#define B 4000
using namespace std;
string res="";
ll n,m,tp[N],fa[N],sz[N],rev[N];
pair<ll,ll> qry[N][2];
stack<pair<ll,ll> > stk;
set<pair<ll,ll> > ap1,ap2;
ll getf(ll x){return (x==fa[x])?x:getf(fa[x]);}
void merg(ll x,ll y,bool tp)
{
	x=getf(x),y=getf(y);
	if(x==y)
	{
		return;
	}
	if(sz[x]>sz[y])
	{
		swap(x,y);
	}
	if(tp)
	{
		stk.push(make_pair(x,y));
	}
	fa[x]=y;
	sz[y]+=sz[x];
	return;
}
void recalc()
{
	while(!stk.empty())
	{
		sz[stk.top().S]-=sz[stk.top().F];
		fa[stk.top().F]=stk.top().F;
		stk.pop();
	}
	for(set<pair<ll,ll> >::iterator it=ap2.begin();it!=ap2.end();it++)
	{
		merg((*it).F,(*it).S,true);
	}
	return;
}
void solve(ll l,ll r)
{
	ll i;
	while(!stk.empty())
	{
		stk.pop();
	}
	for(i=0;i<n;i++)
	{
		fa[i]=i;
		sz[i]=1;
	}
	set<pair<ll,ll> > allnd;
	ap1.clear(),ap2.clear();
	for(i=l;i<=r;i++)
	{
		if(tp[i]==1)
		{
			allnd.insert(qry[i][0]);
			allnd.insert(qry[i][1]);
		}
	}
	for(i=0;i<l;i++)
	{
		if(tp[i]==1)
		{
			pair<ll,ll> cur=qry[i][rev[i]];
			if(allnd.find(cur)==allnd.end())
			{
				if(ap1.find(cur)==ap1.end())
				{
					ap1.insert(cur);
				}
				else
				{
					ap1.erase(cur);
				}
			}
			else
			{
				if(ap2.find(cur)==ap2.end())
				{
					ap2.insert(cur);
				}
				else
				{
					ap2.erase(cur);
				}
			}
		}
	}
	for(set<pair<ll,ll> >::iterator it=ap1.begin();it!=ap1.end();it++)
	{
		merg((*it).F,(*it).S,false);
	}
	for(i=l;i<=r;i++)
	{
		if(tp[i]==1)
		{
			rev[i]=(i==0)?0:rev[i-1];
			pair<ll,ll> cur=qry[i][rev[i]];
			if(ap2.find(cur)==ap2.end())
			{
				ap2.insert(cur);
				merg(cur.F,cur.S,true);
			}
			else
			{
				ap2.erase(cur);
			}
		}
		else
		{
			recalc();
			pair<ll,ll> cur=qry[i][(i==0)?0:rev[i-1]];
			rev[i]=(getf(cur.F)==getf(cur.S));
			res+=(char)(rev[i]+'0');
		}
	}
	return;
}
int main(){
	ll i,x,y;
	scanf("%d%d",&n,&m);
	for(i=0;i<m;i++)
	{
		scanf("%d%d%d",&tp[i],&x,&y);
		qry[i][0]=make_pair((x-1)%n,(y-1)%n);
		qry[i][1]=make_pair(x%n,y%n);
		if(qry[i][0].S<qry[i][0].F)
		{
			swap(qry[i][0].F,qry[i][0].S);
		}
		if(qry[i][1].S<qry[i][1].F)
		{
			swap(qry[i][1].F,qry[i][1].S);
		}
	}
	for(i=0;i<m;i+=B)
	{
		solve(i,min(m-1,i+B-1));
	}
	printf("%s\n",res.c_str());
	return 0;
}
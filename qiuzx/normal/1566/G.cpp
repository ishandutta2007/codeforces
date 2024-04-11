//ANMHLIJKTJIY!
#pragma GCC optimize(2)
#include <bits/stdc++.h>
#define INF 1000000000
#define LINF 1000000000000000000
#define MOD 1000000007
#define mod 998244353
#define F first
#define S second
#define ll long long
#define N 100010
using namespace std;
ll n,m,q;
multiset<pair<ll,pair<ll,ll> > > med[N],sm3[N],tsm,alled;
multiset<pair<ll,ll> > vt[N];
multiset<ll> allv;
ll calc3(ll x)
{
	ll res=0;
	multiset<pair<ll,pair<ll,ll> > >::iterator it=med[x].begin();
	res+=(*it).F;
	it++;
	res+=(*it).F;
	it++;
	res+=(*it).F;
	return res;
}
ll calc1()//a->b a->c a->d
{
	if(allv.empty())
	{
		return LINF;
	}
	return (*allv.begin());
}
ll calc2()//a->b c->d
{
	ll ret,x,y,cnt;
	bool fd=false;
	set<ll> vis;
	//min_edge + c->d
	ret=(*alled.begin()).F;
	x=(*alled.begin()).S.F;
	y=(*alled.begin()).S.S;
	for(multiset<pair<ll,pair<ll,ll> > >::iterator it=tsm.begin();it!=tsm.end();it++)
	{
		if((*it).S.F!=x&&(*it).S.S!=x&&(*it).S.F!=y&&(*it).S.S!=y)
		{
			ret+=(*it).F;
			fd=true;
			break;
		}
	}
	if(!fd)
	{
		ret=LINF;
	}
	for(multiset<pair<ll,pair<ll,ll> > >::iterator it=sm3[x].begin();it!=sm3[x].end();it++)
	{
		if((*it).S.F==y||(*it).S.S==y)
		{
			continue;
		}
		for(multiset<pair<ll,pair<ll,ll> > >::iterator it2=sm3[y].begin();it2!=sm3[y].end();it2++)
		{
			if((*it2).S.F==x||(*it2).S.S==x||(*it2).S.F==(*it).S.F||(*it2).S.S==(*it).S.F||(*it2).S.F==(*it).S.S||(*it2).S.S==(*it).S.S)
			{
				continue;
			}
			ret=min(ret,(*it).F+(*it2).F);
			break;
		}
	}
	return ret;
}
void add_edge(ll x,ll y,ll w)
{
	if(x>y)
	{
		swap(x,y);
	}
	if(med[x].size()>=3)
	{
		allv.erase(calc3(x));
	}
	med[x].insert(make_pair(w,make_pair(x,y)));
	if(med[x].size()>=3)
	{
		allv.insert(calc3(x));
	}
	if(med[y].size()>=3)
	{
		allv.erase(calc3(y));
	}
	med[y].insert(make_pair(w,make_pair(x,y)));
	if(med[y].size()>=3)
	{
		allv.insert(calc3(y));
	}
	alled.insert(make_pair(w,make_pair(x,y)));
	sm3[x].insert(make_pair(w,make_pair(x,y)));
	sm3[y].insert(make_pair(w,make_pair(x,y)));
	tsm.insert(make_pair(w,make_pair(x,y)));
	if(sm3[x].size()>3||sm3[y].size()>3)
	{
		if(sm3[x].size()>3)
		{
			multiset<pair<ll,pair<ll,ll> > >::iterator it=sm3[x].end();
			it--;
			if(tsm.find(*it)!=tsm.end())
			{
				tsm.erase(tsm.find(*it));
			}
			sm3[x].erase(it);
		}
		if(sm3[y].size()>3)
		{
			multiset<pair<ll,pair<ll,ll> > >::iterator it=sm3[y].end();
			it--;
			if(tsm.find(*it)!=tsm.end())
			{
				tsm.erase(tsm.find(*it));
			}
			sm3[y].erase(it);
		}
	}
	return;
}
void erz_edge(ll x,ll y,ll w)
{
	if(x>y)
	{
		swap(x,y);
	}
	if(med[x].size()>=3)
	{
		allv.erase(calc3(x));
	}
	med[x].erase(med[x].lower_bound(make_pair(w,make_pair(x,y))));
	if(med[x].size()>=3)
	{
		allv.insert(calc3(x));
	}
	if(med[y].size()>=3)
	{
		allv.erase(calc3(y));
	}
	med[y].erase(med[y].lower_bound(make_pair(w,make_pair(x,y))));
	if(med[y].size()>=3)
	{
		allv.insert(calc3(y));
	}
	alled.erase(alled.lower_bound(make_pair(w,make_pair(x,y))));
	if(tsm.find(make_pair(w,make_pair(x,y)))!=tsm.end())
	{
		tsm.erase(tsm.lower_bound(make_pair(w,make_pair(x,y))));
	}
	if(sm3[x].find(make_pair(w,make_pair(x,y)))!=sm3[x].end())
	{
		sm3[x].erase(sm3[x].lower_bound(make_pair(w,make_pair(x,y))));
		if(med[x].size()>=3)
		{
			multiset<pair<ll,pair<ll,ll> > >::iterator it=med[x].begin();
			it++,it++;
			sm3[x].insert(*it);
			if(tsm.find(*it)==tsm.end())
			{
				tsm.insert(*it);
			}
		}
	}
	if(sm3[y].find(make_pair(w,make_pair(x,y)))!=sm3[y].end())
	{
		sm3[y].erase(sm3[y].lower_bound(make_pair(w,make_pair(x,y))));
		if(med[y].size()>=3)
		{
			multiset<pair<ll,pair<ll,ll> > >::iterator it=med[y].begin();
			it++,it++;
			sm3[y].insert(*it);
			if(tsm.find(*it)==tsm.end())
			{
				tsm.insert(*it);
			}
		}
	}
	return;
}
int main(){
	ll i,x,y,w,tp;
	scanf("%lld%lld",&n,&m);
	for(i=0;i<m;i++)
	{
		scanf("%lld%lld%lld",&x,&y,&w);
		x--;
		y--;
		vt[x].insert(make_pair(y,w));
		vt[y].insert(make_pair(x,w));
		add_edge(x,y,w);
	}
	scanf("%lld",&q);
	printf("%lld\n",min(calc1(),calc2()));
	while(q--)
	{
		scanf("%lld",&tp);
		if(tp==0)
		{
			scanf("%lld%lld",&x,&y);
			x--;
			y--;
			multiset<pair<ll,ll> >::iterator it=vt[x].lower_bound(make_pair(y,0));
			w=(*it).S;
			vt[x].erase(it);
			vt[y].erase(vt[y].lower_bound(make_pair(x,w)));
			erz_edge(x,y,w);
		}
		else
		{
			scanf("%lld%lld%lld",&x,&y,&w);
			x--;
			y--;
			vt[x].insert(make_pair(y,w));
			vt[y].insert(make_pair(x,w));
			add_edge(x,y,w);
		}
		printf("%lld\n",min(calc1(),calc2()));
	}
	return 0;
}
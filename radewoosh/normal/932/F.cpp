//while (clock()<=69*CLOCKS_PER_SEC)
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace __gnu_pbds;
using namespace std;

template <typename T>
using ordered_set =
    tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

#define sim template < class c
#define ris return * this
#define dor > debug & operator <<
#define eni(x) sim > typename \
  enable_if<sizeof dud<c>(0) x 1, debug&>::type operator<<(c i) {
sim > struct rge { c b, e; };
sim > rge<c> range(c i, c j) { return rge<c>{i, j}; }
sim > auto dud(c* x) -> decltype(cerr << *x, 0);
sim > char dud(...);
struct debug {
#ifdef LOCAL
~debug() { cerr << endl; }
eni(!=) cerr << boolalpha << i; ris; }
eni(==) ris << range(begin(i), end(i)); }
sim, class b dor(pair < b, c > d) {
  ris << "(" << d.first << ", " << d.second << ")";
}
sim dor(rge<c> d) {
  *this << "[";
  for (auto it = d.b; it != d.e; ++it)
    *this << ", " + 2 * (it == d.b) << *it;
  ris << "]";
}
#else
sim dor(const c&) { ris; }
#endif
};
#define imie(...) " [" << #__VA_ARGS__ ": " << (__VA_ARGS__) << "] "

#define shandom_ruffle random_shuffle

using ll=long long;
using zbio=ordered_set < pair <ll,ll> >;
const int nax=100*1007;
using mag=long double;

int n;

ll a[nax];
ll b[nax];

vector <int> graf[nax];

zbio otocz[nax];
zbio otoczmin[nax];

ll dp[nax];

zbio::iterator it, jt, kt;

mag ilowek(pair <ll,ll> s, pair <ll,ll> a, pair <ll,ll> b)
{
	a.first-=s.first;
	a.second-=s.second;
	b.first-=s.first;
	b.second-=s.second;
	return ((mag)a.first)*b.second-((mag)a.second)*b.first;
}

void dorzuc(zbio &v, pair <ll,ll> w)
{
	it=v.lower_bound(w);
	//~ if (it!=v.end())
		//~ debug() << w << " widzi " << *it; 
	//~ else
		//~ debug() << w << " slepe ";
	while(it!=v.end() && (*it).second>=w.second)
	{
		jt=it;
		it++;
		v.erase(jt);
	}
	if (it!=v.begin())
	{
		it--;
		if ((*it).second<=w.second)
			return;
	}
	it=v.lower_bound(w);
	if (it!=v.end() && it!=v.begin())
	{
		jt=it;
		jt--;
		if (ilowek(*it, *jt, w)<=0)
			return;
	}
	v.insert(w);
	jt=it;
	jt--;
	while(it!=v.end())
	{
		kt=it;
		kt++;
		if (kt==v.end())
			break;
		if (ilowek(*kt, w, *it)<=0)
		{
			v.erase(it);
			it=kt;
		}
		else
		{
			break;
		}
	}
	if (jt!=v.begin())
	{
		jt--;
		while(jt!=v.begin())
		{
			kt=jt;
			kt--;
			if (ilowek(w, *kt, *jt)<=0)
			{
				v.erase(jt);
				jt=kt;
			}
			else
			{
				break;
			}
		}
	}
	//~ debug() << "chuj ";
	//~ assert(0);
}

void dopisz(zbio &v, zbio &u)
{
	if ((int)v.size()<(int)u.size())
		v.swap(u);
	for (auto i : u)
		dorzuc(v, i);
}

void znajdzopt(int v)
{
	int k=otocz[v].size();
	int tsa=0;
	int tsb=k-1;
	int ts1, ts2;
	pair <ll,ll> raz, dwa;
	while(tsa<tsb)
	{
		ts1=(tsa+tsb)/2;
		ts2=ts1+1;
		it=otocz[v].find_by_order(ts1);
		raz=*it;
		it++;
		dwa=*it;
		if (raz.first+raz.second*a[v]<dwa.first+dwa.second*a[v])
			tsb=ts1;
		else
			tsa=ts2;
	}
	raz=*otocz[v].find_by_order(tsa);
	dp[v]=raz.first+raz.second*a[v];
	
	
	k=otoczmin[v].size();
	tsa=0;
	tsb=k-1;
	ts1, ts2;
	while(tsa<tsb)
	{
		ts1=(tsa+tsb)/2;
		ts2=ts1+1;
		it=otoczmin[v].find_by_order(ts1);
		raz=*it;
		it++;
		dwa=*it;
		if (raz.first-raz.second*a[v]<dwa.first-dwa.second*a[v])
			tsb=ts1;
		else
			tsa=ts2;
	}
	raz=*otoczmin[v].find_by_order(tsa);
	dp[v]=min(dp[v], raz.first-raz.second*a[v]);
}

void dfs(int v, int oj)
{
	int lis=1;
	for (int i : graf[v])
	{
		if (i==oj)
			continue;
		dfs(i, v);
		dopisz(otocz[v], otocz[i]);
		dopisz(otoczmin[v], otoczmin[i]);
		lis=0;
	}
	//~ debug() << v << " widzi " << otocz[v];
	if (!lis)
		znajdzopt(v);
	//~ debug() << v << " to " << dp[v];
	dorzuc(otocz[v], {dp[v], b[v]});
	dorzuc(otoczmin[v], {dp[v], -b[v]});
	//~ debug() << v << " zostawia " << otocz[v];
}

int main()
{
	//~ debug() << ilowek({0, 0}, {0, 1}, {-1, 1});
	scanf("%d", &n);
	for (int i=1; i<=n; i++)
		scanf("%lld", &a[i]);
	for (int i=1; i<=n; i++)
		scanf("%lld", &b[i]);
	for (int i=1; i<n; i++)
	{
		int v, u;
		scanf("%d%d", &v, &u);
		graf[v].push_back(u);
		graf[u].push_back(v);
	}
	dfs(1, 0);
	
	for (int i=1; i<=n; i++)
		printf("%lld ", dp[i]);
	printf("\n");
	return 0;
}
//~ while (clock()<=69*CLOCKS_PER_SEC)
//~ #pragma comment(linker, "/stack:200000000")
#pragma GCC optimize("O3")
//~ #pragma GCC target ("avx2")
//~ #pragma GCC optimize("Ofast")
//~ #pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
//~ #pragma GCC optimize("unroll-loops")
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
using pii=pair<int,int>;
using pll=pair<ll,ll>;
using vi=vector<int>;
using vll=vector<ll>;
const int nax=1000*1007;
const ll inf=1e18;

int n;
ll t;

ll tab[nax];
ll stan[nax];
ll odl[nax];

ll wyn;

ll start[nax];

ll czek(ll a, ll b)
{
	if (a<=b)
		return b-a;
	return b-a+t;
}

ll dp[nax];
set<pair<pll,int>> setel;
set<pll> setel2;

void cut(ll v)
{
	auto it=setel.lower_bound({{v, inf}, 0});
	it--;
	auto x=(*it);
	if (x.first.first==v)
		return;
	setel.erase(it);
	setel.insert({{x.first.first, v}, x.second});
	setel.insert({{v, x.first.second}, x.second});
}

void cut2(ll v)
{
	auto it=setel2.lower_bound({v, inf});
	if (it==setel2.begin())
		return;
	it--;
	auto x=(*it);
	if (x.first>=v || x.second<=v)
		return;
	setel2.erase(it);
	setel2.insert({x.first, v});
	setel2.insert({v, x.second});
}

int main()
{
	scanf("%d%lld", &n, &t);
	for (int i=1; i<=n; i++)
		scanf("%lld%lld", &tab[i], &stan[i]);
	for (int i=1; i<n; i++)
		scanf("%lld", &odl[i]);
	ll s=0;
	for (int i=1; i<n; i++)
	{
		s+=odl[i];
		stan[i+1]=((stan[i+1]+s)%t+t)%t;
	}
	for (int i=n; i; i--)
		stan[i]=(stan[i]-stan[1]+t)%t;
	for (int i=1; i<=n; i++)
		start[i]=(t-stan[i])%t;
	debug() << imie(s);
	debug() << imie(tab[1]);
	//~ ll pocz=0;
	//~ ll dlu=tab[1];
	
	setel.insert({{0LL, t}, n+1});
	for (int i=n; i; i--)
	{
		auto it=setel.lower_bound({{start[i], inf}, 0});
		it--;
		int x=(*it).second;
		if (x<=n)
			dp[i]=dp[x]+czek(start[i], start[x]);
		for (int j=-2; j<=1; j++)
		{
			ll a=start[i]+tab[i]+j*t;
			ll b=start[i]+t+j*t;
			a=max(a, 0LL);
			b=min(b, t);
			if (a>=b)
				continue;
			cut(a);
			cut(b);
			while(1)
			{
				auto jt=setel.lower_bound({{a, -inf}, 0});
				if (jt==setel.end() || (*jt).first.first>=b)
					break;
				setel.erase(jt);
			}
			setel.insert({{a, b}, i});
		}
		debug() << i << " " << imie(setel.size());
	}
	//~ debug() << range(dp+1, dp+1+n);
	wyn=inf;
	setel2.insert({0, tab[1]});
	for (int i=2; i<=n; i++)
	{
		ll opc=0;
		ll mini=inf;
		{
			auto it=setel2.lower_bound({start[i], inf});
			if (it==setel2.end())
				it=setel2.begin();
			it++;
			if (it==setel2.end())
				it=setel2.begin();
			for (int h=0; h<5; h++)
			{
				mini=min(mini, czek((*it).second, start[i])+1);
				if (it==setel2.begin())
					it=setel2.end();
				it--;
			}
		}
		opc+=mini;
		opc+=dp[i];
		wyn=min(wyn, opc);
		
		//~ debug() << imie(i) << setel2;
		
		
		if (start[i]+tab[i]<=t)
		{
			//~ debug() << "a";
			cut2(start[i]);
			cut2(start[i]+tab[i]);
			while(!setel2.empty())
			{
				auto it=setel2.begin();
				if ((*it).first>=start[i])
					break;
				setel2.erase(it);
			}
			while(!setel2.empty())
			{
				auto it=setel2.end();
				it--;
				if ((*it).second<=start[i]+tab[i])
					break;
				setel2.erase(it);
			}
		}
		else
		{
			//~ debug() << "b " << start[i] << " " << tab[i];
			cut2(start[i]);
			cut2(start[i]+tab[i]-t);
			//~ debug() << setel2;
			while(1)
			{
				auto it=setel2.lower_bound({start[i]+tab[i]-t, -inf});
				if (it==setel2.end() || (*it).first>=start[i])
					break;
				setel2.erase(it);
			}
		}
		
		//~ debug() << imie(i) << setel2;
		
		if (setel2.empty())
			break;
	}
	if (!setel2.empty())
		wyn=0;
	printf("%lld\n", wyn+s);
	return 0;
}
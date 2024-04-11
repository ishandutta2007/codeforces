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

int n, q;

int per[nax];

ll ka[nax];
ll kb[nax];

int gdz[nax];

ll fen[nax];

void pisz(int a, int b, ll w)
{
	for (int i=a; i<nax; i+=(i&(-i)))
		fen[i]+=w;
	for (int i=b+1; i<nax; i+=(i&(-i)))
		fen[i]-=w;
}

ll czyt(int v)
{
	ll ret=0;
	for (int i=v; i; i-=(i&(-i)))
		ret+=fen[i];
	return ret;
}

int zap[nax];
set<int> setel;

map<pii,ll> ciek;

vi oco[nax];

int main()
{
	scanf("%d%d", &n, &q);
	for (int i=1; i<=n; i++)
		scanf("%d", &per[i]);
	for (int i=1; i<=n; i++)
		scanf("%lld", &ka[i]);
	for (int i=1; i<=n; i++)
		scanf("%lld", &kb[i]);
	
	gdz[n]=n+1;
	for (int i=n-1; i; i--)
	{
		gdz[i]=i+1;
		while(gdz[i]<=n && per[gdz[i]]<per[i])
			gdz[i]=gdz[gdz[i]];
	}
	//~ debug() << range(gdz+1, gdz+1+n);
	for (int i=1; i<=q; i++)
	{
		scanf("%d", &zap[i]);
	}
	setel.insert(1);
	setel.insert(n+1);
	ciek[{1, n+1}];
	for (int i=1; i<=q; i++)
	{
		if (zap[i]==1)
			continue;
		if (setel.count(zap[i]))
		{
			auto it=setel.find(zap[i]);
			it--;
			int a=(*it);
			it++;
			it++;
			int b=(*it);
			ciek[{a, b}];
			setel.erase(zap[i]);
		}
		else
		{
			setel.insert(zap[i]);
			auto it=setel.find(zap[i]);
			it--;
			ciek[{(*it), zap[i]}];
			it++;
			it++;
			ciek[{zap[i], (*it)}];
		}
	}
	setel.clear();
	//~ debug() << ciek;
	for (auto i : ciek)
	{
		pii p=i.first;
		oco[p.first].push_back(p.second);
	}
	for (int i=n; i; i--)
	{
		//~ if (gdz[i]==i+1)
		//~ {
			//~ pisz(i+1, n+1, min(ka[i], kb[i]));
		//~ }
		//~ else
		//~ {
			
		//~ }
		ll tam=czyt(gdz[i]);
		pisz(i+1, gdz[i]-1, ka[i]);
		pisz(gdz[i], n+1, -tam+min(ka[i]+tam, kb[i]));
		//~ vll wek;
		//~ for (int j=i+1; j<=n+1; j++)
			//~ wek.push_back(czyt(j));
		//~ debug() << i << " " << wek;
		for (int j : oco[i])
			ciek[{i, j}]=czyt(j);
	}
	setel.insert(1);
	setel.insert(n+1);
	ll trz=ciek[{1, n+1}];
	for (int i=1; i<=q; i++)
	{
		if (zap[i]!=1)
		{
			if (setel.count(zap[i]))
			{
				auto it=setel.find(zap[i]);
				it--;
				int a=(*it);
				it++;
				it++;
				int b=(*it);
				setel.erase(zap[i]);
				trz-=ciek[{a, zap[i]}];
				trz-=ciek[{zap[i], b}];
				trz+=ciek[{a, b}];
			}
			else
			{
				setel.insert(zap[i]);
				auto it=setel.find(zap[i]);
				it--;
				int a=(*it);
				it++;
				it++;
				int b=(*it);
				trz+=ciek[{a, zap[i]}];
				trz+=ciek[{zap[i], b}];
				trz-=ciek[{a, b}];
			}
		}
		printf("%lld\n", trz);
	}
	return 0;
}
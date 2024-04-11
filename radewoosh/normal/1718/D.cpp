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
int tab[nax];

int gdz[nax];

vi drz[nax];

int k;
int zbi[nax];
int zap[nax];

vector<pii> musz;
int glonope;

void ans(int v)
{
	if (v)
		printf("YES\n");
	else
		printf("NO\n");
}

int dfs1(int v, int gor)
{
	int dol=0;
	if (tab[v])
	{
		if (tab[v]>gor)
			glonope=1;
		gor=min(gor, tab[v]-1);
	}
	for (int i : drz[v])
		dol=max(dol, dfs1(i, gor));
	
	if (!tab[v])
	{
		musz.push_back({dol, gor});
	}
	else
	{
		dol=max(dol, tab[v]+1);
	}
	return dol;
}

int dajmax()
{
	sort(zbi+1, zbi+k);
	multiset<int> setel;
	sort(musz.begin(), musz.end());
	//~ debug() << musz;
	//~ debug() << range(zbi+1, zbi+k);
	int wsk=0;
	int ret=-1;
	for (int i=1; i<k; i++)
	{
		while(wsk<(int)musz.size() && zbi[i]>=musz[wsk].first)
		{
			setel.insert(musz[wsk].second);
			wsk++;
		}
		while(1)
		{
			if (setel.empty())
				return -1;
			int x=*setel.begin();
			setel.erase(setel.begin());
			if (x<zbi[i])
			{
				if (ret!=-1)
					return -1;
				ret=x;
				continue;
			}
			break;
		}
	}
	while(wsk<(int)musz.size())
	{
		setel.insert(musz[wsk].second);
		wsk++;
	}
	if (!setel.empty())
		ret=(*setel.begin());
	return ret;
}

void test()
{
	scanf("%d%d", &n, &q);
	for (int i=1; i<=n; i++)
		scanf("%d", &per[i]);
	k=0;
	for (int i=1; i<=n; i++)
	{
		scanf("%d", &tab[i]);
		if (!tab[i])
			k++;
	}
	for (int i=1; i<k; i++)
		scanf("%d", &zbi[i]);
	for (int i=1; i<=q; i++)
		scanf("%d", &zap[i]);
	for (int i=1; i<=n; i++)
	{
		drz[i].clear();
		gdz[per[i]]=i;
	}
	set<int> setel;
	per[0]=per[n+1]=n+1;
	setel.insert(0);
	setel.insert(n+1);
	for (int i=n; i; i--)
	{
		int p=gdz[i];
		auto it=setel.lower_bound(p);
		int y=(*it);
		it--;
		int x=(*it);
		if (i!=n)
		{
			if (per[x]<per[y])
				drz[x].push_back(p);
			else
				drz[y].push_back(p);
		}
		setel.insert(p);
	}
	musz.clear();
	glonope=0;
	dfs1(gdz[n], nax);
	//~ for (int i=1; i<=n; i++)
		//~ debug() << i << " " << drz[i];
	//~ debug() << musz;
	//~ debug() << imie(glonope);
	if (glonope)
	{
		for (int i=1; i<=q; i++)
			ans(0);
		return;
	}
	int pra=dajmax();
	//~ debug() << imie(pra);
	for (pii &i : musz)
		i={nax-i.second, nax-i.first};
	for (int i=1; i<k; i++)
		zbi[i]=nax-zbi[i];
	int lew=nax-dajmax();
	for (pii &i : musz)
		i={nax-i.second, nax-i.first};
	for (int i=1; i<k; i++)
		zbi[i]=nax-zbi[i];
	//~ debug() << lew << " " << pra;
	//~ debug();
	for (int i=1; i<=q; i++)
		ans(zap[i]>=lew && zap[i]<=pra);
}

int main()
{
	int t;
	scanf("%d", &t);
	while(t--)
		test();
	return 0;
}
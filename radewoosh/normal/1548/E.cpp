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
    tree<T, null_type, less_equal<T>, rb_tree_tag, tree_order_statistics_node_update>;

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
const int nax=1200*1007;
const int n1=(1<<18);

int n, m, k;

int taba[nax];
int tabb[nax];

int skok[nax];
int naj[nax];

int a[nax];
int b[nax];

pii t1[nax];
pii t2[nax];

ll wyn=0;

ordered_set<int> drz[n1*2];

void wrzuc(int v, pii w)
{
	v+=n1-1;
	while(v)
	{
		drz[v].insert(w.first);
		v>>=1;
	}
}

int czyt(int v, int a, int b, int graa, int dol)
{
	if (drz[v].empty())
		return 0;
	if (a>=graa)
	{
		return ((int)drz[v].size())-(int)drz[v].order_of_key(dol);
	}
	if (b<graa)
	{
		return 0;
	}
	return czyt((v<<1), a, (a+b)>>1, graa, dol)+czyt((v<<1)^1, (a+b+2)>>1, b, graa, dol);
}
	
int main()
{
	scanf("%d%d%d", &n, &m, &k);
	for (int i=1; i<=n; i++)
	{
		scanf("%d", &taba[i]);
		taba[i]=min(taba[i], k+1);
	}
	for (int i=1; i<=m; i++)
	{
		scanf("%d", &tabb[i]);
		tabb[i]=min(tabb[i], k+1);
	}
	{
		for (int i=1; i<=n; i++)
			a[i]=k+2;
		for (int i=1; i<=n; i++)
		{
			skok[i]=i-1;
			naj[i]=taba[i];
			while(taba[skok[i]]>taba[i])
			{
				naj[i]=max(naj[i], naj[skok[i]]);
				skok[i]=skok[skok[i]];
			}
			if (skok[i])
				a[i]=min(a[i], naj[i]);
		}
		//~ debug() << range(skok+1, skok+1+n);
		for (int i=n; i; i--)
		{
			skok[i]=i+1;
			naj[i]=taba[i];
			while(taba[skok[i]]>=taba[i])
			{
				naj[i]=max(naj[i], naj[skok[i]]);
				skok[i]=skok[skok[i]];
			}
			if (skok[i]!=n+1)
				a[i]=min(a[i], naj[i]);
		}
		//~ debug() << range(skok+1, skok+1+n);
	}
	{
		for (int i=1; i<=m; i++)
			b[i]=k+2;
		for (int i=1; i<=m; i++)
		{
			skok[i]=i-1;
			naj[i]=tabb[i];
			while(tabb[skok[i]]>tabb[i])
			{
				naj[i]=max(naj[i], naj[skok[i]]);
				skok[i]=skok[skok[i]];
			}
			if (skok[i])
				b[i]=min(b[i], naj[i]);
		}
		for (int i=m; i; i--)
		{
			skok[i]=i+1;
			naj[i]=tabb[i];
			while(tabb[skok[i]]>=tabb[i])
			{
				naj[i]=max(naj[i], naj[skok[i]]);
				skok[i]=skok[skok[i]];
			}
			if (skok[i]!=m+1)
				b[i]=min(b[i], naj[i]);
		}
	}
	//~ debug() << range(a+1, a+1+n);
	//~ debug() << range(b+1, b+1+m);
	for (int i=1; i<=n; i++)
		t1[i]={taba[i], a[i]};
	for (int i=1; i<=m; i++)
		t2[i]={tabb[i], b[i]};
	sort(t1+1, t1+1+n);
	sort(t2+1, t2+1+m);
	//~ debug() << range(t1+1, t1+1+n);
	//~ debug() << range(t2+1, t2+1+m);
	//~ for (int i=1; i<=n; i++)
	//~ {
		//~ for (int j=1; j<=m; j++)
		//~ {
			//~ if (t1[i].first+t2[j].first<=k && t1[i].first+t2[j].second>=k+1 && t1[i].second+t2[j].first>=k+1)
				//~ wyn++;
		//~ }
	//~ }
	int wsk=1;
	for (int i=n; i; i--)
	{
		while(wsk<=m && t1[i].first+t2[wsk].first<=k)
		{
			wrzuc(t2[wsk].first, {t2[wsk].second, wsk});
			wsk++;
		}
		//~ debug() << i << " " << wsk;
		wyn+=czyt(1, 1, n1, k+1-t1[i].second, k+1-t1[i].first);
	}
	printf("%lld\n", wyn);
	return 0;
}
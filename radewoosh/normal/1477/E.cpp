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

int n, m, q;

ll ta[nax];
ll tb[nax];

ll drz[4][nax];

int ile_a[nax];

ordered_set<int> ist;
set<pii> setel;

ll k;

void pisz(int g, int v, ll w)
{
	for (int i=v; i<nax; i+=(i&(-i)))
		drz[g][i]+=w;
}

ll czyt(int g, int a, int b)
{
	if (a>b || b<1 || a>=nax)
		return 0;
	b=min(b, nax-1);
	a=max(a, 1);
	ll ret=0;
	for (int i=b; i; i-=(i&(-i)))
		ret+=drz[g][i];
	for (int i=a-1; i; i-=(i&(-i)))
		ret-=drz[g][i];
	return ret;
}

void doloz_a(int war, int mno)
{
	pisz(0, war, mno);
	pisz(1, war, mno*war);
	if (mno==1)
	{
		ile_a[war]++;
		ist.insert(war);
	}
	else
	{
		ile_a[war]--;
		if (!ile_a[war])
			ist.erase(war);
	}
}

int czas;

void doloz_b(int war, int mno)
{
	//~ debug() << "dokladam_b " << war << " " << mno;
	pisz(2, war, mno);
	pisz(3, war, mno*war);
	czas++;
	if (mno==1)
		setel.insert({war, czas});
	else
		setel.erase(setel.lower_bound({war, -1}));
}

ll pierwszy()
{
	return (*setel.begin()).first;
}

ll ostatni()
{
	auto it=setel.end();
	it--;
	return (*it).first;
}

ll symuluj(vector<pii> wek)
{
	ll ret=0;
	//~ ll ter=0;
	ll pier;
	if (!wek.empty())
	{
		pier=wek[0].first-k;
	}
	else
	{
		pier=ostatni()-k;
	}
	for (pii i : wek)
	{
		//~ ter=max(0LL, ter+i.first-pier);
		pier=min(pier, (ll)i.first);
		//~ if (ter<0)
		//~ {
			//~ pier+=ter;
			//~ ter=0;
		//~ }
		if (i.second==1)
			ret+=i.first-pier;
		else
			ret-=i.first-pier;
	}
	//~ debug() << imie(pier) << imie(pierwszy()) << imie(ostatni());
	if (!setel.empty())
	{
		ret-=czyt(3, pier, nax-1)-czyt(2, pier, nax-1)*pier;
		//~ debug() << imie(czyt(3, pier, nax-1)) << imie(czyt(2, pier, nax-1));
		pier=min(pierwszy(), pier);
	}
	if (!ist.empty())
	{
		if (*(ist.begin())<pier)
			pier=(*ist.begin());
		//~ debug() << imie(pier);
		ret+=czyt(1, 1, nax-1)-czyt(0, 1, nax-1)*pier;
		//~ debug() << imie(czyt(1, pier, nax-1)) << imie(czyt(0, pier, nax-1));
	}
	return ret;
}

ll policz(int kt)
{
	ll x=*ist.find_by_order(kt-1);
	doloz_a(x, -1);
	ll ret=symuluj({{x, 1}});
	doloz_a(x, 1);
	return ret;
}

void query()
{
	scanf("%lld", &k);
	ll wyn=symuluj({});
	{
		ll x=pierwszy();
		doloz_b(x, -1);
		wyn=max(wyn, symuluj({{x, 2}}));
		doloz_b(x, 1);
	}
	{
		ll x=*ist.begin();
		doloz_a(x, -1);
		wyn=max(wyn, symuluj({{x, 1}}));
		doloz_a(x, 1);
	}
	{
		auto it=ist.end();
		it--;
		ll x=*(it);
		doloz_a(x, -1);
		wyn=max(wyn, symuluj({{x, 1}}));
		doloz_a(x, 1);
	}
	{
		auto it=ist.lower_bound(ostatni()+k);
		if (it!=ist.end())
		{
			ll x=*(it);
			doloz_a(x, -1);
			wyn=max(wyn, symuluj({{x, 1}}));
			doloz_a(x, 1);
		}
	}
	{
		auto it=ist.lower_bound(ostatni()+k);
		if (it!=ist.begin())
		{
			it--;
			ll x=*(it);
			doloz_a(x, -1);
			wyn=max(wyn, symuluj({{x, 1}}));
			doloz_a(x, 1);
		}
	}
	//~ ll kon=ostatni();
	//~ int mni=ist.order_of_key(kon+1)+1;
	//~ int jest=ist.size();
	
	//~ int bsa=mni;
	//~ int bsb=jest;
	//~ if (bsa<=bsb)
	//~ {
		//~ while(bsa<bsb)
		//~ {
			//~ int bs1=(bsa+bsb)>>1;
			//~ int bs2=bs1+1;
			//~ if (policz(bs1)>=policz(bs2))
				//~ bsb=bs1;
			//~ else
				//~ bsa=bs2;
		//~ }
		//~ wyn=max(wyn, policz(bsa));
	//~ }
	
	printf("%lld\n", wyn);
}

int main()
{
	scanf("%d%d%d", &n, &m, &q);
	for (int i=1; i<=n; i++)
	{
		scanf("%lld", &ta[i]);
		ta[i]++;
		doloz_a(ta[i], 1);
	}
	for (int i=1; i<=m; i++)
	{
		scanf("%lld", &tb[i]);
		tb[i]++;
		doloz_b(tb[i], 1);
	}
	while(q--)
	{
		int typ;
		scanf("%d", &typ);
		if (typ==1)
		{
			int a, b;
			scanf("%d%d", &a, &b);
			b++;
			doloz_a(ta[a], -1);
			ta[a]=b;
			doloz_a(ta[a], 1);
			continue;
		}
		if (typ==2)
		{
			int a, b;
			scanf("%d%d", &a, &b);
			b++;
			doloz_b(tb[a], -1);
			tb[a]=b;
			doloz_b(tb[a], 1);
			continue;
		}
		query();
	}
	return 0;
}
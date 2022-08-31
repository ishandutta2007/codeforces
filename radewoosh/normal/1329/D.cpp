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
const int alfa=26;

int n;
char wcz[nax];
int tab[nax];

set<int> powt;

vector<pii> pary[alfa][alfa];
int jego[alfa];

ordered_set<int> wsz;

vector<pii> oper;

void usuniecie(pii v)
{
	int sta=wsz.order_of_key(v.first);
	vi wek;
	auto it=wsz.find(v.first);
	while((*it)<v.second)
	{
		wek.push_back((*it));
		it++;
	}
	oper.push_back({sta, sta+(int)wek.size()-1});
	for (int i : wek)
		wsz.erase(i);
	powt.erase(wek[0]);
	powt.erase(wek.back()+1);
	auto kt=powt.lower_bound(wek.back());
	auto jt=kt;
	jt--;
	int x=(*jt);
	int y=(*kt);
	if (x>=1 && y<=n && tab[x]!=tab[y])
	{
		pary[tab[x]][tab[y]].push_back({x, y});
		pary[tab[y]][tab[x]].push_back({x, y});
	}
}

void test()
{
	oper.clear();
	scanf("%s", wcz+1);
	n=strlen(wcz+1);
	for (int i=1; i<=n; i++)
		tab[i]=wcz[i]-'a';
	wsz.clear();
	powt.clear();
	for (int i=0; i<alfa; i++)
	{
		jego[i]=0;
		for (int j=0; j<alfa; j++)
			pary[i][j].clear();
	}
	for (int i=0; i<=n+1; i++)
		wsz.insert(i);
	for (int i=2; i<=n; i++)
	{
		if (tab[i]==tab[i-1])
		{
			powt.insert(i);
			jego[tab[i]]++;
		}
	}
	powt.insert(0);
	powt.insert(n+2);
	for (int i : powt)
	{
		if (i>=1 && i<=n)
		{
			auto it=powt.find(i);
			it--;
			if (*it)
			{
				int j=*it;
				if (tab[i]!=tab[j])
				{
					pary[tab[j]][tab[i]].push_back({j, i});
					pary[tab[i]][tab[j]].push_back({j, i});
				}
			}
		}
	}
	while(1)
	{
		int naj=0;
		int suma=0;
		int g=-1;
		for (int i=0; i<alfa; i++)
		{
			suma+=jego[i];
			if (jego[i]>=naj)
			{
				naj=jego[i];
				g=i;
			}
		}
		if (!suma || naj==suma)
			break;
		//~ debug() << range(jego, jego+alfa);
		pii v;
		int mam=0;
		for (int i=0; i<alfa && !mam; i++)
		{
			if (i==g)
				continue;
			while(!mam && !pary[g][i].empty())
			{
				v=pary[g][i].back();
				//~ debug() << i << " cons " << v;
				if (!powt.count(v.first) || !powt.count(v.second))
				{
					pary[g][i].pop_back();
					continue;
				}
				mam=1;
			}
		}
		assert(mam);
		usuniecie(v);
		jego[tab[v.first]]--;
		jego[tab[v.second]]--;
	}
	vi wek;
	for (int i : powt)
		if (i>=1 && i<=n)
			wek.push_back(i);
	for (int i : wek)
		usuniecie({i, i+1});
	usuniecie({1, n+1});
	printf("%d\n", (int)oper.size());
	for (pii i : oper)
		printf("%d %d\n", i.first, i.second);
}

int main()
{
	int t;
	scanf("%d", &t);
	while(t--)
		test();
	return 0;
}
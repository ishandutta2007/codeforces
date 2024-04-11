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
const int nax=1007;
using mag=__int128;

int n, m;

mag ta[nax];
mag tb[nax];

char wcz[nax];

vector<pair<mag,int>> ra[nax];
vector<pair<mag,int>> rb[nax];

int jesta[nax];
int jestb[nax];

set<mag> wek;

void ans(int v)
{
	if (v)
		printf("YES\n");
	else
		printf("NO\n");
}

mag czyt()
{
	scanf("%s", wcz+1);
	mag ret=0;
	for (int i=1; wcz[i]; i++)
		ret=ret*10+(wcz[i]-'0');
	return ret;
}

vector<pair<mag,int>> rozloz(mag v)
{
	vector<pair<mag,int>> ret;
	for (mag i : wek)
	{
		if (!(v%i))
		{
			ret.push_back({i, 0});
			while(!(v%i))
			{
				v/=i;
				ret.back().second++;
			}
		}
	}
	return ret;
}

map<mag,set<pii>> sa, sb;
queue<mag> intere;

void usuna(int v)
{
	jesta[v]=0;
	for (auto j : ra[v])
	{
		sa[j.first].erase({-j.second, v});
		intere.push(j.first);
	}
}

void usunb(int v)
{
	jestb[v]=0;
	for (auto j : rb[v])
	{
		sb[j.first].erase({-j.second, v});
		intere.push(j.first);
	}
}

void wypisz(mag v)
{
	vi wek;
	while(wek.empty() || v)
	{
		wek.push_back(v%10);
		v/=10;
	}
	reverse(wek.begin(), wek.end());
	for (int i : wek)
		printf("%d", i);
	printf(" ");
}

void test()
{
	scanf("%d%d", &n, &m);
	for (int i=1; i<=n; i++)
		ta[i]=czyt();
	for (int i=1; i<=m; i++)
		tb[i]=czyt();
	set<mag> kol;
	for (int i=1; i<=n; i++)
		if (ta[i]>1)
			kol.insert(ta[i]);
	for (int i=1; i<=m; i++)
		if (tb[i]>1)
			kol.insert(tb[i]);
	wek.clear();
	while(!kol.empty())
	{
		mag v=*kol.begin();
		kol.erase(v);
		int mam=0;
		for (mag i : wek)
		{
			mag g=__gcd(i, v);
			if (g==1)
				continue;
			mam=1;
			if (v!=g)
				kol.insert(v/g);
			if (i!=g)
				kol.insert(i/g);
			kol.insert(g);
			wek.erase(i);
			break;
		}
		if (!mam)
			wek.insert(v);
	}
	//~ for (mag i : wek)
		//~ debug() << ((ll)i);
	//~ debug();
	for (int i=1; i<=n; i++)
		ra[i]=rozloz(ta[i]);
	for (int i=1; i<=m; i++)
		rb[i]=rozloz(tb[i]);
	//~ debug() << rb[m];
	sa.clear();
	sb.clear();
	for (mag i : wek)
	{
		sa[i].insert({0, 0});
		sb[i].insert({0, 0});
	}
	for (int i=1; i<=n; i++)
	{
		jesta[i]=1;
		for (auto j : ra[i])
			sa[j.first].insert({-j.second, i});
	}
	for (int i=1; i<=m; i++)
	{
		jestb[i]=1;
		for (auto j : rb[i])
			sb[j.first].insert({-j.second, i});
	}
	for (mag i : wek)
		intere.push(i);
	while(!intere.empty())
	{
		mag v=intere.front();
		intere.pop();
		if ((*sa[v].begin()).first==(*sb[v].begin()).first)
			continue;
		if ((*sa[v].begin()).first<(*sb[v].begin()).first)
			usuna((*sa[v].begin()).second);
		else
			usunb((*sb[v].begin()).second);
	}
	int da=0;
	int db=0;
	for (int i=1; i<=n; i++)
		da+=jesta[i];
	for (int i=1; i<=m; i++)
		db+=jestb[i];
	if (!da || !db)
	{
		ans(0);
		return;
	}
	ans(1);
	printf("%d %d\n", da, db);
	for (int i=1; i<=n; i++)
		if (jesta[i])
			wypisz(ta[i]);
	printf("\n");
	for (int i=1; i<=m; i++)
		if (jestb[i])
			wypisz(tb[i]);
	printf("\n");
}

int main()
{
	int t;
	scanf("%d", &t);
	while(t--)
		test();
	return 0;
}
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
const int nax=1007*1007;
const int n1=(1<<18);

int n, m, q;

pii pole[nax];
int blok[nax];

int wyn[nax];

void zabron(int a, int b)
{
	wyn[a]++;
	wyn[b+1]--;
}

int gr(int v)
{
	return (v+1)>>1;
}

multiset<int> gor;
multiset<int> dol;

void usun(multiset<int> &setel, int v)
{
	setel.erase(setel.find(v));
}

void wstaw(multiset<int> &setel, int v)
{
	setel.insert(v);
}

int pier(multiset<int> &setel)
{
	if (setel.empty())
		return nax;
	return (*setel.begin());
}

int ost(multiset<int> &setel)
{
	if (setel.empty())
		return -nax;
	auto it=setel.end();
	it--;
	return *it;
}

void rek(int a, int b, vi que)
{
	if (que.empty() || a>b)
		return;
	int s=(a+b)>>1;
	gor.clear();
	dol.clear();
	for (int i=0; i<(int)que.size(); i++)
	{
		pii prze;
		prze.first=que[i];
		if (i+1==(int)que.size())
			prze.second=q;
		else
			prze.second=que[i+1]-1;
		int v=que[i];
		if (blok[v])
		{
			if ((pole[v].first&1) && gr(pole[v].first)<=s)
				wstaw(dol, gr(pole[v].second));
			if (!(pole[v].first&1) && gr(pole[v].first)>=s)
				wstaw(gor, gr(pole[v].second));
		}
		else
		{
			if ((pole[v].first&1) && gr(pole[v].first)<=s)
				usun(dol, gr(pole[v].second));
			if (!(pole[v].first&1) && gr(pole[v].first)>=s)
				usun(gor, gr(pole[v].second));
		}
		if (pier(dol)<=ost(gor))
			zabron(prze.first, prze.second);
	}
	vi nadol;
	vi nagore;
	for (int i : que)
	{
		if (gr(pole[i].first)<s)
			nadol.push_back(i);
		if (gr(pole[i].first)>s)
			nagore.push_back(i);
	}
	rek(a, s-1, nadol);
	rek(s+1, b, nagore);
}

int main()
{
	scanf("%d%d%d", &n, &m, &q);
	set<pii> setel;
	for (int i=1; i<=q; i++)
	{
		scanf("%d%d", &pole[i].first, &pole[i].second);
		if (!setel.count(pole[i]))
		{
			blok[i]=1;
			setel.insert(pole[i]);
		}
		else
		{
			setel.erase(pole[i]);
		}
	}
	vi que(q);
	iota(que.begin(), que.end(), 1);
	rek(1, n, que);
	
	for (int i=1; i<=q; i++)
	{
		wyn[i]+=wyn[i-1];
		if (!wyn[i])
			printf("YES\n");
		else
			printf("NO\n");
	}
	return 0;
}
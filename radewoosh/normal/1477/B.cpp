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

char wcz[nax];

int sta[nax];
int kon[nax];

pii prz[nax];

void ans(int v)
{
	if (v)
		printf("YES\n");
	else
		printf("NO\n");
}

set<pii> setel;

void cut_przed(int v)
{
	auto it=setel.lower_bound({v, nax});
	it--;
	if ((*it).first<v && (*it).second>=v)
	{
		pii x=(*it);
		setel.erase(it);
		setel.insert({x.first, v-1});
		setel.insert({v, x.second});
	}
}

int jest[nax];

void test()
{
	scanf("%d%d", &n, &q);
	scanf("%s", wcz+1);
	for (int i=1; i<=n; i++)
		sta[i]=wcz[i]-'0';
	scanf("%s", wcz+1);
	for (int i=1; i<=n; i++)
		kon[i]=wcz[i]-'0';
	for (int i=1; i<=q; i++)
		scanf("%d%d", &prz[i].first, &prz[i].second);
	setel.clear();
	setel.insert({0, 0});
	setel.insert({n+1, n+1});
	for (int i=1; i<=n; i++)
		if (kon[i])
			setel.insert({i, i});
	for (int i=q; i; i--)
	{
		int a=prz[i].first;
		int b=prz[i].second;
		cut_przed(a);
		cut_przed(b+1);
		int licz=0;
		auto it=setel.lower_bound({a, 0});
		vector<pii> pam;
		while((*it).first<=b)
		{
			pam.push_back(*it);
			licz+=(*it).second-(*it).first+1;
			it++;
		}
		if (licz*2==(b-a+1))
		{
			ans(0);
			return;
		}
		for (pii j : pam)
			setel.erase(j);
		if (licz*2>(b-a+1))
			setel.insert({a, b});
	}
	
	for (int i=1; i<=n; i++)
		jest[i]=0;
	for (pii i : setel)
		for (int j=i.first; j<=i.second; j++)
			jest[j]=1;
	for (int i=1; i<=n; i++)
	{
		if (jest[i]!=sta[i])
		{
			ans(0);
			return;
		}
	}
	ans(1);
}

int main()
{
	int t;
	scanf("%d", &t);
	while(t--)
		test();
	return 0;
}
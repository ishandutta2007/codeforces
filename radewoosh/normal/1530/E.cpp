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

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

int n;
char wcz[nax];
char wczsor[nax];

map<char,int> mapa;

void test()
{
	scanf("%s", wcz+1);
	n=strlen(wcz+1);
	for (int i=1; i<=n; i++)
		wczsor[i]=wcz[i];
	sort(wczsor+1, wczsor+1+n);
	if (wczsor[1]==wczsor[n])
	{
		for (int i=1; i<=n; i++)
			printf("%c", wcz[i]);
		printf("\n");
		return;
	}
	mapa.clear();
	for (int i=1; i<=n; i++)
		mapa[wcz[i]]++;
	vector<pair<char,int>>wek;
	for (auto i : mapa)
		wek.push_back(i);
	for (int j=0; j<(int)wek.size(); j++)
	{
		if (wek[j].second==1)
		{
			printf("%c", wek[j].first);
			for (auto i : wek)
			{
				if (i.first==wek[j].first)
					continue;
				for (int l=0; l<i.second; l++)
					printf("%c", i.first);
			}
			printf("\n");
			return;
		}
	}
	int male=wek[0].second-1;
	int sred=wek[1].second;
	char m=wek[0].first;
	char s=wek[1].first;
	vector<char> wyn{m};
	vector<char> reszta;
	for (int i=2; i<(int)wek.size(); i++)
		for (int j=0; j<wek[i].second; j++)
			reszta.push_back(wek[i].first);
	reverse(reszta.begin(), reszta.end());
	if (male-1<=sred+(int)reszta.size())
	{
		wyn.push_back(m);
		male--;
		while(male || sred || !reszta.empty())
		{
			//~ debug() << wyn << " " << male << " " << sred << " " << reszta;
			if (male && wyn.back()!=m)
			{
				male--;
				wyn.push_back(m);
				continue;
			}
			if (sred)
			{
				sred--;
				wyn.push_back(s);
				continue;
			}
			wyn.push_back(reszta.back());
			reszta.pop_back();
		}
	}
	else
	{
		wyn.push_back(s);
		sred--;
		while(male || sred || !reszta.empty())
		{
			if (!reszta.empty())
			{
				if (male)
				{
					male--;
					wyn.push_back(m);
					continue;
				}
				if (sred && wyn.back()!=m)
				{
					sred--;
					wyn.push_back(s);
					continue;
				}
				wyn.push_back(reszta.back());
				reszta.pop_back();
				continue;
			}
			if (!male || !sred)
			{
				if (male)
				{
					male--;
					wyn.push_back(m);
				}
				else
				{
					sred--;
					wyn.push_back(s);
				}
				continue;
			}
			if (wyn.back()==m)
				assert(0);
			sred--;
			wyn.push_back(s);
		}
	}
	
	for (char i : wyn)
		printf("%c", i);
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
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
const int d=200;

void ff()
{
	fflush(stdout);
}

int pyt(vector<pii> wek)
{
	printf("? %d\n", (int)wek.size());
	for (pii i : wek)
		printf("%d %d ", i.first, i.second);
	printf("\n");
	ff();
	int x;
	scanf("%d", &x);
	return x;
}

int podl(int li, int mi)
{
	return li/mi;
}

int sufi(int li, int mi)
{
	return (li+mi-1)/mi;
}

vi mozliwe(pii pro, pii czes)
{
	vi ret;
	for (int i=podl(pro.first, czes.first); i<=sufi(pro.first, czes.first); i++)
		for (int j=podl(pro.second, czes.second); j<=sufi(pro.second, czes.second); j++)
			ret.push_back(i*j);
	sort(ret.begin(), ret.end());
	ret.resize(unique(ret.begin(), ret.end())-ret.begin());
	return ret;
}

int moze(pii pro, pii czes, int x)
{
	vi wez=mozliwe(pro, czes);
	for (int i : wez)
		if (i==x)
			return 1;
	return 0;
}

int main()
{
	//~ map<int,vector<pii>> mapa;
	//~ for (int i=1; i<=200; i++)
		//~ for (int j=1; j<=i; j++)
			//~ mapa[i*j].push_back({i, j});
	//~ int naj=0;
	//~ for (auto i : mapa)
		//~ naj=max(naj, (int)i.second.size());
	//~ debug() << naj;
	//~ for (auto i : mapa)
		//~ if (i.second.size()==naj)
			//~ debug() << i;
	vector<pii> wsz;
	for (int i=1; i<=d; i++)
		for (int j=1; j<=d; j++)
			wsz.push_back({i, j});
	int pole=pyt(wsz);
	vector<pii> moz;
	for (int i=1; i<=d; i++)
		for (int j=1; j<=d; j++)
			if (i*j==pole)
				moz.push_back({i, j});
	debug() << imie(moz);
	for (int h=1; h<=3; h++)
	{
		pair<int,pii> jak{d, {0, 0}};
		for (int i=1; i<=d; i++)
		{
			for (int j=1; j<=d; j++)
			{
				map<int,int> mapa;
				for (pii l : moz)
					for (int w : mozliwe(l, {i, j}))
						mapa[w]++;
				int naj=0;
				for (auto l : mapa)
					naj=max(naj, l.second);
				jak=min(jak, {naj, {i, j}});
			}
		}
		int a=jak.second.first;
		int b=jak.second.second;
		//~ {
			//~ map<int,int> mapa;
			//~ for (pii l : moz)
				//~ for (int w : mozliwe(l, {a, b}))
					//~ mapa[w]++;
			//~ debug() << mapa;
		//~ }
		//~ debug() << a << " " << b;
		vector<pii> zap;
		for (int i=a; i<=d; i+=a)
			for (int j=b; j<=d; j+=b)
				zap.push_back({i, j});
		vector<pii> nowe;
		int odp=pyt(zap);
		for (pii i : moz)
			if (moze(i, {a, b}, odp))
				nowe.push_back(i);
		moz=nowe;
		//~ debug() << imie(moz);
	}
	printf("! %d\n", 2*(moz[0].first+moz[0].second-2));
	ff();
	return 0;
}
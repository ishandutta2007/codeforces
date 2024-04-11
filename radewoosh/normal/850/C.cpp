//PRZEMYSL ASSERTY

//SPRAWDZ CORNER CASE'Y, MINIMALNE I MAKSYMALNE WEJCIE I WYJCIE

//MODULO = 1

//while (clock()<=69*CLOCKS_PER_SEC)

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

const int nax=1007;

int n;
map <int, set <int> > mapa;

int xo;

inline void roz(int v)
{
	if (v==1)
		return;
	vector < pair <int,int> > ret;
	vector <int> nor;
	for (int i=2; i*i<=v; i++)
	{
		if (!(v%i))
		{
			v/=i;
			nor.push_back(i);
			i--;
		}
	}
	nor.push_back(v);
	for (int i : nor)
	{
		if (ret.empty() || ret.back().second!=i)
			ret.push_back({0, i});
		ret.back().first++;
	}
	for (auto i : ret)
		mapa[i.second].insert(i.first);
}

map < int , int > wyny;

int licz(int v)
{
	//debug() << imie(v);
	if (!v)
		return 0;
	if (wyny.count(v))
		return wyny[v];
	vector <int> ile;
	for (int i=0; i<=35; i++)
		ile.push_back(0);
	vector <int> wek;
	int vv=v;
	while(vv)
	{
		wek.push_back(vv&1);
		vv>>=1;
	}
	int k=wek.size()-1;
	for (int i=1; i<=k; i++)
	{
		int maska=0;
		for (int j=1; j<=k; j++)
		{
			if (j==i || !wek[j])
				continue;
			if (j<i)
				maska|=(1<<j);
			else
				maska|=(1<<(j-i));
		}
		ile[licz(maska)]=1;
	}
	for (int i=0; 1; i++)
	{
		if (!ile[i])
		{
			wyny[v]=i;
			return i;
		}
	}
}

int main()
{
	scanf("%d", &n);
	for (int i=1; i<=n; i++)
	{
		int x;
		scanf("%d", &x);
		roz(x);
	}
	for (auto i : mapa)
	{
		int mas=0;
		for (int j : i.second)
			mas|=(1<<j);
		xo^=licz(mas);
	}
	if (xo)
		printf("Mojtaba\n");
	else
		printf("Arpa\n");
	return 0;
}
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

void nope()
{
	printf("NO\n");
	exit(0);
}

int n;

int tab[nax];

vi graf[nax];

int fen[nax];

ll inv;

int czas;
int pre[nax];
int kto[nax];
int mini[nax];

int ojc[nax];
int gle[nax];

void pisz(int v, int w)
{
	for (int i=v; i; i-=(i&(-i)))
		fen[i]+=w;
}

int czyt(int v)
{
	int ret=0;
	for (int i=v; i<=n; i+=(i&(-i)))
		ret+=fen[i];
	return ret;
}

void dfs1(int v)
{
	inv+=czyt(tab[v]);
	pisz(tab[1], 1);
	mini[v]=tab[v];
	for (int i : graf[v])
	{
		ojc[i]=v;
		gle[i]=gle[v]+1;
		dfs1(i);
		mini[v]=min(mini[v], mini[i]);
	}
	pisz(tab[1], -1);
}

bool mniej(int a, int b)
{
	return mini[a]<mini[b];
}

void dfs2(int v)
{
	czas++;
	pre[v]=czas;
	kto[czas]=v;
	sort(graf[v].begin(), graf[v].end(), mniej);
	for (int i : graf[v])
		dfs2(i);
}

int ma[nax];
int wsk[nax];
int blok[nax];

deque<int> kol;

void symuluj()
{
	for (int i=1; i<=n; i++)
		ma[i]=pre[i];
	kol.push_back(1);
	int gdz=1;
	ll kroki=inv;
	while(kroki)
	{
		//~ debug() << kol << " " << gdz << " " << kroki;
		if (kroki<(int)kol.size()-1)
		{
			ma[gdz]=kol.back();
			kol.pop_back();
			gdz=ojc[gdz];
			continue;
		}
		if (kroki==(int)kol.size()-1)
		{
			int x=kol.front();
			kol.pop_front();
			kol.push_back(x);
			int ost=gdz;
			while(ost)
			{
				ma[ost]=kol.back();
				kol.pop_back();
				ost=ojc[ost];
			}
			break;
		}
		if (wsk[gdz]<(int)graf[gdz].size())
		{
			int x=graf[gdz][wsk[gdz]];
			gdz=x;
			kol.push_back(ma[gdz]);
		}
		else
		{
			int x=kol.front();
			kol.pop_front();
			ma[gdz]=x;
			gdz=ojc[gdz];
			wsk[gdz]++;
			kroki-=kol.size();
		}
	}
	debug() << range(ma+1, ma+1+n);
	for (int i=1; i<=n; i++)
		if (tab[i]!=ma[i])
			nope();
}

int main()
{
	scanf("%d", &n);
	for (int i=1; i<=n; i++)
	{
		scanf("%d", &tab[i]);
	}
	for (int i=1; i<n; i++)
	{
		int a, b;
		scanf("%d%d", &a, &b);
		graf[a].push_back(b);
	}
	gle[1]=1;
	dfs1(1);
	dfs2(1);
	symuluj();
	//~ debug() << imie(inv);
	//~ debug() << range(pre+1, pre+1+n);
	
	printf("YES\n");
	printf("%lld\n", inv);
	for (int i=1; i<=n; i++)
		printf("%d ", pre[i]);
	printf("\n");
	return 0;
}
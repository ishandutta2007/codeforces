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
const int d=20;

void ff()
{
	fflush(stdout);
}

int c, n;
int moge;

int zle[nax];

int jego[nax];

int sito[nax];
int baza[nax];

vi wek[nax];

int biore[nax];

vector<vi> zmiany;

int mac[nax];
vi jak[nax];

vi xoruj(const vi a, const vi b)
{
	vi ret;
	int wa=0;
	int wb=0;
	while(wa<(int)a.size() && wb<(int)b.size())
	{
		if (a[wa]==b[wb])
		{
			wa++;
			wb++;
		}
		else
		{
			if (a[wa]<b[wb])
			{
				ret.push_back(a[wa]);
				wa++;
			}
			else
			{
				ret.push_back(b[wb]);
				wb++;
			}
		}
	}
	while(wa<(int)a.size())
	{
		ret.push_back(a[wa]);
		wa++;
	}
	while(wb<(int)b.size())
	{
		ret.push_back(b[wb]);
		wb++;
	}
	return ret;
}

void solve(int v)
{
	shandom_ruffle(wek[v].begin(), wek[v].end());
	//~ debug() << v << " chce " << jego[v];
	for (int i=0; i<d; i++)
	{
		mac[i]=0;
		jak[i].clear();
	}
	for (int i : wek[v])
	{
		vi ter{i};
		int umiem=i;
		for (int j=d-1; j>=0; j--)
		{
			if (mac[j] && (umiem&(1<<j)))
			{
				umiem^=mac[j];
				ter=xoruj(ter, jak[j]);
			}
		}
		if (!umiem)
		{
			zmiany.push_back(ter);
			continue;
		}
		int x=31-__builtin_clz(umiem);
		jak[x]=ter;
		mac[x]=umiem;
		for (int j=0; j<d; j++)
		{
			if (j!=x && (mac[j]&(1<<x)))
			{
				mac[j]^=mac[x];
				jak[j]=xoruj(jak[j], jak[x]);
			}
		}
	}
	int umiem=jego[v];
	vi ter;
	for (int i=d-1; i>=0; i--)
	{
		if (umiem&(1<<i))
		{
			umiem^=mac[i];
			ter=xoruj(ter, jak[i]);
		}
	}
	//~ if (umiem)
	//~ {
		//~ debug() << "kurwa " << v << " " << wek[v];
	//~ }
	assert(!umiem);
	for (int i : ter)
		biore[i]=1;
}

int main()
{
	scanf("%d%d", &c, &n);
	moge=(c*65+99)/100;
	for (int i=1; i<=c; i++)
		baza[i]=i;
	for (int i=2; i<=c; i++)
		if (!sito[i])
			for (int j=i; j<=c; j+=i)
				sito[j]=i;
	for (int i=2; i*i<=c; i++)
	{
		for (int j=i*i; j<=c; j+=i*i)
		{
			zle[j]=1;
			while(!(baza[j]%(i*i)))
				baza[j]/=i;
		}
	}
	//~ debug() << range(baza+1, baza+1+c);
	for (int i=1; i<=c; i++)
		wek[baza[i]].push_back(i);
	//~ map<int,int> mapa;
	//~ for (int i=1; i<=c; i++)
	//~ {
		//~ if (!zle[i])
		//~ {
			//~ mapa[wek[i].size()]++;
			//~ if ((int)wek[i].size()==260)
				//~ debug() << i << " " << wek[i];
		//~ }
	//~ }
	//~ for (auto i : mapa)
		//~ debug() << i;
	//~ return 0;
	int dobr=0;
	for (int i=1; i<=c; i++)
		if (!zle[i])
			dobr++;
	assert(dobr<=moge);
	printf("%d", dobr);
	for (int i=1; i<=c; i++)
		if (!zle[i])
			printf(" %d", i);
	printf("\n");
	ff();
	for (int i=1; i<=c; i++)
		if (!zle[i])
			scanf("%d", &jego[i]);
	//~ for (int i=1; i<=c; i++)
	//~ {
		//~ if (zle[i])
			//~ continue;
		//~ for (int j=2*i; j<=c; j+=i)
			//~ jego[i]^=jego[j];
	//~ }
	//~ for (int i=2; i<=c; i++)
		//~ if (!zle[i])
			//~ jego[i]^=jego[1];
	for (int i=c; i; i--)
		if (!zle[i])
			for (int j=2*i; j<=c; j+=i)
				if (!zle[j])
					jego[j]^=jego[i];
	//~ for (int i=1; i<=c; i++)
		//~ if (!zle[i])
			//~ debug() << i << " " << jego[i];
	for (int i=1; i<=c; i++)
		if (!zle[i])
			for (int j=2*i; j<=c; j+=i)
				if (!zle[j])
					jego[i]^=jego[j];
	//~ for (int i=1; i<=c; i++)
		//~ if (!zle[i])
			//~ debug() << i << " " << jego[i];
	
	for (int i=1; i<=c; i++)
		if (!zle[i])
			solve(i);
	int ile=0;
	for (int i=1; i<=c; i++)
		if (biore[i])
			ile++;
	while(ile!=n)
	{
		int x=rand()%zmiany.size();
		vi &opc=zmiany[x];
		int bedzie=ile;
		for (int i : opc)
		{
			if (biore[i])
				bedzie--;
			else
				bedzie++;
		}
		if (abs(n-bedzie)<=abs(n-ile) || !(rand()%(3*zmiany.size())))
		{
			ile=bedzie;
			for (int i : opc)
				biore[i]^=1;
		}
	}
	
	
	
	for (int i=1; i<=c; i++)
		if (biore[i])
			printf("%d ", i);
	printf("\n");
	ff();
	return 0;
}
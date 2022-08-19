//~ while (clock()<=69*CLOCKS_PER_SEC)
//~ #pragma comment(linker, "/stack:200000000")
#pragma GCC optimize("O3")
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
const int nax=400*1007;
const int d=26;
const ll h=100*1000+3;
const ll mod1=1000*1000*1000+7;
const ll mod2=1000*1000*1000+9;

int n, q;

char wcz[nax];
int tab[nax];

ll pot1[nax];
ll hasz1[nax];
ll pot2[nax];
ll hasz2[nax];

int lit[nax][d];

int sito[nax];
vi dz[nax];

int ile_lit(int a, int b, int kt)
{
	return lit[b][kt]-lit[a-1][kt];
}

inline ll daj_hasz(const int &a, const int &b)
{
	ll ret1=hasz1[b]-hasz1[a-1]*pot1[b-a+1];
	ret1%=mod1;
	if (ret1<0)
		ret1+=mod1;
	ll ret2=hasz2[b]-hasz2[a-1]*pot2[b-a+1];
	ret2%=mod2;
	if (ret2<0)
		ret2+=mod2;
	return ret1*mod2+ret2;
}

unordered_map <ll,vi> mapa[nax];
int pocz[nax];
int kon[nax];

const int magia=50;

void pre_pro()
{
	for (int i=1; i<=n; i<<=1)
		for (int j=1; j+i-1<=n; j++)
			mapa[i][daj_hasz(j, j+i-1)].push_back(j);
	for (int i=1; i<=n; i++)//pocz
	{
		for (int j=1; i+j-1<=n && !pocz[i]; j<<=1)
		{
			ll x=daj_hasz(i, i+j-1);
			const vi &poz=mapa[j][x];
			int w=lower_bound(poz.begin(), poz.end(), i)-poz.begin();
			assert(poz[w]==i);
			for (int l=w+1; l<(int)poz.size() && poz[l]-i<=2*j && !pocz[i] && l-w<=magia; l++)
			{
				int dlu=poz[l]-i;
				if (i+dlu+dlu-1>n)
					break;
				if (daj_hasz(i, i+dlu-1)==daj_hasz(i+dlu, i+dlu+dlu-1))
					pocz[i]=2*dlu;
			}
		}
	}
	
	for (int i=1; i<=n; i++)//kon
	{
		for (int j=1; i-j+1>=1 && !kon[i]; j<<=1)
		{
			ll x=daj_hasz(i-j+1, i);
			const vi &poz=mapa[j][x];
			int w=lower_bound(poz.begin(), poz.end(), i-j+1)-poz.begin();
			assert(poz[w]==i-j+1);
			for (int l=w-1; l>=0 && i-j+1-poz[l]<=2*j && !kon[i] && w-l<=magia; l--)
			{
				int dlu=i-(poz[l]+j)+1;
				if (i-dlu-dlu+1<1)
					break;
				if (daj_hasz(i-dlu+1, i)==daj_hasz(i-dlu-dlu+1, i-dlu))
					kon[i]=2*dlu;
			}
		}
	}
	
	
	debug() << range(pocz+1, pocz+1+n);
	debug() << range(kon+1, kon+1+n);
}

pii prze[nax];
vi tutaj[nax];

int num;

int wyn[nax];

void zamiec()
{
	int najp=0;
	for (int i=1; i<=n; i++)
	{
		if (kon[i])
			najp=max(najp, i-kon[i]+1);
		for (int j : tutaj[i])
			if (najp>=prze[j].first)
				wyn[j]=3;
	}
}

int nie_powta(int a, int b)
{
	tutaj[b].push_back(num);
	return 4;
}

int powta(int a, int b)
{
	if (pocz[a] && a+pocz[a]-1<=b)
		return 2;
	if (kon[b] && b-kon[b]+1>=a)
		return 2;
	//~ debug() << "Tak";
	for (int i=1; 2*i<=b-a+1; i<<=1)
	{
		ll x=daj_hasz(b-i+1, b);
		const vi &poz=mapa[i][x];
		int w=lower_bound(poz.begin(), poz.end(), a)-poz.begin();
		int ory=lower_bound(poz.begin(), poz.end(), b-i+1)-poz.begin();
		assert(poz[ory]==b-i+1);
		for (int j=w; j<ory && j-w<=magia; j++)
		{
			int dlu=i+(poz[j]-a);
			if (2*dlu>b-a+1 || dlu>2*i)
				break;
			if (daj_hasz(a, a+dlu-1)==daj_hasz(b-dlu+1, b))
				return 2;
		}
	}
	
	return 3;
}

int query()
{
	num++;
	int a, b;
	scanf("%d%d", &a, &b);
	prze[num]={a, b};
	int czy=0;
	for (int i=0; i<d; i++)
		if (ile_lit(a, b, i)>1)
			czy=1;
	if (!czy)
		return -1;
	for (int i : dz[b-a+1])
	{
		int dlu=(b-a+1)/i;
		if (daj_hasz(a, b-dlu)==daj_hasz(a+dlu, b))
			return 1;
	}
	
	if (ile_lit(a, b, tab[a])==1 && ile_lit(a, b, tab[b])==1)
		return nie_powta(a, b);
	else
		return powta(a, b);
	
	assert(0);
}

int main()
{
	scanf("%d", &n);
	scanf("%s", wcz+1);
	pot1[0]=pot2[0]=1;
	for (int i=1; i<=n; i++)
	{
		tab[i]=wcz[i]-'a';
		pot1[i]=(pot1[i-1]*h)%mod1;
		hasz1[i]=(hasz1[i-1]*h+tab[i])%mod1;
		pot2[i]=(pot2[i-1]*h)%mod2;
		hasz2[i]=(hasz2[i-1]*h+tab[i])%mod2;
		for (int j=0; j<d; j++)
			lit[i][j]=lit[i-1][j];
		lit[i][tab[i]]++;
	}
	for (int i=2; i<=n; i++)
	{
		if (!sito[i])
		{
			for (int j=i; j<=n; j+=i)
			{
				sito[j]=1;
				dz[j].push_back(i);
			}
		}
	}
	pre_pro();
	scanf("%d", &q);
	for (int i=1; i<=q; i++)
		wyn[i]=query();
	zamiec();
	for (int i=1; i<=q; i++)
		printf("%d\n", wyn[i]);
	return 0;
}
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
const ll mod=1000*1000*1000+7;
const ll haha=1000*1000+3;

int n;

char wcz[nax];
int tab[nax];

int skok[nax];

map<int,int> mapa;

int ktotu[nax];
int dok[nax];
int jak[nax];

vector<pair<int,ll>> jump[nax];

int dlu[nax];

ll pot[nax];

int main()
{
	pot[0]=1;
	for (int i=1; i<nax; i++)
		pot[i]=(pot[i-1]*haha)%mod;
	scanf("%s", wcz+1);
	n=strlen(wcz+1);
	for (int i=1; i<=n; i++)
	{
		if (wcz[i]=='(')
			tab[i]=1;
		else
			tab[i]=3;
	}
	mapa[0]=0;
	int bil=0;
	for (int i=1; i<=n; i++)
	{
		bil+=tab[i]-2;
		if (mapa.count(bil))
			skok[mapa[bil]]=i;
		mapa[bil]=i;
		while(!mapa.empty())
		{
			auto it=mapa.begin();
			if ((it->first)<bil)
				mapa.erase(it);
			else
				break;
		}
	}
	//~ debug() << range(skok, skok+1+n);
	ktotu[n]=n;
	for (int i=n-1; i>=0; i--)
	{
		ktotu[i]=i;
		dok[i]=ktotu[i+1];
		jak[i]=tab[i+1];
		jump[i].push_back({dok[i], jak[i]});
		dlu[i]=1+dlu[ktotu[i+1]];
		while(jump[i].back().first!=n)
		{
			//~ debug() << i << " " << jump[i];
			int a=jump[i].back().first;
			int b=min(jump[i].size(), jump[a].size())-1;
			int w=jump[a][b].first;
			ll mno=jump[i].size();
			mno=pot[1<<mno];
			ll h=(jump[i].back().second+mno*jump[a][b].second)%mod;
			jump[i].push_back({w, h});
		}
		//~ debug() << i << " " << jump[i];
		if (!skok[i])
			continue;
		int a=i;
		int b=ktotu[skok[i]];
		for (int h=20; h>=0; h--)
		{
			if (h<(int)jump[a].size() && h<(int)jump[b].size() && jump[a][h].second==jump[b][h].second)
			{
				a=jump[a][h].first;
				b=jump[b][h].first;
			}
		}
		if (a==n || b==n)
		{
			if (b==n)
				ktotu[i]=ktotu[skok[i]];
			continue;
		}
		if (jump[a][0].second>jump[b][0].second)
		{
			ktotu[i]=ktotu[skok[i]];
		}
	}
	//~ debug() << range(ktotu, ktotu+1+n);
	int v=ktotu[v];
	while(v!=n)
	{
		int w=jump[v][0].second;
		if (w==1)
			printf("(");
		else
			printf(")");
		v=jump[v][0].first;
	}
	printf("\n");
	return 0;
}
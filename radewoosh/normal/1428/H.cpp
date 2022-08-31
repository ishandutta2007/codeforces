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
const int nax=3007;

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

void ff()
{
	fflush(stdout);
}

int n, m;

int pole;

int poz[nax];

int zapy;

int policz()
{
	int ret=0;
	for (int i=0; i<n*m; i++)
	{
		int czy=1;
		for (int j=0; j<n; j++)
		{
			int x=i-poz[j];
			x%=(n*m);
			x+=(n*m);
			x%=(n*m);
			if (x<m)
				czy=0;
		}
		ret+=czy;
	}
	return ret;
}

void zrob(int v, int kier)
{
	zapy++;
	assert(zapy<=15000);
	printf("? %d %d\n", v, kier);
	ff();
	scanf("%d", &pole);
	
	//~ poz[v]=(poz[v]+kier+n*m)%(n*m);
	//~ pole=policz();
}

int los(int a, int b)
{
	return a+rng()%(b-a+1);
}

int k;
vi gru[nax];

vector<pii> graf[nax];

void kra(int a, int b, int prz)
{
	prz%=(n*m);
	prz+=(n*m);
	prz%=(n*m);
	graf[a].push_back({b, prz});
	graf[b].push_back({a, (n*m-prz)%(n*m)});
}

int malew[nax];

int wyn[nax];
int bylo[nax];

void dfs(int v)
{
	bylo[v]=1;
	for (pii i : graf[v])
	{
		if (!bylo[i.first])
		{
			wyn[i.first]=(wyn[v]+i.second)%(n*m);
			dfs(i.first);
		}
	}
}

int main()
{
	scanf("%d%d", &n, &m);
	//~ for (int i=0; i<n; i++)
		//~ poz[i]=los(0, n*m-1);
		//~ poz[i]=i*m;
	//~ debug() << range(poz, poz+n);
	for (int i=0; i<n; i++)
	{
		int x=los(-20, 20);
		while(x)
		{
			zrob(i, x/abs(x));
			x-=x/abs(x);
		}
	}
	vi kol(n);
	iota(kol.begin(), kol.end(), 0);
	shuffle(kol.begin(), kol.end(), rng);
	for (int i : kol)
	{
		int pam=pole;
		while(1)
		{
			zrob(i, 1);
			if (pole<pam)
			{
				zrob(i, -1);
				break;
			}
			pam=pole;
		}
	}
	//~ debug() << range(poz, poz+n);
	//~ debug() << imie(zapy);
	
	shuffle(kol.begin(), kol.end(), rng);
	for (int i : kol)
	{
		int mam=0;
		zrob(i, 1);
		int pam=pole;
		for (int j=0; j<k && !mam; j++)
		{
			int x=gru[j].back();
			zrob(x, 1);
			if (pole>=pam)
			{
				gru[j].push_back(i);
				mam=1;
			}
			zrob(x, -1);
		}
		zrob(i, -1);
		if (!mam)
		{
			gru[k].push_back(i);
			k++;
		}
	}
	//~ debug() << imie(k);
	//~ for (int i=0; i<k; i++)
		//~ debug() << gru[i];
	for (int i=0; i<k; i++)
		for (int j=1; j<(int)gru[i].size(); j++)
			kra(gru[i][0], gru[i][j], 0);
	//~ debug() << imie(zapy);
	for (int i=0; i+1<k; i++)
	{
		int x=gru[i].back();
		int ruchy=0;
		while(1)
		{
			ruchy++;
			int pam=pole;
			int oczek=pam;
			if (ruchy<=m)
				oczek--;
			zrob(x, 1);
			if (pole==oczek)
				continue;
			ruchy--;
			zrob(x, -1);
			int znaj=0;
			for (int j=0; j<k && !znaj; j++)
			{
				if (malew[j] || j==i)
					continue;
				pam=pole;
				int y=gru[j].back();
				zrob(y, -1);
				int nowe=pole;
				zrob(y, 1);
				if (nowe>=pam)
				{
					kra(x, y, ruchy+m);
					malew[j]=1;
					znaj=1;
					//~ debug() << "od " << i << " do " << j << "   " << x << " " << y << " " << imie(ruchy) << imie(poz[x]) << imie(poz[y]);
				}
			}
			assert(znaj);
			while(ruchy--)
				zrob(x, -1);
			break;
		}
	}
	dfs(0);
	//~ for (int i=0; i<n; i++)
		//~ debug() << i << " " << graf[i];
	//~ debug() << range(poz, poz+n);
	printf("!");
	for (int i=1; i<n; i++)
		printf(" %d", wyn[i]);
	printf("\n");
	ff();
	//~ for (int i=1; i<n; i++)
		//~ assert(wyn[i]==((poz[i]-poz[0]+n*m)%(n*m)));
	//~ debug() << imie(zapy);
	return 0;
}
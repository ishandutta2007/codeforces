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
const int nax=107;

int n, m;

int tab[nax][nax];
int musz[nax][nax];

vector <vi> wyn;

pii fast[nax*nax];

inline pii gdz(const int &v)
{
	return fast[v];
	for (int i=1; i<=n; i++)
		for (int j=1; j<=m; j++)
			if (tab[i][j]==v)
				return {i, j};
	assert(0);
}

inline int &war(const pii &v)
{
	return tab[v.first][v.second];
}

void zrob(const vi &wek)
{
	vector <pii> poz(wek.size());
	//~ for (int i : wek)
		//~ poz.push_back(gdz(i));
	for (int i=0; i<(int)wek.size(); i++)
		poz[i]=gdz(wek[i]);
	//~ debug() << poz;
	for (int i=(int)poz.size()-1; i>0; i--)
	{
		pii a=poz[i];
		pii b=poz[i-1];
		swap(tab[a.first][a.second], tab[b.first][b.second]);
		swap(fast[tab[a.first][a.second]], fast[tab[b.first][b.second]]);
		
		//~ swap(war(poz[i]), war(poz[i-1]));
		//~ swap(fast[war(poz[i])], fast[war(poz[i-1])]);
	}
	wyn.push_back(wek);
}

void cofnij()
{
	assert(!wyn.empty());
	vi wez=wyn.back();
	reverse(wez.begin(), wez.end());
	zrob(wez);
	wyn.pop_back();
	wyn.pop_back();
}

vi daj_kwa(pii v)
{
	vi ret;
	ret.push_back(tab[v.first][v.second]);
	ret.push_back(tab[v.first][v.second+1]);
	ret.push_back(tab[v.first+1][v.second+1]);
	ret.push_back(tab[v.first+1][v.second]);
	return ret;
}

vi daj_kwa2(pii v)
{
	vi ret=daj_kwa(v);
	reverse(ret.begin(), ret.end());
	return ret;
}

int chce[nax*nax];

vi los(int a, int b)
{
	//~ if (rand()&1)
	//~ {
		if (rand()&1)
			return daj_kwa({a+(rand()&1), b+(rand()&1)});
		else
			return daj_kwa2({a+(rand()&1), b+(rand()&1)});
	//~ }
}

void solve(int a, int b, int lim)
{
	while(1)
	{
		for (int h=0; h<lim/4; h++)
		{
			int czy=1;
			for (int i=0; i<3 && czy; i++)
				for (int j=0; j<3 && czy; j++)
					if (chce[musz[a+i][b+j]] && musz[a+i][b+j]!=tab[a+i][b+j])
						czy=0;
			if (czy)
				return;
			zrob(los(a, b));
		}
		
		
		for (int i=0; i<lim/4; i++)
			cofnij();
	}
}

int przelicz()
{
	int ret=0;
	for (vi i : wyn)
		ret+=i.size();
	return ret;
}

bool mniej(pii a, pii b)
{
	return a.second>b.second;
}

const int magic=1200;

int main()
{
	scanf("%d%d", &n, &m);
	for (int i=1; i<=n; i++)
	{
		for (int j=1; j<=m; j++)
		{
			musz[i][j]=m*(i-1)+j;
			scanf("%d", &tab[i][j]);
			fast[tab[i][j]]={i, j};
		}
	}
	int pn=n;
	while(pn>3)
	{
		//~ debug() << "a";
		for (int i=m; i>1; i--)
		{
			int tutaj=musz[pn][i];
			while(gdz(tutaj)!=make_pair(pn, i))
			{
				pii x=gdz(tutaj);
				if (x.second!=i)
				{
					if (x.second<i)
					{
						if (x.first<pn)
						{
							zrob(daj_kwa(x));
						}
						else
						{
							zrob(daj_kwa2({x.first-1, x.second}));
						}
					}
					else
					{
						if (x.first<pn-1)
						{
							zrob(daj_kwa2({x.first, x.second-1}));
						}
						else
						{
							zrob(daj_kwa({x.first-1, x.second-1}));
						}
					}
				}
				else
				{
					zrob(daj_kwa({x.first, x.second-1}));
				}
			}
		}
		
		int tutaj=musz[pn][1];
		while(gdz(tutaj).first<pn-1)
		{
			pii x=gdz(tutaj);
			if (x.second>1)
			{
				zrob(daj_kwa({x.first, x.second-1}));
			}
			else
			{
				zrob(daj_kwa2(x));
			}
		}
		while(gdz(tutaj).second>3)
		{
			pii x=gdz(tutaj);
			zrob(daj_kwa({x.first-1, x.second-1}));
		}
		
		chce[musz[pn][1]]=chce[musz[pn][2]]=chce[musz[pn][3]]=1;
		solve(pn-2, 1, magic);
		pn--;
	}
	
	int pm=m;
	while(pm>3)
	{
		vector <pii> poz;
		for (int i=1; i<=3; i++)
			poz.push_back(gdz(musz[i][pm]));
		sort(poz.begin(), poz.end(), mniej);
		int czy=0;
		for (int i=0; i<3; i++)
		{
			if (poz[i].second>=pm-i)
				continue;
			czy=1;
			pii x=poz[i];
			if (x.first==1)
				zrob(daj_kwa(x));
			else
				zrob(daj_kwa2({x.first-1, x.second}));
			break;
		}
		if (czy)
			continue;
		
		chce[musz[1][pm]]=chce[musz[2][pm]]=chce[musz[3][pm]]=1;
		solve(1, pm-2, magic);
		pm--;
	}
	int resz=99*1000-przelicz();
	for (int i=1; i<=3; i++)
		for (int j=1; j<=3; j++)
			chce[musz[i][j]]=1;
	solve(1, 1, resz);
	
	//~ for (int i=1; i<=n; i++)
		//~ debug() << range(tab[i]+1, tab[i]+1+m);
	
	for (int i=1; i<=n; i++)
		for (int j=1; j<=m; j++)
			assert(musz[i][j]==tab[i][j]);
	debug() << imie(przelicz());
	
	//~ return 0;
	printf("%d\n", (int)wyn.size());
	for (vi i : wyn)
	{
		printf("%d", (int)i.size());
		for (int j : i)
			printf(" %d", j);
		printf("\n");
	}
	return 0;
}
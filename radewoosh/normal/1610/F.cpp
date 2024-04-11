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
const int nax=300*1007;

int n, m;

pii kra[nax];
int wag[nax];

int bylo[nax];
vector<pii> graf[nax];
int ojc[nax];
int gle[nax];

int spec[nax];

int uzyte[nax];

//~ vector<pair<pii,vi>> super;

int rusz(int v, int w)
{
	return v^kra[w].first^kra[w].second;
}

int wyn;
int skier[nax];

//~ int wjed[nax];
//~ int wdwa[nax];

vector<pair<int,vi>>sup[nax];

void polacz(int a, int b)
{
	//~ debug() << "Sta";
	//~ debug() << a << " " << b;
	//~ debug() << range(ojc+1, ojc+1+n);
	pii pam={a, b};
	vi raz, dwa;
	while(a!=b)
	{
		if (gle[a]>gle[b])
		{
			raz.push_back(ojc[a]);
			a=rusz(a, ojc[a]);
		}
		else
		{
			dwa.push_back(ojc[b]);
			b=rusz(b, ojc[b]);
		}
	}
	while(!dwa.empty())
	{
		raz.push_back(dwa.back());
		dwa.pop_back();
	}
	//~ super.push_back({pam, raz});
	sup[pam.first].push_back({pam.second, raz});
	reverse(raz.begin(), raz.end());
	sup[pam.second].push_back({pam.first, raz});
	for (int i : raz)
		uzyte[i]=1;
	//~ debug() << "kon";
}

int dfs1(int v)
{
	int ret=0;
	bylo[v]=1;
	if (spec[v])
		ret=v;
	for (pii i : graf[v])
	{
		if (bylo[i.first])
			continue;
		ojc[i.first]=i.second;
		gle[i.first]=gle[v]+1;
		int wez=dfs1(i.first);
		if (!wez)
			continue;
		if (!ret)
		{
			ret=wez;
		}
		else
		{
			polacz(ret, wez);
			ret=0;
		}
	}
	return ret;
}

void skieruj(int v, int z, int g)
{
	if (kra[v].first==z)
		skier[v]=1;
	else
		skier[v]=2;
}

void dfs2(int v)
{
	while(!graf[v].empty())
	{
		pii x=graf[v].back();
		graf[v].pop_back();
		if (bylo[x.second])
			continue;
		bylo[x.second]=1;
		dfs2(x.first);
		skieruj(x.second, v, x.first);
	}
}

void skieruj_max(vi wek, int a, int b)
{
	for (int i : wek)
	{
		int p=rusz(a, i);
		skieruj(i, a, p);
		a=p;
	}
}

int bieg(int v)
{
	bylo[v]=1;
	int ret=v;
	for (auto &i : sup[v])
	{
		if (bylo[i.first])
			continue;
		ret=bieg(i.first);
		skieruj_max(i.second, v, i.first);
	}
	return ret;
}

int main()
{
	scanf("%d%d", &n, &m);
	for (int i=1; i<=m; i++)
	{
		int a, b;
		scanf("%d%d%d", &a, &b, &wag[i]);
		kra[i]={a, b};
		if (wag[i]==1)
		{
			graf[a].push_back({b, i});
			graf[b].push_back({a, i});
			spec[a]^=1;
			spec[b]^=1;
		}
	}
	for (int i=1; i<=n; i++)
		wyn+=spec[i];
	//~ debug() << "0";
	for (int i=1; i<=n; i++)
	{
		if (bylo[i])
			continue;
		gle[i]=1;
		dfs1(i);
	}
	//~ jede=super;
	//~ super.clear();
	//~ debug() << "A";
	for (int i=1; i<=n; i++)
		spec[i]=0;
	for (int i=1; i<=n; i++)
		graf[i].clear();
	for (int i=1; i<=m; i++)
	{
		int a, b;
		a=kra[i].first;
		b=kra[i].second;
		if (wag[i]==2)
		{
			graf[a].push_back({b, i});
			graf[b].push_back({a, i});
			spec[a]^=1;
			spec[b]^=1;
		}
	}
	for (int i=1; i<=n; i++)
		gle[i]=bylo[i]=ojc[i]=0;
	for (int i=1; i<=n; i++)
	{
		if (bylo[i])
			continue;
		gle[i]=1;
		dfs1(i);
	}
	//~ debug() << "B";
	//~ dwa=super;
	//~ super.clear();
	for (int h=1; h<=2; h++)
	{
		for (int i=1; i<=max(n, m); i++)
		{
			graf[i].clear();
			bylo[i]=0;
		}
		for (int i=1; i<=m; i++)
		{
			int a, b;
			a=kra[i].first;
			b=kra[i].second;
			if (wag[i]==h && !uzyte[i])
			{
				graf[a].push_back({b, i});
				graf[b].push_back({a, i});
				spec[a]^=1;
				spec[b]^=1;
			}
		}
		for (int i=1; i<=n; i++)
			dfs2(i);
	}
	for (int i=1; i<=n; i++)
	{
		bylo[i]=0;
	}
	//~ for (int i=0; i<(int)jede.size(); i++)
	//~ {
		//~ wjed[jede[i].first.first]=i;
		//~ wjed[jede[i].first.second]=i;
	//~ }
	//~ for (int i=0; i<(int)dwa.size(); i++)
	//~ {
		//~ wdwa[dwa[i].first.first]=i;
		//~ wdwa[dwa[i].first.second]=i;
	//~ }
	//~ for (auto &i : jede)
	//~ {
		//~ sup[i.first.first].push_back({i.first.second, i.second});
		//~ reverse(i.second.begin(), i.second.end());
		//~ sup[i.first.second].push_back({i.first.first, i.second});
	//~ }
	//~ for (auto &i : dwa)
	//~ {
		//~ sup[i.first.first].push_back({i.first.second, i.second});
		//~ reverse(i.second.begin(), i.second.end());
		//~ sup[i.first.second].push_back({i.first.first, i.second});
	//~ }
	for (int i=1; i<=n; i++)
	{
		if (bylo[i])
			continue;
		if ((int)sup[i].size()!=1)
			continue;
		bieg(i);
	}
	for (int i=1; i<=n; i++)
	{
		if (bylo[i])
			continue;
		if ((int)sup[i].size()!=2)
			continue;
		if (sup[i][0].first==sup[i][1].first)
		{
			int x=sup[i][0].first;
			bylo[i]=bylo[x]=1;
			skieruj_max(sup[i][0].second, i, x);
			reverse(sup[i][1].second.begin(), sup[i][1].second.end());
			skieruj_max(sup[i][1].second, x, i);
			continue;
		}
		int wez=bieg(i);
		for (auto j : sup[wez])
			if (j.first==i)
				skieruj_max(j.second, wez, i);
	}
	
	printf("%d\n", wyn);
	for (int i=1; i<=m; i++)
		printf("%d", skier[i]);
	printf("\n");
	return 0;
}
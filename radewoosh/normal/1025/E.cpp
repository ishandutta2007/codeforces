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
const int nax=57;
using bn=bitset<nax>;
const int limit=60*60*3;

int n, m;

pii sta[nax];
pii kon[nax];

pii poz[nax];
int blok[nax][nax];

vector <pair<pii,pii> > wyn;

bool flag;

int odl[nax][nax];

int rx[]={1, -1, 0, 0};
int ry[]={0, 0, 1, -1};

pii rusz(pii v, int w)
{
	return {v.first+rx[w], v.second+ry[w]};
}

vector <pii> bfs(pii a, pii b)
{
	flag=false;
	if (a==b)
	{
		flag=true;
		return {};
	}
	if (blok[b.first][b.second])
		return {};
	for (int i=0; i<=n+1; i++)
		for (int j=0; j<=n+1; j++)
			odl[i][j]=-1;
	odl[b.first][b.second]=0;
	queue <pii> kol;
	kol.push(b);
	while(!kol.empty())
	{
		pii v=kol.front();
		kol.pop();
		for (int i=0; i<4; i++)
		{
			pii u=rusz(v, i);
			if (odl[u.first][u.second]==-1 && (!blok[u.first][u.second] || u==a))
			{
				odl[u.first][u.second]=odl[v.first][v.second]+1;
				kol.push(u);
			}
		}
	}
	if (odl[a.first][a.second]==-1)
	{
		flag=false;
		return {};
	}
	flag=true;
	vector <pii> ret;
	while(a!=b)
	{
		for (int i=0; 1; i++)
		{
			assert(i<4);
			pii u=rusz(a, i);
			if (odl[u.first][u.second]+1==odl[a.first][a.second] && !blok[u.first][u.second])
			{
				a=u;
				ret.push_back(a);
				break;
			}
		}
	}
	return ret;
}

pii los()
{
	return {(rand()%n)+1, (rand()%n)+1};
}

vector <pair <pii,pii>> ods;
		
void rusz(pii &v, vector <pii> wek, bool pisz=false)
{
	for (auto i : wek)
	{
		blok[v.first][v.second]=0;
		blok[i.first][i.second]=1;
		if (pisz)
			ods.push_back({i, v});
		wyn.push_back({v, i});
		v=i;
	}
}

pii &szuk(pii v)
{
	for (int i=1; i<=m; i++)
		if (poz[i]==v)
			return poz[i];
}

int zle;

int gdz=1;

void solve(int tryb)
{
	wyn.clear();
	for (int i=1; i<=m; i++)
		poz[i]=sta[i];
	vi kol;
	for (int i=1; i<=m; i++)
		kol.push_back(i);
	shandom_ruffle(kol.begin(), kol.end());
	for (int i=0; i<=n+1; i++)
		for (int j=0; j<=n+1; j++)
			blok[i][j]=1;
	for (int i=1; i<=n; i++)
		for (int j=1; j<=n; j++)
			blok[i][j]=0;
	for (int i=1; i<=m; i++)
		blok[poz[i].first][poz[i].second]=1;
	
	int zbio=1;
	if (tryb==1)
		zbio=gdz;
	if (tryb==2)
		zbio=n;
	
	int ost=m+1;
	while(1)
	{
		int czy=0;
		for (int i=1; i<=m; i++)
			if (poz[i].first!=zbio)
				czy++;
		if (!czy)
			break;
		assert(czy<ost);
		ost=czy;
		shandom_ruffle(kol.begin(), kol.end());
		for (int i : kol)
		{
			if (poz[i].first==zbio)
				continue;
			for (int j=1; j<=n; j++)
			{
				if (!blok[zbio][j])
				{
					auto wez=bfs(poz[i], {zbio, j});
					if (flag)
					{
						rusz(poz[i], wez);
						break;
					}
				}
			}
		}
	}
	vector <pair <pii,int> > cele;
	for (int i=1; i<=m; i++)
		cele.push_back({{abs(kon[i].first-zbio), kon[i].second}, i});
	sort(cele.begin(), cele.end());
	reverse(cele.begin(), cele.end());
	while(1)
	{
		int okok=1;
		for (int i=1; i<=m; i++)
			if (poz[i]!=kon[i])
				okok=0;
		if (okok)
			break;
		int czy=0;
		for (auto i : cele)
		{
			int w=i.second;
			if (poz[w]==kon[w])
				continue;
			auto wez=bfs(poz[w], kon[w]);
			if (!flag)
				continue;
			czy=1;
			rusz(poz[w], wez);
		}
		if (!czy)
			return;
	}
	if ((int)wyn.size()>limit)
		return;
	printf("%d\n", (int)wyn.size());
	for (auto i : wyn)
	{
		if (zle)
		{
			swap(i.first.first, i.first.second);
			swap(i.second.first, i.second.second);
		}
		printf("%d %d %d %d\n", i.first.first, i.first.second, i.second.first, i.second.second);
	}
	exit(0);
}

int main()
{
	srand(69);
	scanf("%d%d", &n, &m);
	

	for (int i=1; i<=m; i++)
	{
		scanf("%d%d", &sta[i].first, &sta[i].second);
	}
	for (int i=1; i<=m; i++)
	{
		scanf("%d%d", &kon[i].first, &kon[i].second);
	}
	gdz=(n+1)/2;
	for (int i=1; i<=n; i++)
	{
		int nal=0;
		for (int j=1; j<=m; j++)
			if (kon[j].first==i)
				nal++;
		if (!nal)
			gdz=i;
	}
	for (int h=0; 1; h++)
	{
		solve(h%3);
		if (rand()&1)
		{
			zle^=1;
			for (int i=1; i<=m; i++)
			{
				swap(sta[i].first, sta[i].second);
				swap(kon[i].first, kon[i].second);
			}
		}
	}
	return 0;
}
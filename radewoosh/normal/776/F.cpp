#ifndef LOCAL
#define NDEBUG
#endif

#include <bits/stdc++.h>
using namespace std;

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
  for (auto it = d.b; it != d.e; ++it) 
    *this << ", \0[" + 3 * (it == d.b) << *it;
  ris << "]";
}
#else
sim dor(const c&) { ris; }
#endif
};

#define imie(x) "[" << #x ": " << (x) << "] "

const int nax=1000*1007;

int n, mm;

vector <int> graf[nax];

int cen;

int oj[nax];
int m;
vector <int> co[nax];

int mapa[nax];
int k;

vector < pair < pair <int,int> , int> > trz;

vector <int> wla[nax];

vector <long long> tu[nax];

vector <int> pos[nax];

bool mniej(int a, int b)
{
	a-=cen;
	b-=cen;
	if (a<0)
		a+=n;
	if (b<0)
		b+=n;
	return a<b;
}

int fin(int v)
{
	if (v!=oj[v])
		oj[v]=fin(oj[v]);
	return oj[v];
}

void uni(int v, int u)
{
	v=fin(v);
	u=fin(u);
	if (v>u)
		swap(v, u);
	oj[u]=v;
}

int dos[nax];
int wyn[nax];

int bylcen[nax];

bool por(int a, int b)
{
	for (int i=0; i<tu[a].size(); i++)
		if (tu[a][i]!=tu[b][i])
			return tu[a][i]<tu[b][i];
}

int roz[nax];
int maxi[nax];
vector <int> spo;

void dfs(int v, int oj)
{
	roz[v]=1;
	maxi[v]=0;
	spo.push_back(v);
	for (int i=0; i<wla[v].size(); i++)
	{
		if (bylcen[wla[v][i]] || wla[v][i]==oj)
			continue;
		dfs(wla[v][i], v);
		roz[v]+=roz[wla[v][i]];
		maxi[v]=max(maxi[v], roz[wla[v][i]]);
	}
}

void szuk(int v, int il)
{
	if (bylcen[v])
		return;
	spo.clear();
	dfs(v, 0);
	int c=-1;
	for (int i=0; i<spo.size(); i++)
	{
		int v=spo[i];
		if (maxi[v]*2<=(int)spo.size() && ((int)spo.size()-roz[v])*2<=(int)spo.size())
			c=v;
	}
	debug() << "z " << v << " " << c << " i jest " << il;
	assert(c>=0);
	wyn[c]=il;
	bylcen[c]=1;
	for (int i=0; i<wla[c].size(); i++)
		szuk(wla[c][i], il+1);
}

int main()
{
	scanf("%d%d", &n, &mm);
	for (int i=1; i<=n; i++)
	{
		int x=(i%n)+1;
		graf[i].push_back(x);
		graf[x].push_back(i);
	}
	for (int i=1; i<=mm; i++)
	{
		int p1, p2;
		scanf("%d%d", &p1, &p2);
		graf[p1].push_back(p2);
		graf[p2].push_back(p1);
	}
	for (int i=1; i<=n; i++)
	{
		cen=i;
		sort(graf[i].begin(), graf[i].end(), mniej);
	}
	for (int i=1; i<=n; i++)
	{
		for (int j=0; j+1<(int)graf[i].size(); j++)
		{
			m++;
			oj[m]=m;
			co[i].push_back(m);
		}
	}
	for (int i=1; i<=n; i++)
	{
		for (int j=0; j+1<(int)graf[i].size(); j++)
		{
			trz.push_back({{i, graf[i][j]}, co[i][j]});
			trz.push_back({{graf[i][j+1], i}, co[i][j]});
		}
	}
	sort(trz.begin(), trz.end());
	for (int i=0; i<(int)trz.size(); i+=2)
		uni(trz[i].second, trz[i+1].second);
	for (int i=1; i<=m; i++)
	{
		if (oj[i]==i)
		{
			k++;
			mapa[i]=k;
		}
	}
	for (int i=1; i<=m; i++)
		mapa[i]=mapa[fin(i)];
	for (int i=1; i<=n; i++)
		for (int j=0; j<co[i].size(); j++)
			tu[mapa[co[i][j]]].push_back(i);
	for (int i=1; i<=n; i++)
	{
		for (int j=0; j+1<(int)co[i].size(); j++)
		{
			int x=mapa[co[i][j]];
			int y=mapa[co[i][j+1]];
			wla[x].push_back(y);
		}
	}
	for (int i=1; i<=k; i++)
	{
		sort(tu[i].begin(), tu[i].end());
		reverse(tu[i].begin(), tu[i].end());
		dos[i]=i;
		debug() << tu[i];
		debug() << i;
		debug() << wla[i];
	}
	szuk(1, 1);
	sort(dos+1, dos+1+k, por);
	for (int i=1; i<=k; i++)
		printf("%d ", wyn[dos[i]]);
	printf("\n");
	return 0;
}
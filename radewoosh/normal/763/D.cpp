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

int n;

vector <int> graf[1000007];

long long hd1[1000007];
long long hd2[1000007];
long long h=1000003;
long long mod1=1000000007;
long long mod2=1000000007;

long long hg1[1000007];
long long hg2[1000007];

pair <int,int> wyn[1000007];

map < pair <long long,long long> , int> mapa;

int aktu;

void dodaj(pair <long long,long long> v)
{
	mapa[v]++;
	if (mapa[v]==1)
		aktu++;
}

void usun(pair <long long,long long> v)
{
	mapa[v]--;
	if (mapa[v]==0)
		aktu--;
}

long long dod1(long long &a, long long b)
{
	a=(a+b)%mod1;
	a+=mod1;
	a%=mod1;
}

long long dod2(long long &a, long long b)
{
	a=(a+b)%mod2;
	a+=mod2;
	a%=mod2;
}

void dfs1(int v, int oj)
{
	hd1[v]=1;
	hd2[v]=1;
	long long x1=0;
	long long x2=0;
	for (int i=0; i<graf[v].size(); i++)
	{
		if (graf[v][i]==oj)
			continue;
		dfs1(graf[v][i], v);
		dod1(hd1[v], hd1[graf[v][i]]*h);
		dod2(hd2[v], hd2[graf[v][i]]*h);
		x1^=hd1[graf[v][i]];
		x2^=hd2[graf[v][i]];
	}
	dod1(hd1[v], x1);
	dod2(hd2[v], x2);
}

void dfs2(int v, int oj)
{
	long long p1=(hg1[v]*h+1)%mod1;
	long long p2=(hg2[v]*h+1)%mod2;
	long long x1=hg1[v];
	long long x2=hg2[v];
	
	debug() << v << " " << hd1[v] << " " << hd2[v];
	debug() << v << " " << hg1[v] << " " << hg2[v];
	debug();
	
	for (int i=0; i<graf[v].size(); i++)
	{
		if (graf[v][i]==oj)
			continue;
		dod1(p1, hd1[graf[v][i]]*h);
		dod2(p2, hd2[graf[v][i]]*h);
		x1^=hd1[graf[v][i]];
		x2^=hd2[graf[v][i]];
	}
	
	for (int i=0; i<graf[v].size(); i++)
	{
		if (graf[v][i]==oj)
			continue;
		x1^=hd1[graf[v][i]];
		x2^=hd2[graf[v][i]];
		dod1(hg1[graf[v][i]], p1-hd1[graf[v][i]]*h+x1);
		dod2(hg2[graf[v][i]], p2-hd2[graf[v][i]]*h+x2);
		x1^=hd1[graf[v][i]];
		x2^=hd2[graf[v][i]];
	}
	
	for (int i=0; i<graf[v].size(); i++)
	{
		if (graf[v][i]==oj)
			continue;
		dfs2(graf[v][i], v);
	}
}

void dfs3(int v, int oj)
{
	wyn[v].first=aktu;
	wyn[v].second=v;
	for (int i=0; i<graf[v].size(); i++)
	{
		if (graf[v][i]==oj)
			continue;
		dodaj({hg1[graf[v][i]], hg2[graf[v][i]]});
		usun({hd1[graf[v][i]], hd2[graf[v][i]]});
		dfs3(graf[v][i], v);
		dodaj({hd1[graf[v][i]], hd2[graf[v][i]]});
		usun({hg1[graf[v][i]], hg2[graf[v][i]]});
	}
}

int main()
{
	scanf("%d", &n);
	for (int i=1; i<n; i++)
	{
		int p1, p2;
		scanf("%d%d", &p1, &p2);
		graf[p1].push_back(p2);
		graf[p2].push_back(p1);
	}
	dfs1(1, 0);
	dfs2(1, 0);
	for (int i=2; i<=n; i++)
		dodaj({hd1[i], hd2[i]});
	dfs3(1, 0);
	sort(wyn+1, wyn+1+n);
	reverse(wyn+1, wyn+1+n);
	debug() << range(wyn+1, wyn+1+n);
	printf("%d\n", wyn[1].second);
	return 0;
}
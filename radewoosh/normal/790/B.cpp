//PRZEMYSL ASSERTY

//SPRAWDZ CORNER CASE'Y, MINIMALNE I MAKSYMALNE WEJCIE I WYJCIE

//MODULO = 1

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

const int nax=207*1000;
const int kax=7;

int n, k;

vector <int> graf[nax];

long long mdol[nax][kax];
long long mogol[nax][kax];

long long dol[nax];
long long ogol[nax];
long long roz[nax];

long long wyn;

void dfs1(int v, int oj)
{
	mdol[v][0]=1;
	roz[v]=1;
	for (int i=0; i<graf[v].size(); i++)
	{
		if (graf[v][i]==oj)
			continue;
		dfs1(graf[v][i], v);
		roz[v]+=roz[graf[v][i]];
		dol[v]+=dol[graf[v][i]]+roz[graf[v][i]];
		for (int j=0; j<k; j++)
			mdol[v][(j+1)%k]+=mdol[graf[v][i]][j];
	}
}

void dfs2(int v, int oj)
{
	for (int i=0; i<graf[v].size(); i++)
	{
		if (graf[v][i]==oj)
			continue;
		
		ogol[graf[v][i]]=ogol[v]-roz[graf[v][i]]+(n-roz[graf[v][i]]);
		for (int j=0; j<k; j++)
		{
			mogol[graf[v][i]][(j+1)%k]+=mogol[v][j];
			mogol[graf[v][i]][(j+2)%k]-=mdol[graf[v][i]][j];
			mogol[graf[v][i]][j]+=mdol[graf[v][i]][j];
		}
		
		dfs2(graf[v][i], v);
	}
}

int main()
{
	scanf("%d%d", &n, &k);
	for (int i=1; i<n; i++)
	{
		int p1, p2;
		scanf("%d%d", &p1, &p2);
		graf[p1].push_back(p2);
		graf[p2].push_back(p1);
	}
	dfs1(1, 0);
	ogol[1]=dol[1];
	for (int i=0; i<k; i++)
		mogol[1][i]=mdol[1][i];
	dfs2(1, 0);
	for (int i=1; i<=n; i++)
	{
		debug() << i;
		debug() << range(mdol[i], mdol[i]+k);
		debug() << range(mogol[i], mogol[i]+k);
		long long s=ogol[i];
		for (int j=1; j<k; j++)
			s+=mogol[i][j]*(k-j);
		debug() << s << " " << k;
		wyn+=s/k;
	}
	wyn/=2;
	printf("%lld\n", wyn);
	return 0;
}
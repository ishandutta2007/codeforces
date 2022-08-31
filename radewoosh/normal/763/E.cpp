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

const int nax=100007;

int n, k;
int m;

vector <int> graf[nax];

int q;
int wyn[nax];
int lew[nax];
int pra[nax];

int oj[nax];

vector < pair <int,int> > podz[nax];
int ile[nax];

int licz;
int kied[nax];

int z;
int zapy[nax];

int kjuz[nax];
int juz[nax];

vector <int> jed, dwa, tu;

int fin(int v)
{
	if (v!=oj[v])
		oj[v]=fin(oj[v]);
	return oj[v];
}

void unil(int v, int u)
{
	v=fin(v);
	u=fin(u);
	if(v<u)
		swap(v, u);
	oj[v]=u;
}

void unip(int v, int u)
{
	v=fin(v);
	u=fin(u);
	if(v>u)
		swap(v, u);
	oj[v]=u;
}

int wprze(int v, int a, int b)
{
	return ((a<=v)&&(v<=b));
}

void rek(int l, int p, int lz, int pz)
{
	if (lz>pz || l==p)
		return;
	int s=(l+p)/2;
	
	jed.clear();
	dwa.clear();
	tu.clear();
	
	for (int i=lz; i<=pz; i++)
	{
		if (pra[zapy[i]]<=s)
		{
			jed.push_back(zapy[i]);
			continue;
		}
		if (lew[zapy[i]]>s)
		{
			dwa.push_back(zapy[i]);
			continue;
		}
		tu.push_back(zapy[i]);
	}
	
	pair <int,int> nal, nap, tutaj;
	
	int gra=lz-1;
	for (int i=0; i<jed.size(); i++)
	{
		gra++;
		zapy[gra]=jed[i];
	}
	
	nal.first=lz;
	nal.second=gra;
	
	nap.first=gra+1;
	
	for (int i=0; i<dwa.size(); i++)
	{
		gra++;
		zapy[gra]=dwa[i];
	}
	
	nap.second=gra;
	tutaj.first=gra+1;
	
	for (int i=0; i<tu.size(); i++)
	{
		gra++;
		zapy[gra]=tu[i];
	}
	
	tutaj.second=pz;
	
	rek(l, s, nal.first, nal.second);
	rek(s+1, p, nap.first, nap.second);
	
	for (int i=l; i<=p; i++)
	{
		oj[i]=i;
		podz[i].clear();
		ile[i]=0;
	}
	for (int i=s; i>=l; i--)
	{
		ile[i]=ile[i+1]+1;
		if (i==s)
			ile[i]=1;
		for (int j=0; j<graf[i].size(); j++)
		{
			if (wprze(graf[i][j], i, s) && fin(i)!=fin(graf[i][j]))
			{
				ile[i]--;
				unip(i, graf[i][j]);
			}
		}
		for (int j=s; j>=i && s-j<k; j--)
			podz[i].push_back({j, fin(j)});
	}
	for (int i=s+1; i<=p; i++)
	{
		ile[i]=ile[i-1]+1;
		if (i==s+1)
			ile[i]=1;
		for (int j=0; j<graf[i].size(); j++)
		{
			if (wprze(graf[i][j], s+1, i) && fin(i)!=fin(graf[i][j]))
			{
				ile[i]--;
				unil(i, graf[i][j]);
			}
		}
		for (int j=s+1; j<=i && j-s<=k; j++)
			podz[i].push_back({j, fin(j)});
	}
	
	for (int h=tutaj.first; h<=tutaj.second; h++)
	{
		int x=zapy[h];
		
		int a=lew[x];
		int b=pra[x];
		
		int w=ile[a]+ile[b];
		
		licz++;
		
		for (int i=0; i<podz[a].size(); i++)
		{
			int gdz=podz[a][i].second;
			oj[podz[a][i].first]=podz[a][i].second;
			kied[podz[a][i].first]=licz;
		}
		for (int i=0; i<podz[b].size(); i++)
		{
			oj[podz[b][i].first]=podz[b][i].second;
			kied[podz[b][i].first]=licz;
		}
			
		for (int i=0; i<podz[a].size(); i++)
		{
			int u=podz[a][i].first;
			for (int j=0; j<graf[u].size(); j++)
			{
				if (kied[graf[u][j]]==licz && fin(u)!=fin(graf[u][j]))
				{
					w--;
					unip(u, graf[u][j]);
				}
			}
		}
		wyn[x]=w;
	}
}

int main()
{
	jed.reserve(nax);
	dwa.reserve(nax);
	tu.reserve(nax);
	
	scanf("%d%d", &n, &k);
	scanf("%d", &m);
	for (int i=1; i<=m; i++)
	{
		int p1, p2;
		scanf("%d%d", &p1, &p2);
		graf[p1].push_back(p2);
		graf[p2].push_back(p1);
	}
	scanf("%d", &q);
	for (int i=1; i<=q; i++)
	{
		scanf("%d%d", &lew[i], &pra[i]);
		if (lew[i]==pra[i])
		{
			wyn[i]=1;
		}
		else
		{
			z++;
			zapy[z]=i;
		}
	}
	rek(1, n, 1, z);
	for (int i=1; i<=q; i++)
		printf("%d\n", wyn[i]);
	return 0;
}
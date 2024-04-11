#include <bits/stdc++.h>
using namespace std;

int n;

long long m;

vector < pair <int,int> > graf[1000007];

int bylcen[1000007];

long long phi=1;
long long dzie;
long long pote[1000007];

long long wyn;

vector <int> tutaj;

int roz[1000007];
int naj[1000007];

void dfs1(int v, int oj)
{
	tutaj.push_back(v);
	roz[v]=1;
	naj[v]=0;
	for (int i=0; i<graf[v].size(); i++)
	{
		if (bylcen[graf[v][i].first] || graf[v][i].first==oj)
			continue;
		dfs1(graf[v][i].first, v);
		roz[v]+=roz[graf[v][i].first];
		naj[v]=max(naj[v], roz[graf[v][i].first]);
	}
}

map <long long,long long> mapa;

void dfs2(int v, int oj, long long ile, int d)
{
	wyn+=mapa[((m-ile)*pote[d])%m];
	//if (mapa[((m-ile)*pote[d])%m])
	//	printf("KURWA %d dalo %lld\n", v, mapa[((m-ile)*pote[d])%m]);
	for (int i=0; i<graf[v].size(); i++)
	{
		if (graf[v][i].first==oj || bylcen[graf[v][i].first])
			continue;
		dfs2(graf[v][i].first, v, (ile*10+graf[v][i].second)%m, d+1);
	}
}

int tak;

void dfs3(int v, int oj, long long ile, long long r)
{
	if (tak && !ile)
		wyn++;
	mapa[ile]++;
	for (int i=0; i<graf[v].size(); i++)
	{
		if (graf[v][i].first==oj || bylcen[graf[v][i].first])
			continue;
		dfs3(graf[v][i].first, v, (ile+graf[v][i].second*r)%m, (r*10)%m);
	}
}

void szuk(int v)
{
	if (bylcen[v])
		return;
	tutaj.clear();
	dfs1(v, 0);
	int c;
	for (int i=0; i<tutaj.size(); i++)
	{
		int x=tutaj[i];
		if ((tutaj.size()-roz[x])*2<=tutaj.size() && naj[x]*2<=tutaj.size())
		{
			c=x;
		}
	}
	
	mapa.clear();
	mapa[0]++;
	tak=1;
	for (int i=0; i<graf[c].size(); i++)
	{
		if (bylcen[graf[c][i].first])
			continue;
		dfs2(graf[c][i].first, c, graf[c][i].second%m, 1);
		dfs3(graf[c][i].first, c, graf[c][i].second%m, 10%m);
		//printf("w %d ma %lld\n", c, wyn);
	}
	//printf("po %d ma %lld\n", c, wyn);
	
	mapa.clear();
	tak=0;
	reverse(graf[c].begin(), graf[c].end());
	for (int i=0; i<graf[c].size(); i++)
	{
		if (bylcen[graf[c][i].first])
			continue;
		dfs2(graf[c][i].first, c, graf[c][i].second%m, 1);
		dfs3(graf[c][i].first, c, graf[c][i].second%m, 10%m);
		//printf("w %d ma %lld\n", c, wyn);
	}
	//printf("po %d ma %lld\n", c, wyn);
	bylcen[c]=1;
	for (int i=0; i<graf[c].size(); i++)
		szuk(graf[c][i].first);
}

long long pot(long long a, long long b)
{
	long long ret=1;
	while(b)
	{
		if (b&1)
		{
			ret*=a;
			ret%=m;
		}
		a*=a;
		a%=m;
		b>>=1;
	}
	return ret%m;
}

long long licz()
{
	vector <int> roz;
	int pom=m;
	for (int i=2; i*i<=pom; i++)
	{
		if (!(pom%i))
		{
			roz.push_back(i);
			pom/=i;
			i--;
		}
	}
	if (pom)
		roz.push_back(pom);
	for (int i=0; i<roz.size(); i++)
	{
		if (!i || (roz[i]!=roz[i-1]))
			phi*=roz[i]-1;
		else
			phi*=roz[i];
	}
	dzie=pot(10, phi-1);
	pote[0]=1;
	for (int i=1; i<=n; i++)
		pote[i]=(pote[i-1]*dzie)%m;
}

int main()
{
	scanf("%d%lld", &n, &m);
	if (m==1)
	{
		printf("%lld\n", (long long)n*(n-1));
		return 0;
	}
	licz();
	//printf("%lld %lld\n", phi, dzie);
	for (int i=1; i<n; i++)
	{
		int p1, p2, p3;
		scanf("%d%d%d", &p1, &p2, &p3);
		graf[p1].push_back(make_pair(p2, p3));
		graf[p2].push_back(make_pair(p1, p3));
	}
	szuk(0);
	printf("%lld\n", wyn);
	return 0;
}
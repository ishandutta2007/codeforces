#include <bits/stdc++.h>
using namespace std;

using ll=long long;
using pii=pair<int,int>;
using vi=vector<int>;
using vll=vector<ll>;
const int nax=3000*1007;

int n, q;

int tab[nax];

ll los[nax];

int m;
pii cons[nax];
ll xo[nax];

map<pii,vi> pozy;
map<pii,vll> hasze;

unordered_map<ll,int> mapa;

int wyn[nax];

void start(int a, int b)
{
	if (a<b)
	{
		start(a, (a+b)>>1);
		start((a+b+2)>>1, b);
	}
	pii p={a, b};
	for (int i=1; i<=n; i++)
		if (tab[i]>=a && tab[i]<=b)
			pozy[p].push_back(i);
	ll s=0;
	hasze[p].push_back(0);
	for (int i : pozy[p])
	{
		s^=los[i];
		hasze[p].push_back(s);
	}
}

int lacz(int a, int b)
{
	if (!a)
		return b;
	if (!b)
		return a;
	m++;
	cons[m]={a, b};
	xo[m]=xo[a]^xo[b];
	mapa[xo[m]]=m;
	return m;
}

ll daj(int a, int b, int lim)
{
	vi &wek=pozy[{a, b}];
	int x=upper_bound(wek.begin(), wek.end(), lim)-wek.begin();
	return hasze[{a, b}][x];
}

int rek(int a, int b, int dol, int gor)
{
	ll ha=daj(dol, gor, b)^daj(dol, gor, a-1);
	if (mapa.count(ha))
		return mapa[ha];
	return lacz(rek(a, b, dol, (dol+gor)>>1), rek(a, b, (dol+gor+2)>>1, gor));
}

int main()
{
	scanf("%d%d", &n, &q);
	for (int i=1; i<=n; i++)
		scanf("%d", &tab[i]);
	for (int i=1; i<=n; i++)
	{
		for (int j=1; j<=60; j++)
			los[i]=(los[i]<<1)^(rand()&1);
		xo[i]=los[i];
		mapa[xo[i]]=i;
	}
	m=n;
	mapa[0]=0;
	start(1, n);
	for (int i=1; i<=q; i++)
	{
		int a, b;
		scanf("%d%d", &a, &b);
		wyn[i]=rek(a, b, 1, n);
	}
	printf("%d\n", m);
	for (int i=n+1; i<=m; i++)
		printf("%d %d\n", cons[i].first, cons[i].second);
	for (int i=1; i<=q; i++)
		printf("%d ", wyn[i]);
	printf("\n");
	return 0;
}
#include <bits/stdc++.h>
using namespace std;

int n, m;
long long l;

int s, t;

vector <int> graf[1000007];

int mapa[1007][1007];

pair <int,int> kra[1000007];

int bylo[1000007];

long long odl1[1000007];
long long odl2[1000007];
long long odl3[1000007];

long long odl[1000007];
int st[1007][1007];

priority_queue < pair <long long,int> > dij;

int zap(int v, int u)
{
	if (v>u)
		swap(v, u);
	return mapa[v][u];
}

long long licz()
{
	for (int i=0; i<n; i++)
		bylo[i]=0;
	dij.push(make_pair(0, s));
	while(!dij.empty())
	{
		int v=dij.top().second;
		if (bylo[v])
		{
			dij.pop();
			continue;
		}
		odl[v]=-dij.top().first;
		dij.pop();
		bylo[v]=1;
		for (int i=0; i<graf[v].size(); i++)
		{
			int wag=zap(v, graf[v][i]);
			if (!wag)
				wag=st[v][graf[v][i]];
			dij.push(make_pair(-wag-odl[v], graf[v][i]));
		}
	}
	return odl[t];
}

long long check(long long bss)
{
	long long jesz=bss;
	for (int i=1; i<=m; i++)
	{
		if (zap(kra[i].first, kra[i].second))
			continue;
		long long r=min((long long)1000000000, jesz);
		jesz-=r;
		st[kra[i].first][kra[i].second]=r+1;
		st[kra[i].second][kra[i].first]=r+1;
	}
	return licz();
}

int main()
{
	scanf("%d%d%lld%d%d", &n, &m, &l, &s, &t);
	for (long long i=1; i<=m; i++)
	{
		int p1, p2, p3;
		scanf("%d%d%d", &p1, &p2, &p3);
		mapa[p1][p2]=p3;
		mapa[p2][p1]=p3;
		kra[i]=make_pair(p1, p2);
		graf[p1].push_back(p2);
		graf[p2].push_back(p1);
	}
	for (int i=0; i<n; i++)
		bylo[i]=0;
	dij.push(make_pair(0, s));
	while(!dij.empty())
	{
		int v=dij.top().second;
		if (bylo[v])
		{
			dij.pop();
			continue;
		}
		odl1[v]=-dij.top().first;
		dij.pop();
		bylo[v]=1;
		for (int i=0; i<graf[v].size(); i++)
		{
			int wag=zap(v, graf[v][i]);
			if (!wag)
				wag=1;
			dij.push(make_pair(-wag-odl1[v], graf[v][i]));
		}
	}
	
	for (int i=0; i<n; i++)
		bylo[i]=0;
	dij.push(make_pair(0, s));
	while(!dij.empty())
	{
		int v=dij.top().second;
		if (bylo[v])
		{
			dij.pop();
			continue;
		}
		odl3[v]=-dij.top().first;
		dij.pop();
		bylo[v]=1;
		for (int i=0; i<graf[v].size(); i++)
		{
			int wag=zap(v, graf[v][i]);
			if (!wag)
				wag=1000000007;
			dij.push(make_pair(-wag-odl3[v], graf[v][i]));
		}
	}
	
	if (odl1[t]>l || odl3[t]<l)
	{
		printf("NO\n");
		return 0;
	}
	printf("YES\n");
	long long bsa=0;
	long long bsb=(long long)m*1000000000;
	long long bss;
	while(1)
	{
		bss=(bsa+bsb)>>1;
		long long bie=check(bss);
		if (bie==l)
		{
			break;
		}
		if (bie<l)
		{
			bsa=bss+1;
		}
		else
		{
			bsb=bss;
		}
	}
	for (int i=1; i<=m; i++)
	{
		if (mapa[kra[i].first][kra[i].second])
			printf("%d %d %d\n", kra[i].first, kra[i].second, mapa[kra[i].first][kra[i].second]);
		else
			printf("%d %d %d\n", kra[i].first, kra[i].second, st[kra[i].first][kra[i].second]);
	}
	return 0;
}
#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
using namespace std;

int n, m;
int n1;
long long wys[2100007];
long long odl[2100007];
int lew[2100007];
int pra[2100007];
long long drzewonap[2100007];
long long drzewonal[2100007];
long long drzewoob[2100007];
long long wyn;
long long dop;
vector <int> wek;
int p1, p2;

int potenga(int v)
{
	for (int i=1; 1; i<<=1)
	if (i>=v)
	return i;
}

void rek(int v, int a, int b)
{
	pra[v]=b;
	lew[v]=a;
	if (a==b)
	{
		drzewonap[v]=drzewonal[v]=(wys[a]<<1);
		return;
	}
	rek(v<<1, a, (a+b)>>1);
	rek((v<<1)+1, ((a+b)>>1)+1, b);
	drzewoob[v]=max(drzewoob[v], drzewoob[v<<1]);
	drzewoob[v]=max(drzewoob[v], drzewoob[(v<<1)+1]);
	drzewoob[v]=max(drzewoob[v], drzewonap[v<<1]+drzewonal[(v<<1)+1]+odl[(a+b+2)>>1]-odl[(a+b)>>1]);
	
	drzewonal[v]=max(drzewonal[v<<1], drzewonal[(v<<1)+1]+odl[(a+b+2)>>1]-odl[a]);
	
	drzewonap[v]=max(drzewonap[(v<<1)+1], drzewonap[v<<1]+odl[b]-odl[(a+b)>>1]);
	
	//printf("%d  %d %d    %lld  %lld  %lld\n", v, a, b, drzewonal[v], drzewoob[v], drzewonap[v]);
}

void kol(int v, int a, int b, int graa, int grab)
{
	if (a>=graa && b<=grab)
	{
		wek.push_back(v);
		return;
	}
	if (a>grab || b<graa)
	{
		return;
	}
	kol(v<<1, a, (a+b)>>1, graa, grab);
	kol((v<<1)+1, (a+b+2)>>1, b, graa, grab);
}

int main()
{
	scanf("%d%d", &n, &m);
	n1=potenga(n<<1);
	for (int i=2; i<=n+1; i++)
	{
		scanf("%lld", &odl[i]);
		odl[i]+=odl[i-1];
	}
	for (int i=2; i<=n; i++)
	{
		odl[n+i]=odl[n+1]+odl[i];
	}
	//for (int i=1; i<=n*2; i++)
	//printf("%lld ", odl[i]);
	//printf("\n");
	for (int i=1; i<=n; i++)
	{
		scanf("%lld", &wys[i]);
		wys[n+i]=wys[i];
	}
	rek(1, 1, n1);
	while(m--)
	{
		wek.clear();
		scanf("%d%d", &p1, &p2);
		if (p1<=p2)
		{
			kol(1, 1, n1, p2+1, n+p1-1);
		}
		else
		{
			kol(1, 1, n1, p2+1, p1-1);
		}
		dop=drzewonap[wek[0]]+odl[pra[wek[0]]+1]-odl[pra[wek[0]]];
		wyn=drzewoob[wek[0]];
		for (int i=1; i<wek.size(); i++)
		{
			wyn=max(wyn, drzewoob[wek[i]]);
			wyn=max(wyn, dop+drzewonal[wek[i]]);
			dop=max(dop+odl[pra[wek[i]]]-odl[lew[wek[i]]], drzewonap[wek[i]]) +odl[pra[wek[i]]+1]-odl[pra[wek[i]]];
		}
		printf("%lld\n", wyn);
	}
	return 0;
}
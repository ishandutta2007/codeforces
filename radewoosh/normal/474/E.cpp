#include <iostream>
#include <cstdio>
#include <map>
#include <algorithm>
#include <vector>
using namespace std;

int n, m;
long long d;
long long tab[100007];
long long dos[100007];
map <long long,int> mapa;
int licz;
pair <int,int> drzewo[1000007];
int aktu;
pair <int,int> wyn[1000007];
int aa, bb;
long long pacz;
vector <int> scie;
int gdzie;

int potenga(int v)
{
	for (int i=1; 1; i*=2)
	{
		if (i>=v)
		{
			return i;
		}
	}
}

void pisz(int v, int ile, int pocz)
{
	v=v-1+m;
	while(v)
	{
		if (ile>drzewo[v].first)
		{
			drzewo[v].first=ile;
			drzewo[v].second=pocz;
		}
		v/=2;
	}
}

pair <int,int> czyt(int v, int a, int b, int graa, int grab)
{
	if (a>=graa && b<=grab)
	{
		return drzewo[v];
	}
	if (a>grab || b<graa)
	{
		return make_pair(0, 0);
	}
	return max(czyt(v*2, a, (a+b)/2, graa, grab), czyt(v*2+1, (a+b)/2+1, b, graa, grab));
}

int main()
{
	scanf("%d%lld", &n, &d);
	m=potenga(n);
	for (int i=1; i<=n; i++)
	{
		scanf("%lld", &tab[i]);
		dos[i]=tab[i];
		mapa[tab[i]]=0;
	}
	sort(dos+1, dos+1+n);
	dos[n+1]=1000;
	dos[n+1]*=1000;
	dos[n+1]*=1000;
	dos[n+1]*=1000;
	dos[n+1]*=1000;
	dos[n+1]*=1000;
	dos[0]=-dos[n+1];
	for (map <long long,int>::iterator it=mapa.begin(); it!=mapa.end(); it++)
	{
		licz++;
		mapa[it->first]=licz;
	}
	for (int i=1; i<=n; i++)
	{
		//printf("%d\n", i);
		aa=0;
		bb=n+1;
		pacz=tab[i]-d;
		while(aa!=bb)
		{
			if (dos[(aa+bb)/2+1]<=pacz)
			aa=(aa+bb)/2+1;
			else
			bb=(aa+bb)/2;
		}
		//printf("  %lld %d\n", dos[aa], mapa[dos[aa]]);
		if (aa)
		{
			wyn[i]=max(wyn[i], czyt(1, 1, m, 1, mapa[dos[aa]]));
		}
		aa=0;
		bb=n+1;
		pacz=tab[i]+d;
		while(aa!=bb)
		{
			if (dos[(aa+bb)/2]<pacz)
			aa=(aa+bb)/2+1;
			else
			bb=(aa+bb)/2;
		}
		//printf("  %lld %d\n", dos[aa], mapa[dos[aa]]);
		if (aa<=n)
		{
			wyn[i]=max(wyn[i], czyt(1, 1, m, mapa[dos[aa]], m));
		}
		wyn[i].first++;
		pisz(mapa[tab[i]], wyn[i].first, i);
		//for (int j=1; j<2*m; j++)
		//{
		//	printf("%d.%d ", drzewo[j].first, drzewo[j].second);
		//}
		//printf("\n");
	}
	for (int i=1; i<=n; i++)
	{
		//printf("%d %d %d\n", i, wyn[i].first, wyn[i].second);
		if (wyn[i].first>wyn[gdzie].first)
		{
			gdzie=i;
		}
	}
	printf("%d\n", wyn[gdzie].first);
	while(gdzie)
	{
		scie.push_back(gdzie);
		gdzie=wyn[gdzie].second;
	}
	while(!scie.empty())
	{
		printf("%d ", scie.back());
		scie.pop_back();
	}
	return 0;
}
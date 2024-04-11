#include <bits/stdc++.h>
using namespace std;

using pii=pair<int,int>;
const int nax=1000*1007;

int n, m;

pii kra[nax];

int ojf[nax];

int kol[nax];

int fin(int v)
{
	if (v!=ojf[v])
		ojf[v]=fin(ojf[v]);
	return ojf[v];
}

void uni(int a, int b)
{
	ojf[fin(a)]=fin(b);
}

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

void test()
{
	scanf("%d%d", &n, &m);
	for (int i=1; i<=m; i++)
	{
		int a, b;
		scanf("%d%d", &a, &b);
		kra[i]={a, b};
	}
	while(1)
	{
		for (int i=1; i<=m; i++)
			kol[i]=(rng()&2)/2;
		int li=0;
		for (int h=0; h<2; h++)
		{
			for (int i=1; i<=n; i++)
				ojf[i]=i;
			for (int i=1; i<=m; i++)
				if (kol[i]==h)
					uni(kra[i].first, kra[i].second);
			for (int i=1; i<=n; i++)
				if (ojf[i]==i)
					li++;
		}
		if (li==2*n-m)
		{
			for (int i=1; i<=m; i++)
				printf("%d", kol[i]);
			printf("\n");
			break;
		}
	}
}

int main()
{
	int t;
	scanf("%d", &t);
	while(t--)
		test();
	return 0;
}
#include <iostream>
#include <cstdio>
#include <vector>
using namespace std;

int n, m;
int n1;
int l[100007];
int r[100007];
int q[100007];
pair <int,int> drzewo[5000007];
int inf=1073741823;

int pot(int v)
{
	for (int i=1; 1; i*=2)
	{
		if (i>=v)
		{
			return i;
		}
	}
}

void pisz(int v, int a, int b, int graa, int grab, int val)
{
	if (a>=graa && b<=grab)
	{
		drzewo[v].first=drzewo[v].first|val;
		return;
	}
	if (a>grab || b<graa)
	{
		return;
	}
	pisz(v*2, a, (a+b)/2, graa, grab, val);
	pisz(v*2+1, (a+b)/2+1, b, graa, grab, val);
	drzewo[v].second=(drzewo[v*2].first | drzewo[v*2].second)&(drzewo[v*2+1].first | drzewo[v*2+1].second);
}

int czyt(int v, int a, int b, int graa, int grab)
{
	if (a>=graa && b<=grab)
	{
		return drzewo[v].first|drzewo[v].second;
	}
	if (a>grab || b<graa)
	{
		return inf;
	}
	return drzewo[v].first | (czyt(v*2, a, (a+b)/2, graa, grab)&czyt(v*2+1, (a+b)/2+1, b, graa, grab));
}

int main()
{
	scanf("%d%d", &n, &m);
	n1=pot(n);
	for (int i=1; i<=m; i++)
	{
		scanf("%d%d%d", &l[i], &r[i], &q[i]);
		pisz(1, 1, n1, l[i], r[i], q[i]);
	}
	for (int i=1; i<=m; i++)
	{
		if (czyt(1, 1, n1, l[i], r[i])!=q[i])
		{
			printf("NO");
			return 0;
		}
	}
	printf("YES\n");
	for (int i=1; i<=n; i++)
	{
		printf("%d ", czyt(1, 1, n1, i, i));
	}
	return 0;
}
#include <bits/stdc++.h>
using namespace std;

using pii=pair<int,int>;
const int nax=1007;

int n, m;

char wcz[nax];
int tab[nax][nax];

vector<vector<pii>> wyn;

void zrob(vector<pii> wek)
{
	wyn.push_back(wek);
	for (pii i : wek)
		tab[i.first][i.second]^=1;
}

void ogar(int i, int j)
{
	if (!tab[i][j])
		return;
	vector<pii> wek;
	wek.push_back({i, j});
	if (i+1<=n)
		wek.push_back({i+1, j});
	else
		wek.push_back({i-1, j+1});
	if (j+1<=m)
		wek.push_back({i, j+1});
	else
		wek.push_back({i+1, j-1});
	zrob(wek);
}

void test()
{
	scanf("%d%d", &n, &m);
	for (int i=1; i<=n; i++)
	{
		scanf("%s", wcz+1);
		for (int j=1; j<=m; j++)
			tab[i][j]=(wcz[j]-'0');
	}
	wyn.clear();
	for (int i=1; i+2<=n; i++)
		for (int j=1; j<=m; j++)
			ogar(i, j);
	for (int i=1; i+2<=m; i++)
	{
		ogar(n-1, i);
		ogar(n, i);
	}
	int ile=0;
	vector<pair<int,pii>> wek;
	for (int i=n-1; i<=n; i++)
	{
		for (int j=m-1; j<=m; j++)
		{
			ile^=tab[i][j];
			wek.push_back({tab[i][j], {i, j}});
		}
	}
	for (auto i : wek)
	{
		if (i.first==ile)
			continue;
		vector<pii> daj;
		for (auto j : wek)
		{
			if (j==i)
				continue;
			daj.push_back(j.second);
		}
		zrob(daj);
	}
	printf("%d\n", (int)wyn.size());
	for (auto i : wyn)
	{
		for (pii j : i)
			printf("%d %d ", j.first, j.second);
		printf("\n");
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
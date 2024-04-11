#include <bits/stdc++.h>
using namespace std;

int n;
int tab[1007];

int czy[1007][1007];

int wyn;

int zx[]={0,1,1,1,0,-1,-1,-1};
int zy[]={1,1,0,-1,-1,-1,0,1};

vector < pair <  pair <int,int> , int> > wek;
vector < pair <  pair <int,int> , int> > now;

int main()
{
	scanf("%d", &n);
	for (int i=1; i<=n; i++)
		scanf("%d", &tab[i]);
	wek.push_back({{500, 500}, 0});
	for (int i=1; i<=n; i++)
	{
		for (int j=1; j<=tab[i]; j++)
		{
			for (int l=0; l<wek.size(); l++)
			{
				wek[l].first.first+=zx[wek[l].second];
				wek[l].first.second+=zy[wek[l].second];
				czy[wek[l].first.first][wek[l].first.second]=1;
			}
		}
		now.clear();
		for (int j=0; j<wek.size(); j++)
		{
			now.push_back(wek[j]);
			now.back().second+=1;
			now.back().second%=8;
			now.push_back(wek[j]);
			now.back().second+=7;
			now.back().second%=8;
		}
		wek.clear();
		sort(now.begin(), now.end());
		for (int j=0; j<now.size(); j++)
			if (!j || now[j]!=now[j-1])
				wek.push_back(now[j]);
	}
	for (int i=0; i<=1000; i++)
		for (int j=0; j<=1000; j++)
			wyn+=czy[i][j];
	printf("%d\n", wyn);
	return 0;
}
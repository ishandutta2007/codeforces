#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

int n;
int pom;
int czy[2000007];
int ost;
int sito[2000007];
vector <pair <int,int> > wek;
vector <int> dzie;
int co;
int wyn;

void roz(int v)
{
	wek.clear();
	while(v>1)
	{
		if (!sito[v])
		{
			if (wek.empty() || wek.back().first!=v)
			wek.push_back(make_pair(v, 1));
			else
			wek[wek.size()-1].second++;
			break;
		}
		if (wek.empty() || wek.back().first!=sito[v])
		wek.push_back(make_pair(sito[v], 1));
		else
		wek[wek.size()-1].second++;
		v/=sito[v];
	}
}

void roz2(int v)
{
	if (v==wek.size())
	{
		dzie.push_back(co);
		return;
	}
	int a=1;
	roz2(v+1);
	for (int i=1; i<=wek[v].second; i++)
	{
		a*=wek[v].first;
		co*=a;
		roz2(v+1);
		co/=a;
	}
}

int main()
{
	for (int i=2; i*i<=2000000; i++)
	{
		if (!sito[i])
		{
			for (int j=i*i; j<=2000000; j+=i)
			{
				if (!sito[j])
				sito[j]=i;
			}
		}
	}
	scanf("%d", &n);
	for (int i=1; i<=n; i++)
	{
		scanf("%d", &pom);
		czy[pom]=1;
	}
	for (int i=1; i<=2000000; i++)
	{
		roz(i);
		dzie.clear();
		co=1;
		roz2(0);
		for (int j=1; j<dzie.size()-1; j++)
		{
			if (czy[dzie[j]])
			{
				wyn=max(wyn, ost-(i-dzie[j]));
			}
		}
		if (czy[i])
		ost=i;
	}
	printf("%d", wyn);
	return 0;
}
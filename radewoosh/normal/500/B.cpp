#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <queue>
#include <stack>
#include <deque>
#include <cmath>
#include <set>
#include <map>
using namespace std;

int n;
int per[307];
int oj[307];
string slo;

int find(int x)
{
	if (oj[x]!=x)
	oj[x]=find(oj[x]);
	return oj[x];
}

void uni(int a, int b)
{
	if (find(a)!=find(b))
	oj[find(b)]=find(a);
}

int wyn[307];
vector <int> poz;
vector <int> licz;

int main()
{
	cin >> n;
	for (int i=1; i<=n; i++)
	{
		cin >> per[i];
		oj[i]=i;
	}
	for (int i=1; i<=n; i++)
	{
		cin >> slo;
		for (int j=1; j<=n; j++)
		{
			if(slo[j-1]=='1')
			{
				uni(i, j);
			}
		}
	}
	for (int i=1; i<=n; i++)
	{
		if (find(i)==i)
		{
			poz.clear();
			licz.clear();
			for (int j=1; j<=n; j++)
			{
				if (find(j)==i)
				{
					poz.push_back(j);
					licz.push_back(per[j]);
				}
			}
			sort(licz.begin(), licz.end());
			for (int j=0; j<licz.size(); j++)
			{
				wyn[poz[j]]=licz[j];
			}
		}
	}
	for (int i=1; i<=n; i++)
	{
		printf("%d ", wyn[i]);
	}
	return 0;
}
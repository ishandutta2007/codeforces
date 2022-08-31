#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <queue>
#include <deque>
#include <set>
#include <map>
using namespace std;

int n, m;
string tab[1007];
int czy[1007];
int zab;
int wyn;

int main()
{
	cin >> n >> m;
	for (int i=1; i<=n; i++)
	{
		cin >> tab[i];
		czy[i]=1;
	}
	for (int i=0; i<m; i++)
	{
		zab=0;
		for (int j=1; j<n; j++)
		{
			if (czy[j] && tab[j][i]>tab[j+1][i])
			{
				zab=1;
				break;
			}
		}
		if (zab)
		{
			wyn++;
		}
		else
		{
			for (int j=1; j<n; j++)
			{
				if (tab[j][i]<tab[j+1][i])
				{
					czy[j]=0;
				}
			}
		}
	}
	printf("%d", wyn);
	return 0;
}
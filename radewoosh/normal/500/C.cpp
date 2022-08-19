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

int n, m;
int wag[507];
int czyn[1007];
int stos[507];
int czy[507];
int wyn;

int main()
{
	scanf("%d%d", &n, &m);
	for (int i=1; i<=n; i++)
	{
		scanf("%d", &wag[i]);
	}
	for (int i=1; i<=m; i++)
	{
		scanf("%d", &czyn[i]);
		if (!czy[czyn[i]])
		{
			czy[czyn[i]]=1;
			for (int j=1; 1; j++)
			{
				if (!stos[j])
				{
					stos[j]=czyn[i];
					break;
				}
			}
		}
	}
	for (int i=1; i<=m; i++)
	{
		for (int j=1; j<=n; j++)
		{
			if (stos[j]==czyn[i])
			{
				for (int k=j-1; k; k--)
				{
					stos[k+1]=stos[k];
					wyn+=wag[stos[k]];
				}
				stos[1]=czyn[i];
				break;
			}
		}
	}
	printf("%d", wyn);
	return 0;
}
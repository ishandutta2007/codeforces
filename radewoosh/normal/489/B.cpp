#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

int n, m;
vector <int> ch;
vector <int> dz;
int p;
int wyn;

int bez(int a, int b)
{
	return max(a-b, b-a);
}

int main()
{
	scanf("%d", &n);
	for (int i=1; i<=n; i++)
	{
		scanf("%d", &p);
		ch.push_back(p);
	}
	scanf("%d", &m);
	for (int i=1; i<=m; i++)
	{
		scanf("%d", &p);
		dz.push_back(p);
	}
	sort(ch.begin(), ch.end());
	sort(dz.begin(), dz.end());
	while(!ch.empty() && !dz.empty())
	{
		if (bez(ch.back(), dz.back())<=1)
		{
			wyn++;
			ch.pop_back();
			dz.pop_back();
		}
		else
		{
			if (ch.back()>dz.back())
			{
				ch.pop_back();
			}
			else
			{
				dz.pop_back();
			}
		}
	}
	printf("%d", wyn);
	return 0;
}
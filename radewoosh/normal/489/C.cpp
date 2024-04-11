#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

int n, m;
int ile;
vector <int> wek;
bool czy;

int main()
{
	scanf("%d%d", &n, &m);
	if (n==1 && !m)
	{
		printf("0 0");
		return 0;
	}
	if (!m)
	{
		printf("-1 -1");
		return 0;
	}
	ile=m;
	for (int i=1; i<=n; i++)
	{
		wek.push_back(min(ile, 9));
		ile-=min(ile, 9);
	}
	if (ile)
	{
		printf("-1 -1");
		return 0;
	}
	for (int i=n-1; i>=0; i--)
	{
		if (i==n-1 && !wek[i])
		{
			czy=true;
			printf("1");
			continue;
		}
		if (czy && wek[i])
		{
			czy=false;
			printf("%d", wek[i]-1);
			continue;
		}
		printf("%d", wek[i]);
	}
	printf(" ");
	for (int i=0; i<n; i++)
	{
		printf("%d", wek[i]);
	}
	return 0;
}
#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

int n;
vector <int> wek[5];
int p;

int main()
{
	scanf("%d", &n);
	for (int i=1; i<=n; i++)
	{
		scanf("%d", &p);
		wek[p].push_back(i);
	}
	printf("%d\n", min(wek[1].size(), min(wek[2].size(), wek[3].size())));
	while(!wek[1].empty() && !wek[2].empty() && !wek[3].empty())
	{
		printf("%d %d %d\n", wek[1].back(), wek[2].back(), wek[3].back());
		wek[1].pop_back();
		wek[2].pop_back();
		wek[3].pop_back();
	}
	return 0;
}
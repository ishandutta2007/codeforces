#include <iostream>
#include <cstdio>
using namespace std;

int n;
char tab[1000007];

int ile[1007];
int wyn;

int main()
{
	scanf("%d", &n);
	scanf("%s", &tab);
	for (int i=0; i<n-1; i++)
	{
		ile[tab[i<<1]]++;
		tab[(i<<1)+1]+='a'-'A';
		if (!ile[tab[(i<<1)+1]])
		{
			wyn++;
			ile[tab[(i<<1)+1]]++;
		}
		ile[tab[(i<<1)+1]]--;
	}
	printf("%d", wyn);
	return 0;
}
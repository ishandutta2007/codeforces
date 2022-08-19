#include <iostream>
#include <cstdio>
using namespace std;

int n;
int co[1000007];
int ost;
int a;

int main()
{
	scanf("%d", &n);
	for (int i=1; i<=n; i++)
	{
		scanf("%d", &a);
		for (int j=1; j<=a; j++)
		{
			ost++;
			co[ost]=i;
		}
	}
	scanf("%d", &n);
	for (int i=1; i<=n; i++)
	{
		scanf("%d", &a);
		printf("%d\n", co[a]);
	}
	return 0;
}
#include <iostream>
#include <cstdio>
using namespace std;

int n;
bool sito[1000007];

int main()
{
	scanf("%d", &n);
	for (int i=2; i*i<=n; i++)
	{
		if (!sito[i])
		{
			for (int j=2*i; j<=n; j+=i)
			sito[j]=1;
		}
	}
	for (int i=2; i<=n; i++)
	{
		if (sito[i] && sito[n-i])
		{
			printf("%d %d", i, n-i);
			return 0;
		}
	}
	return 0;
}
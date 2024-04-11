#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
using namespace std;

int n;
long long tab[500007];
long long sum;
long long aktu;
long long ilpre[500007];
long long ilsuf[500007];
long long wyn;

int main()
{
	scanf("%d", &n);
	for (int i=1; i<=n; i++)
	{
		scanf("%lld", &tab[i]);
		sum+=tab[i];
	}
	if (sum%3)
	{
		printf("0");
		return 0;
	}
	sum/=3;
	for (int i=n; i; i--)
	{
		ilsuf[i]=ilsuf[i+1];
		aktu+=tab[i];
		if (aktu==sum)
		{
			ilsuf[i]++;
		}
	}
	aktu=0;
	for (int i=1; i<=n; i++)
	{
		aktu+=tab[i];
		if (aktu==sum)
		{
			wyn+=ilsuf[i+2];
		}
	}
	printf("%lld", wyn);
	return 0;
}
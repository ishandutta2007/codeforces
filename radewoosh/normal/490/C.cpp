#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <map>
using namespace std;

int n;
string slo;
long long a, b;
long long aktu;
int lew[1000007];
int pra[1000007];
long long dom=1;

int main()
{
	cin >> slo;
	cin >> a >> b;
	n=slo.size();
	for (int i=1; i<=n; i++)
	{
		aktu*=10;
		aktu+=slo[i-1]-'0';
		aktu%=a;
		if (!aktu)
		{
			lew[i]=1;
		}
	}
	aktu=0;
	for (int i=n; i; i--)
	{
		aktu+=dom*(slo[i-1]-'0');
		aktu%=b;
		if (!aktu && slo[i-1]!='0')
		pra[i]=1;
		dom*=10;
		dom%=b;
	}
	for (int i=1; i<n; i++)
	{
		if (lew[i] && pra[i+1])
		{
			printf("YES\n");
			for (int j=1; j<=i; j++)
			printf("%c", slo[j-1]);
			printf("\n");
			for (int j=i+1; j<=n; j++)
			printf("%c", slo[j-1]);
			return 0;
		}
	}
	printf("NO");
	return 0;
}
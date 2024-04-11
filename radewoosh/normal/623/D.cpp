#include <bits/stdc++.h>
using namespace std;

int n;

int x;

double tab[107];

double aktu;
double nie[107];

double wyn;

double kan;
int id;

double ost;

int main()
{
	scanf("%d", &n);
	for (int i=1; i<=n; i++)
	{
		scanf("%d", &x);
		tab[i]=x/100.0;
		nie[i]=1.0;
	}
	for (int h=1; h<=500000; h++)
	{
		ost=aktu;
		aktu=1.0;
		for (int i=1; i<=n; i++)
		{
			aktu*=(1.0-nie[i]);
		}
		wyn+=(aktu-ost)*(h-1);
		id=0;
		kan=0.0;
		for (int i=1; i<=n; i++)
		{
			if (nie[i]==1.0)
			{
				id=i;
				break;
			}
			if (aktu/(1.0-nie[i])*(1.0-(nie[i]*(1-tab[i])))>kan)
			{
				kan=aktu/(1.0-nie[i])*(1.0-(nie[i]*(1-tab[i])));
				id=i;
			}
		}
		nie[id]*=(1.0-tab[id]);
	}
	printf("%.9lf\n", wyn);
	return 0;
}
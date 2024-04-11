#include <iostream>
#include <cstdio>
#include <vector>
using namespace std;

int n;
long long l, r;
vector <long long> wek;
long long pot[100];
int m;
bool czy;

void roz(long long v)
{
	wek.clear();
	while(v)
	{
		wek.push_back(v%2);
		v/=2;
	}
}

int main()
{
	scanf("%d", &n);
	while(n--)
	{
		scanf("%lld%lld", &l, &r);
		if (l==r)
		{
			printf("%lld\n", r);
			continue;
		}
		roz(r);
		pot[0]=1;
		m=0;
		czy=false;
		for (int i=1; i<wek.size(); i++)
		{
			pot[i]=pot[i-1]*2;
		}
		for (int i=0; i<wek.size(); i++)
		{
			//printf("%lld ", wek[i]);
			if (!wek[i])
			{
				czy=true;
			}
			if (czy && wek[i] && ((r-pot[i])|(pot[i]-1))>=l)
			{
				m=i;
			}
		}
		//printf("\n");
		//printf("%d\n", m);
		if (!m)
		{
			printf("%lld\n", r);
			continue;
		}
		r-=pot[m];
		r=r|(pot[m]-1);
		printf("%lld\n", r);
	}
	return 0;
}
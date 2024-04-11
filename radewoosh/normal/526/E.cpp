#include <iostream>
#include <cstdio>
#include <deque>
#include <algorithm>
using namespace std;

long long n, s;
long long l[1000007];
long long d;
long long maxi;
long long dlu;
long long it;
long long dokad[1000007];
long long bylo[1000007];
deque <pair<long long,long long> > road;
long long wyn;
long long drog;
long long prog;
long long gdzie;
long long cel;

long long od(long long v1, long long v2)
{
	if (v1<v2)
	return l[v2]-l[v1];
	else
	return dlu-l[v1]+l[v2];
}

int main()
{
	scanf("%lld%lld", &n, &s);
	for (long long i=1; i<=n; i++)
	{
		scanf("%d", &l[i]);
		maxi=max(maxi, l[i]);
		dlu+=l[i];
		l[i]+=l[i-1];
	}
	for (long long h=1; h<=s; h++)
	{
		scanf("%lld", &d);
		if (d>=dlu)
		{
			printf("1\n");
			continue;
		}
		it=2;
		cel=3;
		for (long long i=1; i<=n; i++)
		{
			while(cel!=i && od(i, cel)<=d)
			{
				it=cel;
				cel=(it%n)+1;
			}
			dokad[i]=it;
		}
		road.clear();
		road.push_front(make_pair(1, 0));
		wyn=n;
		drog=0;
		prog=(dlu+d-1)/d;
		while(1)
		{
			gdzie=road.front().first;
			if (drog>=dlu)
			{
				while(drog-road.back().second>=dlu)
				{
					drog-=road.back().second;
					road.pop_back();
				}
				if (road.size()-1<wyn)
				wyn=road.size()-1;
				if (wyn==prog)
				break;
			}
			if (bylo[gdzie]==h)
			break;
			bylo[gdzie]=h;
			road.front().second=od(gdzie, dokad[gdzie]);
			drog+=road.front().second;
			road.push_front(make_pair(dokad[gdzie], 0));
		}
		printf("%lld\n", wyn);
	}
	return 0;
}
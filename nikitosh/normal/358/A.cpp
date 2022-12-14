#include<cstdio>
#include<iostream>
#include<algorithm>
#include<cmath>
#include<vector>
#include<set>
#include<map>
#include<cstring>
#include<string>
#include<cstdlib>
#include<ctime>
#include<cassert>

using namespace std;

#define FNAME ""
#define FILE 0

#define pb push_back
#define mp make_pair
#define LL long long
#define ULL unsigned long long
#define LD long double

#ifdef WIN32
	#define I64 "%I64d"
#else
	#define I64 "%lld"
#endif

int n, a[1005], sz;
vector < pair <int, int> > v;

int main()
{
	#if (FILE == 1)
	freopen(FNAME".in", "r", stdin);
	freopen(FNAME".out", "w", stdout);
	#endif
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
		scanf("%d", &a[i]);
	for (int i = 1; i < n; i++)
	{
		int k1 = a[i - 1], k2 = a[i];
		if (k1 > k2)
			swap(k1, k2);
		v.pb(mp(k1, k2));
	}
	sz = (int) v.size();
	for (int i = 0; i < sz; i++)
		for (int j = i + 2; j < sz; j++)
		{                   
			if (v[i].first < v[j].first && v[i].second < v[j].second && v[i].second > v[j].first)
			{
				puts("yes");
				return 0;
			}
			if (v[j].first < v[i].first && v[j].second < v[i].second && v[j].second > v[i].first)
			{
				puts("yes");
				return 0;
			}
		}	
	puts("no");
	return 0;
}
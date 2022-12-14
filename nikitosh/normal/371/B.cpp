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

int a, b, a1, b1, boo1[10], boo2[10], ans;
vector <int> c1, c2, d1, d2;

int main()
{
	#if (FILE == 1)
	freopen(FNAME".in", "r", stdin);
	freopen(FNAME".out", "w", stdout);
	#endif
	scanf("%d%d", &a, &b);
	a1 = a;
	b1 = b;
	for (int i = 2; i * i <= a1; i++)
		while (a1 % i == 0)
		{
			c1.pb(i);  
			a1 /= i;
		}
	if (a1 != 1)
		c1.pb(a1);
	for (int i = 2; i * i <= b1; i++)
		while (b1 % i == 0)
		{
			c2.pb(i);  
			b1 /= i;
		}
	if (b1 != 1)
		c2.pb(b1);
	sort(c1.begin(), c1.end());
	sort(c2.begin(), c2.end());
	for (int i = 0; i < (int) c1.size(); i++)
		if (c1[i] > 5)
			d1.pb(c1[i]);
		else
			boo1[c1[i]]++;
	for (int i = 0; i < (int) c2.size(); i++)
		if (c2[i] > 5)
			d2.pb(c2[i]);
		else
			boo2[c2[i]]++;
	if (d1 != d2)
	{
		puts("-1");
		return 0;
	}
	ans = abs(boo1[2] - boo2[2]) + abs(boo1[3] - boo2[3]) + abs(boo1[5] - boo2[5]);
	printf("%d\n", ans);
	return 0;
}
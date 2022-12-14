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

char s[205];
int a[10], n[10], p[10], l[10], len, sum, cnt, boo;
long long ans, r;

int main()
{
	#if (FILE == 1)
	freopen(FNAME".in", "r", stdin);
	freopen(FNAME".out", "w", stdout);
	#endif
	gets(s);
	len = strlen(s);
	for (int i = 0; i < len; i++)
	{
		if (s[i] == 'B')
			a[0]++;
		if (s[i] == 'S')
			a[1]++;
		if (s[i] == 'C')
			a[2]++;
	}
	scanf("%d%d%d", &n[0], &n[1], &n[2]);
	scanf("%d%d%d", &p[0], &p[1], &p[2]);
	scanf("%I64d", &r);
	while (n[0] >= a[0] && n[1] >= a[1] && n[2] >= a[2])
	{
		ans++;
		for (int i = 0; i < 3; i++)
			n[i] -= a[i];
	}
	while(1)
	{
		sum = 0;
		for (int i = 0; i < 3; i++)
		{
		    l[i] = 0;
			if (a[i] > n[i])
			{
				l[i] = (a[i] - n[i]) * p[i];
				n[i] = 0;
			}
			else
				n[i] -= a[i];
			sum += l[i];
		}
		if (r >= sum)
		{
			r -= sum;
			ans++;
		}
		else
			break;
		boo = 0;
		for (int i = 0; i < 3; i++)
			if (n[i] != 0 && a[i] != 0)
	    	   	boo = 1;
		if (boo == 0)
			break;
	}
	cnt = a[0] * p[0] + a[1] * p[1] + a[2] * p[2];
	ans += r / cnt;
	printf("%I64d\n", ans);		
	return 0;
}
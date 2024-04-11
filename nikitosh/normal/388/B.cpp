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

int k, used[100], l, max1, cnt, a[3005][3005], ten[100], l2;
vector <int> c[5005];

int main()
{
	#if (FILE == 1)
	freopen(FNAME".in", "r", stdin);
	freopen(FNAME".out", "w", stdout);
	#endif
	scanf("%d", &k);
	ten[0] = 1;
	for (int i = 1; i < 10; i++)
		ten[i] = ten[i - 1] * 10;
	for (int i = 9; i >= 0; i--)
		if (ten[i] <= k)
		{
			used[i] = k / ten[i];
			k -= used[i] * ten[i];
		}
	for (int i = 9; i >= 0; i--)
		if (used[i])
		{
			l = i;
			break;
		}
	max1 = 2 * l + 3;
	cnt = 3;
	for (int i = 9; i >= 0; i--)
	{
		if (used[i] > 0)
		{   	
		    l = cnt++;
		    for (int t = 0; t < used[i]; t++)
		    {
		    	c[1].pb(cnt++);
		    	c[l].pb(cnt - 1);
		    }
		    for (int j = 0; j < i; j++)
		    {
		    	l2 = cnt++;
			    for (int t = 0; t < 10; t++)
			    {
			    	c[l].pb(cnt++);
			    	c[l2].pb(cnt - 1);
		    	}
		    	l = l2;
		    }
		    for (int j = 0; j < max1 - 2 * i - 3; j++)
			{				
				c[l].pb(cnt++);			    	
				l = cnt - 1;
			}
			c[l].pb(2);
		}
	}
	printf("%d\n", cnt - 1);
	for (int i = 1; i < cnt; i++)
		for (int j = 0; j < (int) c[i].size(); j++)
			a[i][c[i][j]] = a[c[i][j]][i] = 1;
	for (int i = 1; i < cnt; i++)
	{
		for (int j = 1; j < cnt; j++)
			if (a[i][j] == 1)
				printf("Y");
			else
				printf("N");
		puts("");
	}
	return 0;
}
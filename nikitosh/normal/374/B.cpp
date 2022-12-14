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

int l1, k, n, a[200005];
unsigned long long ans = 1;
char s[200005];

int main()
{
	#if (FILE == 1)
	freopen(FNAME".in", "r", stdin);
	freopen(FNAME".out", "w", stdout);
	#endif
	gets(s);
	n = strlen(s);
	for (int i = 0; i < n; i++)
		a[i] = s[i] - '0';
	l1 = 0;
	a[n] = -10;
	while(l1 < n - 1)
	{
		if (a[l1] + a[l1 + 1] != 9)
		{
			l1++;
			continue;
		}
		k = n;
		for (int i = l1 + 2; i < n; i++)
			if (a[i] != a[i - 2])
			{
				k = i;
				break;
			}
		if ((k - l1) % 2 == 1)
			ans = ans * (long long) ((k - l1 + 1) / 2);
		l1 = k;	
	}
	cout << ans << endl;
	 
	return 0;
}
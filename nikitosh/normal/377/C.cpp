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

const int INF = (int) 1e9;

int n, m, t[105], a[105], c[105], f[3000005];
char ch[105];

int cnt (int x)
{
	int ans = 0;
	while (x > 0)
	{
		ans += (x % 2);
		x /= 2;
	}
	return ans;
}

int main()
{
	#if (FILE == 1)
	freopen(FNAME".in", "r", stdin);
	freopen(FNAME".out", "w", stdout);
	#endif
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
		scanf("%d", &a[i]);
	sort(a, a + n);
	reverse(a, a + n);
	scanf("%d\n", &m);
	for (int i = 0; i < m; i++)
	{
		scanf("%c%d\n", &ch[i], &t[i]);
		if (ch[i] == 'p')
			c[i] = 1;
		else
			c[i] = 0;
	}	
	for (int i = (1 << m) - 2; i >= 0; i--)
	{
		int l = cnt(i);
		if (t[l] == 1)
		{
		    f[i] = -INF;
		    for (int j = 0; j < m; j++)
				if (!(i & (1 << j)))
					f[i] = max(f[i], f[i + (1 << j)] + a[j] * c[l]);
		}	
		else
		{
		    f[i] = INF;
		    for (int j = 0; j < m; j++)
				if (!(i & (1 << j)))
					f[i] = min(f[i], f[i + (1 << j)] - a[j] * c[l]);
		}	
	}
	printf("%d\n", f[0]);
	return 0;
}
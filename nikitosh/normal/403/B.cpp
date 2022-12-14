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

int n, m, a[10005], b[10005], g[10005], sum;
set <int> s;

int gcd (int k, int l)
{
	if (l == 0)
		return k;
	else
		return gcd(l, k % l);
}

int good (int k)
{
	vector <int> v;
	for (int i = 2; i * i <= k; i++)
	{
	 	while (k % i == 0)
	 	{
	 		v.pb(i);
	 		k /= i;
	   	}
	}
	if (k != 1)
		v.pb(k);
	int res = 0;
	//printf("k = %d\n", k);
	for (int i = 0; i < (int) v.size(); i++)
	{
		if (s.count(v[i]))
			res--;
		else
			res++;
		//printf("%d\n", v[i]);
	}
	//printf
	return res;
}

int main()
{
	#if (FILE == 1)
	freopen(FNAME".in", "r", stdin);
	freopen(FNAME".out", "w", stdout);
	#endif
	scanf("%d%d", &n, &m);
	for (int i = 0; i < n; i++)
		scanf("%d", &a[i]);
	for (int i = 0; i < m; i++)
	{
		scanf("%d", &b[i]);
   		s.insert(b[i]);
   	}
   	g[0] = a[0];
   	for (int i = 1; i < n; i++)
   	{
		g[i] = gcd(g[i - 1], a[i]);   		
   	}
   	for (int i = n - 1; i >= 0; i--)
   	{
   		if (good(g[i]) < 0)
		{
			for (int j = 0; j < i; j++)
			{
				g[j] /= g[i];
				a[j] /= g[i];
			}
			a[i] /= g[i];
   		}	
   	}
   	for (int i = 0; i < n; i++)
   	{
   		sum += good(a[i]);
   	}
	printf("%d\n", sum);
	return 0;
}
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

#define FNAME "1"
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

int n, a[100005], k, l, used[100005];
long long sum, d[100005], p[100005];
vector <int> c[100005];

long long gcd (long long k, long long l)
{
	if (l == 0)
		return k;
	return gcd(l, k % l);
}

void dfs (int v)
{
	used[v] = 1;
	if ((int) c[v].size() == 1 && v != 0)
	{
		p[v] = 1;
		d[v] = a[v];
		return;
	}
	long long l = 1, min1 = (long long) 1e18;
	for (int i = 0; i < (int) c[v].size(); i++)
		if (used[c[v][i]] == 0)
		{
			dfs(c[v][i]);
			long long t = p[c[v][i]] / gcd(l, p[c[v][i]]);
			if ((long long) 1e18 / l < t)
			{                          
			    printf("%I64d\n", sum);
				exit(0);
			}
			l *= t;
			if (l > (long long) 1e18)
			{
			    printf("%I64d\n", sum);
				exit(0);	
			}
			min1 = min(min1, d[c[v][i]]);
		}
	int q = (int) c[v].size() - 1;
	if (v == 0)
	 	q++;
	d[v] = min1 / l * l * q;
	if ((long long) 1e18 / l < q)
	{                          
		printf("%I64d\n", sum);
		exit(0);
	}
	l *= q;
	p[v] = l;
	if (l > (long long) 1e18)
	{
	    printf("%I64d\n", sum);
		exit(0);
	}
}

int main()
{
	#if (FILE == 1)
	freopen(FNAME".in", "r", stdin);
	freopen(FNAME".out", "w", stdout);
	#endif
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
	{
		scanf("%d", &a[i]);
		sum += a[i];
	}
	for (int i = 1; i < n; i++)
	{
		scanf("%d%d", &k, &l);
		k--;
		l--;
		c[k].push_back(l);
		c[l].push_back(k);
	}
	dfs(0);
	//for (int i = 0; i < n; i++)
	//	printf("i = %d %I64d %I64d\n", i, d[i], p[i]);         
	printf("%I64d\n", sum - d[0]);
	return 0;
}
#include <bits/stdc++.h> 

using namespace std;
 
#define sz(c) (int)(c).size()
 
#define pb push_back
#define mp make_pair
#define fs first
#define sc second
 
#define forn(i,n) for( int i = 0 ; i < (n) ; i++ )
#define forit(it,c) for( __typeof((c).begin()) it = (c).begin() ; it != (c).end() ; it++ )
 
typedef long long LL;
typedef unsigned long long ULL;
typedef long double LD;
typedef unsigned int uint;

#ifdef WIN32
#define INT64 "%I64d"
#else
#define INT64 "%lld"
#endif

#define FNAME "1"

int n, m, k, K, Log[100005], a[100005][6], SP[5][100005][20], L, R, M;

int MAX (int l, int r)
{
	int len = r - l + 1;
	int k = Log[len];
	int res = 0;
	//printf("k = %d %d %d\n", k, l, r);
	for (int j = 0; j < m; j++)
		res += max(SP[j][l][k], SP[j][r - (1 << k) + 1][k]);
	return res;	
}

int check (int M)
{
	for (int i = 0; i < n - M + 1; i++)
	{
	    int res = MAX(i, i + M - 1);
		//printf("%d %d %d\n", M, res, i);
		if (res <= K)
			return 1;
	}		 
	return 0;
}

int main()
{
    //freopen(FNAME".in", "r", stdin);
    //freopen(FNAME".out", "w", stdout); 
   	scanf("%d%d%d", &n, &m, &K);
   	for (int i = 1; i <= 100000; i++)
   	{
   		k = i;
   		while (k > 1)
   		{
   			k >>= 1;
   			Log[i]++;
   		}
   	}
   	for (int i = 0; i < n; i++)
   		for (int j = 0; j < m; j++)
   			scanf("%d", &a[i][j]);
   	for (int j = 0; j < m; j++)
   	{
   		for (int i = 0; i < n; i++)
   			SP[j][i][0] = a[i][j];
   		for (int g = 1; g < 20; g++)
   			for (int i = 0; i < n; i++)
   			{
   				if (i + (1 << g) > n)
   					break;
   				SP[j][i][g] = max(SP[j][i][g - 1], SP[j][i + (1 << (g - 1))][g - 1]);
   			}
   	}
   	L = 0;
   	R = n + 1;
   	while (R - L > 1)
   	{
   		M = (L + R) / 2;
   		if (check(M))
   			L = M;
   		else
   			R = M;
   		//printf("%d %d\n", L, R);
   	}
   	//printf("%d\n", L);
   	int ind = -1, max1 = -1;
	for (int i = 0; i < n - L + 1; i++)
		if (MAX(i, i + L - 1) > max1 && MAX(i, i + L - 1) <= K)
		{
			max1 = MAX(i, i + L - 1);
			ind = i;	
		} 
	int len = L;
	int k = Log[len];
	for (int j = 0; j < m; j++)
		printf("%d ", max(SP[j][ind][k], SP[j][ind + L - 1 - (1 << k) + 1][k]));
    return 0;
}
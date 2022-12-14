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

int N, v, x, y, jump[30][1500005], h[1500005], m1, m2, d, q, l;

int lca (int v, int u)
{
	if (h[v] < h[u])
		swap(v, u);
	int s = h[v] - h[u];
	for (int i = 25; i >= 0; i--)
		if (s >= (1 << i))
		{
			v = jump[i][v];
			s -= (1 << i);
		}
	if (u == v)
		return v;
	for (int i = 25; i >= 0; i--)
		if (jump[i][v] != jump[i][u])
		{
			v = jump[i][v];
			u = jump[i][u];
		}
	return jump[0][u];
}

int main()
{
	#if (FILE == 1)
	freopen(FNAME".in", "r", stdin);
	freopen(FNAME".out", "w", stdout);
	#endif
	scanf("%d", &q);
	x = 3;
    y = 2;
	d = 2;
	h[2] = h[3] = h[4] = 1;
	for (int i = 0; i <= 25; i++)
	    for (int j = 1; j < 5; j++)
			jump[i][j] = 1;
	l = 4;
	for (int g = 0; g < q; g++)
	{
        scanf("%d", &v);
		l++; 
		h[l] = h[v] + 1;
		jump[0][l] = v;
		for (int i = 1; i <= 25; i++)
			jump[i][l] = jump[i - 1][jump[i - 1][l]];
		m1 = h[l] + h[x] - 2 * h[lca(x, l)];
		m2 = h[l] + h[y] - 2 * h[lca(y, l)];
		if (m1 > d && m1 >= m2)
		{
			d = m1;
			y = l;                    
	   	}
		if (m2 > d && m2 > m1)
		{
			d = m2;
			x = l;
	   	}
	   	l++; 
		h[l] = h[v] + 1;
		jump[0][l] = v;
		for (int i = 1; i <= 25; i++)
			jump[i][l] = jump[i - 1][jump[i - 1][l]];
		printf("%d\n", d);
	}
    return 0;
}
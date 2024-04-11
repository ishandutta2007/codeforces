#include <stdio.h>
#include <bits/stdc++.h>
#define il inline

using namespace std;

const int N = 210 , M = 310;

const int MOD = 10007;
il int add(int x , int y) {return x + y >= MOD ? x + y - MOD : x + y;}
il int sub(int x , int y) {return x < y ? x + MOD - y : x - y;}
il int mul(int x , int y) {return x * y % MOD;} 
il int ceil(int x) {return (x >> 1) + (x & 1);}

int n , m , k;
char s[N];

int v[N][N][N];
int h[N][N][N];

inline void mul(int f[M], int g[M][M])
{
	int a[M]; memset(a , 0 , sizeof a);
	for (int j = 1; j <= k; j++)
		for (int i = 1; i <= k; i++)
			a[i] = add(a[i] , mul(f[j] , g[j][i]));
	for (int i = 1; i <= k; i++)
		f[i] = a[i];
}

inline void mul(int g[M][M]) {
	int a[M][M]; memset(a , 0 , sizeof a);
	for (int i = 1; i <= k; i++)
		for (int l = i; l <= k; l++)
			for (int j = l; j <= k; j++)
				a[i][j] = add(a[i][j] , mul(g[i][l] , g[l][j]));
	for (int i = 1; i <= k; i++)
		for (int j = 1; j <= k; j++)
			g[i][j] = a[i][j];
}

int f[M] , g[M][M];
int F[M] , G[M][M];

int H(int t , int l , int r)
{
	if(t < 0)
		return 0;
	if(l == 1 && r == m)
		return (t == 0);
	if(v[t][l][r])
		return h[t][l][r];
	v[t][l][r] = 1;
	if(l != 1 && s[l - 1] != s[r])
		h[t][l][r] = add(h[t][l][r] , H(t - 1 , l - 1 , r));
	if(r != m && s[l] != s[r + 1])
		h[t][l][r] = add(h[t][l][r] , H(t - 1 , l , r + 1));
	if(l != 1 && r != m && s[l - 1] == s[r + 1])
		h[t][l][r] = add(h[t][l][r] , H(t , l - 1 , r + 1));
	return h[t][l][r];
}

inline void Pow(int y)
{
	while (y)
	{
		if (y & 1)
			mul(f , g);
		mul(g) , y >>= 1;
	}
}

int main()
{
	scanf("%s%d" , s + 1 , &n) , m = strlen(s + 1);
	k = m + ceil(m);
	for(int i = 0; i < m; i++)
	{
		int c = 0;
		for(int j = 1; j <= m; j++)
		{
			c = add(c , H(i , j , j));
			if(j != m && s[j] == s[j + 1])
				c = add(c , H(i , j , j + 1));
		}
		if(i)
		{
			g[i][k - ceil(m - i)] = c , g[i][i] = 24;
			if(i != 1)
				g[i - 1][i] = 1;
			else
				f[i] = 1;
		}
		else
		{
			f[m] = c , g[k][k] = 26;
			for(int j = m; j < k; j++)
				g[j][j + 1] = 1 , g[j][j] = 25;
		}
	}
	for(int i = 1; i <= k; i++)
		F[i] = f[i];
	for(int i = 1; i <= k; i++)
		for(int j = 1; j <= k; j++)
			G[i][j] = g[i][j];
	Pow(ceil(n + m));
	if(!((n + m) & 1))
		return printf("%d\n" , f[k]) , 0;
	int ans = f[k];
	for(int i = 1; i <= k; i++)
		f[i] = F[i];
	for(int i = 1; i <= k; i++)
		for(int j = 1; j <= k; j++)
			g[i][j] = G[i][j];
	for(int i = 0; i < m; i++)
	{
		int c = 0;
		for(int j = 1; j < m; j++)
			if(s[j] == s[j + 1])
				c = add(c , H(i , j , j + 1));
		if(i)
			g[i][k - ceil(m - i)] = c;
		else
			f[m] = c , g[k][k] = 0;
	}
	Pow(ceil(n + m));
	printf("%d\n" , sub(ans , f[k]));
	return 0;
}
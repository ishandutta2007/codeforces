#include <bits/stdc++.h>

#define N 1000005

#define pb push_back
#define mk make_pair
#define fi first
#define se second

using namespace std;

int p[N], dp[N][2][2], n;

struct Node{
	int i, j, k;
}last[N][2][2];

void Min(int &a, int b, Node c, Node &d)
{
	if (a > b) a = b, d = c; 
}

void Main()
{
	scanf("%d", &n);
	for (int i = 1; i <= n; ++i) scanf("%d", &p[i]);
	for (int i = 0; i <= n; ++i)
		for (int j = 0; j < 2; ++j)
			for (int k = 0; k < 2; ++k)
				dp[i][j][k] = (int)1e9;
	dp[1][0][0] = -(int)1e9;
	dp[1][0][1] = -(int)1e9;
	for (int i = 1; i < n; ++i)
		for (int j = 0; j < 2; ++j)
			for (int k = 0; k < 2; ++k)
			{
				int a, b;
				if (j == 0) a = (k == 0 ? -p[i] : p[i]), b = dp[i][j][k];
				if (j == 1) a = dp[i][j][k], b = (k == 0 ? -p[i] : p[i]);
				//add p[i + 1]
				if (p[i + 1] > a) Min(dp[i + 1][0][1], b, (Node){i, j, k}, last[i + 1][0][1]);
				else if (p[i + 1] > b) Min(dp[i + 1][1][1], a, (Node){i, j, k}, last[i + 1][1][1]);
				//add -p[i + 1]
				if (-p[i + 1] > a) Min(dp[i + 1][0][0], b, (Node){i, j, k}, last[i + 1][0][0]);
				else if (-p[i + 1] > b) Min(dp[i + 1][1][0], a, (Node){i, j, k}, last[i + 1][1][0]);	
			}
	int nj = -1, nk = -1;
	for (int j = 0; j < 2; ++j)
		for (int k = 0; k < 2; ++k)
			if (dp[n][j][k] < (int)1e9)
			{
				nj = j; nk = k;
			}
	if (nj == -1) 
	{
		puts("NO");
		return;
	}
	for (int i = n; i >= 1; --i)
	{
		if (!nk) p[i] = -p[i];
		int aj = last[i][nj][nk].j, ak = last[i][nj][nk].k;
		nj = aj; nk = ak;
	}
	puts("YES");
	for (int i = 1; i <= n; ++i) printf("%d%c", p[i], (i == n ? '\n' : ' ')); 
}

int main()
{
	int T; scanf("%d", &T);
	for (;T--;) Main(); 
}
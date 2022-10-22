#include <cstdio>
#include <algorithm>
#include <cstring>
#define rep(i, l, r) for(int i = (l); i <= (r); i++)
#define per(i, r, l) for(int i = (r); i >= (l); i--)
#define mem(a, b) memset(a, b, sizeof a)
#define upd(a, b) a = max(a, b)

using namespace std;
const int N = 2e3 + 5;
int a[12][N], B[N], ord[N];
int f[17][1<<12], g[17][1<<12];
bool cmp(int a, int b) { return B[a] > B[b]; }
inline int mod(int a, int b) { return a >= b ? a - b : a; } 
int main()
{
	int t; scanf("%d", &t);
	while(t--)
	{
		int n, m; scanf("%d%d", &n, &m);
		mem(ord, 0); mem(f, 0); mem(g, 0);
		rep(i, 0, n - 1) rep(j, 1, m) scanf("%d", &a[i][j]);
		rep(i, 1, m) { B[ord[i] = i] = 0; rep(j, 0, n - 1) upd(B[i], a[j][i]); }
		sort(ord + 1, ord + m + 1, cmp);
		int maxs = (1 << n) - 1;
		rep(i, 1, n) rep(S, 0, maxs)
		{
			f[i][S] = f[i-1][S];
			rep(j, 0, n - 1)
			{
				int sum = 0;
				rep(k, 0, n - 1) if(S & (1 << k)) sum += a[mod(j + k, n)][ord[i]];
				upd(g[i][S], sum);
			}
			for(int T = S; T; --T &= S) upd(f[i][S], f[i-1][S^T] + g[i][T]);
		}
		printf("%d\n", f[n][maxs]);
	}
	return 0;
}
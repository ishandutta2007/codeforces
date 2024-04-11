#include <bits/stdc++.h>
using namespace std;

const int P = 1000000007;

int pp[500001], n, m, K;
long long val[500001], a[500001];
int fa[500001], x[500001], y[500001], id[500001], vis[500001];

vector <int> yx;

int find(int x)
{
	return fa[x] == x ? x : fa[x] = find(fa[x]);
}

bool cmp(const int &x, const int &y)
{
	return val[x] < val[y];
}

int main()
{

//	freopen("C.in", "r", stdin);
	
	pp[0] = 1; for (int i = 1; i <= 500000; ++ i) pp[i] = (pp[i - 1] * 2) % P;
	scanf("%d%d%d", &n, &m, &K);
	for (int i = 1; i <= n; ++ i) scanf("%lld", &a[i]);
	for (int i = 1; i <= n; ++ i) fa[i] = i;
	for (int i = 1; i <= m; ++ i)
	{
		scanf("%d%d", &x[i], &y[i]);
		val[i] = a[x[i]] ^ a[y[i]]; id[i] = i;
	}
	sort(id + 1, id + 1 + m, cmp);
	int Ans = 0; int Cnt = 0;
	for (int i = 1; i <= m; ++ i)
	{
		int j; ++ Cnt;
		for (j = i; j + 1 <= m && val[id[j + 1]] == val[id[j]]; ++ j);
		
//		printf("work %d %d\n", i, j);
		
		yx.clear(); int edg = j - i + 1;
		for (int k = i; k <= j; ++ k)
		{
			int xx = x[id[k]], yy = y[id[k]];
			if (vis[xx] != Cnt)
			{
				vis[xx] = Cnt; yx.push_back(xx);
			}
			if (vis[yy] != Cnt)
			{
				vis[yy] = Cnt; yx.push_back(yy);
			}
//			printf("link %d %d\n", xx, yy);
			int fx = find(xx), fy = find(yy);
			if (fx != fy) fa[fx] = fy;
			else -- edg;
		}
		int ncnt = yx.size(), mcnt = (int)yx.size() - edg;
		
//		printf("%d %d\n", ncnt, mcnt);
		
		Ans = (Ans + 1ll * (pp[ncnt] + P - pp[mcnt]) * pp[n - ncnt] % P) % P;
		for (auto x : yx) fa[x] = x;
		i = j;
	}
	Ans = (1ll * pp[K] * pp[n] % P + P - Ans) % P;
	printf("%d\n", Ans);
	return 0;
}
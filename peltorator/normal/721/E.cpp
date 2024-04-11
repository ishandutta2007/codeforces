#include <vector>
#include <map>
#include <set>
#include <queue>
#include <deque>
#include <stack>
#include <algorithm>
#include <limits>
#include <tuple>
#include <iostream>
#include <cstdio>

using namespace std;

int  p, f[100001], g[100001];

int xu(int k, int w, int x, int y)
{
	if (w + (y - x) / p > f[k])
    {
        f[k] = w + (y - x) / p;
        g[k] = x + (y - x) / p * p;
    }
    else if (w + (y - x) / p == f[k])
		g[k] = min(g[k], x + (y - x) / p * p);
    return 0;
}
int main()
{
    int m, n, t;
	cin >> m >> n >> p >> t;
	int now = 0, ans = 0;
	g[0] =- t;
	for (int i = 1; i <= n; i++)
    {
        int x, y;
		cin >> x >> y;
		if (now != 0)
            now--;
		for (; now < i && g[now] + t <= y; now++)
			if (g[now] + t <= x)
                xu(i, f[now], x, y);
            else
                xu(i, f[now], g[now] + t, y);
		ans = max(ans, f[i]);
		if (f[i - 1] > f[i])
        {
            f[i] = f[i - 1];
            g[i] = g[i - 1];
        }
		else if (f[i - 1] == f[i])
            g[i] = min(g[i], g[i - 1]);
	}
	cout << ans;
	return 0;
}
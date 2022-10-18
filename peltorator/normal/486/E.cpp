#include <iostream>
#include <math.h>
#include <algorithm>
#include <string>
#include <cstdio>
#include <algorithm>
#include <vector>

using namespace std;

vector<int> a, p, dp, v, ans, g[100001];

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
	int n;
	cin >> n;
	a.resize(n, 0);
	p.resize(n, 0);
	dp.resize(n, 0);
	v.resize(n, -1);
	ans.resize(n, 0);
	for(int i = 0; i < n; i++)
        cin >> a[i];
	int s = 1;
	dp[0] = a[0];
	p[0] = 0;
	for(int i = 1; i < n; i++)
	{
	    int l = -1, r = s;
	    while (r - l > 1)
        {
            int med = (r + l) / 2;
            if (dp[med] >= a[i])
                r = med;
            else
                l = med;
        }
		dp[r] = a[i];
        p[i] = r;
		if (r == s)
		    s++;
	}
	v[s] = 1e9;
	for(int i = n - 1; i >= 0; i--)
	{
		if (v[p[i] + 1] > a[i])
		{
			g[p[i]].push_back(i);
			v[p[i]] = max(v[p[i]], a[i]);
		}
		else
            ans[i] = 1;
	}
	for(int i = 0; i < s; i++)
	{
		if (g[i].size() == 1)
			ans[g[i][0]] = 3;
		else
            for(int j = 0; j < g[i].size(); j++)
                ans[g[i][j]] = 2;
	}
	for(int i = 0; i < n; i++)
        cout << ans[i];
	return 0;
}
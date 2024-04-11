#include <stdio.h>
#include <math.h>
#include <string.h>
#include <limits.h>
#include <stdlib.h>
#include <algorithm>
#include <iostream>
#include <utility>
#include <vector>
#include <string>
#include <map>
#include <queue>
#include <set>
#include <stack>

using namespace std;

#define long long long
#define fi first
#define se second
typedef pair<int,int> ii;

int A[200003];
int closed[200003];
int dp[200003];
bool visited[200003];
vector<int> vec[200003], chi[200003];
vector<int> ans;

long res = 0;
void dfs(int u)
{
	// printf("%d\n", u);
	visited[u] = 1;
	int mx = -1;
	dp[u] = A[u];
	for(int v : vec[u])
	{
		if(!visited[v])
		{
			dfs(v);
			chi[u].push_back(v);
			mx = max(dp[v], mx);
		}
	}
	int cnt = 0;
	for(int v : chi[u])
	{
		// printf("	%d %d %d\n", v, dp[v], bol);
		if(dp[v] == mx) cnt++;
		if(dp[v] < mx)
		{
			res += dp[v];
			closed[v] = dp[v];
		}
	}
	if(cnt >= 2)
		res += 1LL*mx*(cnt-1);
	for(int v : chi[u])
		if(dp[v] == mx && cnt > 1)
			closed[v] = dp[v];

	if(mx == -1) dp[u] = A[u];
	else dp[u] = min(mx, A[u]);
}

int cnt = 0;
void dfs2(int u, int val)
{
	// ++cnt;
	// if(cnt >= 500000)
	// {
	// 	printf("WHUT??\n"); fflush(stdout);
	// 	exit(0);
	// }
	if(A[u] == val)
		ans.push_back(u);
	for(int v : chi[u])
		if(closed[v] == -1)
			dfs2(v, val);
}

int main()
{
	// ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	// freopen("input.in", "r", stdin);

	memset(closed, -1, sizeof closed);

	int n; scanf("%d", &n);
	for(int i = 1; i <= n; i++)
		scanf("%d", &A[i]);

	for(int i = 1; i < n; i++)
	{
		int u, v;
		scanf("%d %d", &u, &v);
		vec[u].push_back(v);
		vec[v].push_back(u);
	}

	dfs(1);
	closed[1] = dp[1];
	for(int i = 1; i <= n; i++)
	{
		if(closed[i] != -1)
			dfs2(i, closed[i]);
	}
	res += dp[1];
	
	
	sort(ans.begin(), ans.end());
	printf("%I64d %lu\n", res, ans.size());
	for(int i = 0; i < ans.size(); i++)
		printf("%d%c", ans[i], (i == ans.size()-1)? '\n' : ' ');
}
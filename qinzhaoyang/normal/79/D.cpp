#include <bits/stdc++.h>

using namespace std;

int n , k , l;
int x[10010] , y[10010];
int e[210] , cnt;

int que[10010] , tail , head = 1;

int a[25] , cntm , b[10010];

int dis[25][25] , f[10010];

int dp[1050000];

void BFS(int st)
{
	memset(f , -1 , sizeof f);
	head = 1 , tail = 0;
	f[st] = 0;
	que[++tail] = st;
	while(head <= tail)
	{
		int t = que[head];
		head++;
		for(int i = 1; i <= cnt; i++)
		{
			int to = t + e[i];
			if(1 <= to && to <= n + 1)
			{
				if(f[to] == -1)
				{
					f[to] = f[t] + 1;
					que[++tail] = to;
				}
			}
		}
	}
	for(int i = 1; i <= cntm; i++)
		dis[b[st]][i] = f[a[i]];
}

void output(int x)
{
	while(x)
	{
		cout << x % 2;
		x /= 2;
	}
	cout << endl;
}

int main()
{
	ios::sync_with_stdio(false);
	cin >> n >> k >> l;
	for(int i = 1 , temp; i <= k; i++)
	{
		cin >> temp;
		x[temp] = true;
	}
	for(int i = 1 , temp; i <= l; i++)
	{
		cin >> temp;
		e[++cnt] = temp;
		e[++cnt] = -temp;
	}
	for(int i = 1; i <= n + 1; i++)
	{
		y[i] = x[i - 1] ^ x[i];
		if(y[i])
			a[++cntm] = i , b[i] = cntm;
	}
	for(int i = 1; i <= cntm; i++)
		BFS(a[i]);
	int size = 1 << (cntm);
	memset(dp , 0x3f , sizeof dp);
	dp[0] = 0;
	for(int i = 0; i < size; i++)
	{
		int temp = 0;
		for(int j = 0; j < cntm; j++)
			if(i & (1 << j))
				temp++;
		if(temp % 2 == 1)
			continue;
		for(int j = 0; j < cntm - 1; j++)
			for(int k = j + 1; k < cntm; k++)
				if((i & (1 << j)) && (i & (1 << k)) && dis[j + 1][k + 1] != -1)
					dp[i] = min(dp[i] , dp[i - (1 << j) - (1 << k)] + dis[j + 1][k + 1]);
	}
	if(dp[size - 1] == 0x3f3f3f3f)
		cout << -1 << endl;
	else
		cout << dp[size - 1] << endl;
	return 0;
}
#include <iostream>
#include <cstdio>
#include <queue>
#include <cstring>

using namespace std;

int n , m;
int flow1[2010] , cnt = 1;
int first[300] , nxt[2010] , to[2010] , flow[2010];
int cur[300];

int dep[300];
queue <int> q;

int maxflow = 0 , ans = 0;

int a[210] , b[210];

int firsta[300] , nxta[2010] , toa[2010] , wa[2010] , cnta = 1;

void connecta(int x , int y , int z)
{
	++cnta;
	toa[cnta] = y;
	nxta[cnta] = firsta[x];
	firsta[x] = cnta;
	wa[cnta] = z;
}

void connect(int x , int y , int z)
{
	++cnt;
	to[cnt] = y;
	nxt[cnt] = first[x];
	first[x] = cnt;
	flow1[cnt] = z;
}

bool BFS(int s , int t)
{
	memset(dep , 0 , sizeof dep);
	q.push(s);
	dep[s] = 1;
	while(!q.empty())
	{
		int p = q.front();
		q.pop();
		for(int e = first[p]; e; e = nxt[e])
			if(!dep[to[e]] && flow[e])
			{
				dep[to[e]] = dep[p] + 1;
				q.push(to[e]);
			}
	}
	return dep[t] != 0;
}

int DFS(int x , int min1 , int t)
{
	if(x == t || min1 == 0)
		return min1;
	int ret = 0;
	for(int &e = cur[x]; e; e = nxt[e])
		if(dep[to[e]] == dep[x] + 1 && flow[e])
		{
			int f = DFS(to[e] , min(min1 , flow[e]) , t);
			if(f)
			{
				flow[e] -= f;
				flow[e ^ 1] += f;
				min1 -= f;
				ret += f;
				if(!min1)
					return ret;
			}
		}
	return ret;
}

void Dinic(int s , int t)
{
	memcpy(flow , flow1 , sizeof flow1);
	maxflow = 0;
	while(BFS(s , t))
	{
		memcpy(cur , first , sizeof cur);
		maxflow += DFS(s , 0x3f3f3f3f , t);
	}
}

void solve(int l , int r)
{
	if(l == r)
		return;
	Dinic(a[l] , a[r]);
	ans += maxflow;
	connecta(a[l] , a[r] , maxflow);
	connecta(a[r] , a[l] , maxflow);
	int L = l - 1 , R = r + 1;
	for(int i = l; i <= r; i++)
	{
		if(dep[a[i]] > 0)
			b[++L] = a[i];
		else
			b[--R] = a[i];
	}
	for(int i = l; i <= r; i++)
		a[i] = b[i];
	solve(l , L);
	solve(R , r);
}

int vis[2010];

void dfs(int x , int fa , int &min1)
{
	for(int i = firsta[x]; i; i = nxta[i])
		if(vis[i] == 0 && toa[i] != fa)
		{
			dfs(toa[i] , x , min1);
			if(!min1 || wa[i] < wa[min1])
				min1 = i;
		}
}

void getans(int x)
{
	int min1 = 0;
	dfs(x , 0 , min1);
	if(!min1)
	{
		cout << x << " ";
		return;
	}
	vis[min1] = vis[min1 ^ 1] = 1;
	getans(toa[min1]);
	getans(toa[min1 ^ 1]);
}

int main()
{
	ios::sync_with_stdio(false);
	cin >> n >> m;
	for(int i = 1; i <= m; i++)
	{
		int a , b , c;
		cin >> a >> b >> c;
		connect(a , b , c);
		connect(b , a , c);
	}
	for(int i = 1; i <= n; i++)
		a[i] = i;
	solve(1 , n);
	cout << ans << endl;
	getans(1);
	cout << endl;
	return 0;
}
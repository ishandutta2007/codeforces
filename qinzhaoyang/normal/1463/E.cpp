#include <bits/stdc++.h>

using namespace std;

const int MAXN = 3e5 + 10;

int n , m;
int fa[MAXN];
vector <int> v[MAXN];
int in[MAXN];
int x[MAXN] , y[MAXN];

int L[MAXN] , R[MAXN] , cur;

int f[MAXN] , go[MAXN];

queue <int> q;

int t , ans[MAXN];

void dfs1(int x , int fa)
{
	L[x] = ++cur;
	for(int i = 0; i < v[x].size(); i++)
	{
		int to = v[x][i];
		if(to != fa)
			dfs1(to , x);
	}
	R[x] = cur;
}

int find(int x)
{
	if(f[x] == x)
		return x;
	return f[x] = find(f[x]);
}

int main()
{
	ios::sync_with_stdio(false);
	cin >> n >> m;
	for(int i = 1; i <= n; i++)
		f[i] = i;
	int root = 0; 
	for(int i = 1; i <= n; i++)
	{
		cin >> fa[i];
		if(!fa[i])
			root = i;
		else
			v[fa[i]].push_back(i);
	}
	dfs1(root , 0);
	int flag = false;
	for(int i = 1; i <= m; i++)
	{
		cin >> x[i] >> y[i];
		if(L[x[i]] <= L[y[i]] && R[y[i]] <= R[x[i]] || L[y[i]] <= L[x[i]] && R[x[i]] <= R[y[i]])
		{
			if(fa[y[i]] != x[i])
				flag = true;
		}
		if(find(x[i]) == find(y[i]))
			flag = true;
		go[x[i]] = y[i];
		f[f[y[i]]] = f[x[i]];
	}
	if(flag == true)
	{
		cout << 0 << endl;
		return 0;
	}
	for(int i = 1; i <= n; i++)
		v[i].clear();
	for(int i = 1; i <= n; i++)
		if(fa[i])
		{
			int x = find(fa[i]) , y = find(i);
			if(x != y)
				v[x].push_back(y) , in[y]++;
		}
	q.push(root);
	while(!q.empty())
	{
		int temp = q.front();
		ans[++t] = temp;
		q.pop();
		for(int i = 0; i < v[temp].size(); i++)
		{
			int to = v[temp][i];
			in[to]--;
			if(in[to] == 0)
				q.push(to);
		}
	}
	if(t != n - m)
		cout << 0 << endl;
	else
	{
		for(int i = 1; i <= t; i++)
		{
			int temp = ans[i];
			cout << temp << " ";
			while(go[temp])
			{
				temp = go[temp];
				cout << temp << " ";
			}
		}
		cout << endl;
	}
	return 0;
}
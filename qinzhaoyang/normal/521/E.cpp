#include <stdio.h>
#include <bits/stdc++.h>

using namespace std;

struct Edge {int nxt , to , id;} e[400010];
int first[200010] , cur;
void connect(int x , int y , int z) {e[++cur] = (Edge){first[x] , y , z} , first[x] = cur;}

int n , m;
int dep[200010] , fa[200010] , wh[200010];
int x[200010] , y[200010] , z[200010];

void dfs(int x , int f , int w)
{
	dep[x] = dep[f] + 1 , fa[x] = f , wh[x] = w;
	for(int i = first[x]; i; i = e[i].nxt)
		if(e[i].to != f && !dep[e[i].to])
			z[e[i].id] = 1 , dfs(e[i].to , x , e[i].id);
}

int f[200010];

int lca(int t1 , int t2)
{
	if(dep[t1] < dep[t2])
		swap(t1 , t2);
	while(dep[t1] > dep[t2])
		t1 = fa[t1];
	while(t1 != t2)
		t1 = fa[t1] , t2 = fa[t2];
	return t1;
}

int cnt = 0 , out[200010];

void print()
{
	cout << cnt << " ";
	for(int i = 1; i <= cnt; i++)
		cout << out[i] << " ";
	cout << endl , cnt = 0; 
}

void get(int x , int y)
{
	out[++cnt] = x;
	while(x != y)
		out[++cnt] = x = fa[x];
}

void getans(int _ , int __)
{
	cout << "YES" << endl;
	int t1 = x[_] , t2 = y[_];
	int t3 = x[__] , t4 = y[__];
	if(dep[t1] < dep[t2])
		swap(t1 , t2);
	if(dep[t3] < dep[t4])
		swap(t3 , t4);
	if(dep[t2] < dep[t4])
		swap(t1 , t3) , swap(t2 , t4);
	int t5 = lca(t1 , t3);
	get(t5 , t2);
	reverse(out + 1 , out + cnt + 1);
	print();
	get(t2 , t4) , get(t3 , t5);
	print();
	out[++cnt] = t2 , get(t1 , t5);
	print();
	exit(0);
}

int main()
{
	cin >> n >> m;
	for(int i = 1; i <= m; i++)
	{
		cin >> x[i] >> y[i];
		connect(x[i] , y[i] , i);
		connect(y[i] , x[i] , i);
	}
	for(int i = 1; i <= n; i++)
		if(!fa[i])
			dfs(i , 0 , 0);
	for(int i = 1; i <= m; i++)
		if(!z[i])
		{
			int t1 = x[i] , t2 = y[i];
			int l = lca(t1 , t2);
			if(dep[t1] < dep[t2])
				swap(t1 , t2);
			int fi = -1;
			while(t1 != l)
			{
				if(!f[wh[t1]])
					f[wh[t1]] = i;
				else
				{
					fi = f[wh[t1]];
					break;
				}
				t1 = fa[t1];
			}
			while(t2 != l)
			{
				if(!f[wh[t2]])
					f[wh[t2]] = i;
				else
				{
					fi = f[wh[t2]];
					break;
				}
				t1 = fa[t2];
			}
			if(fi != -1)
				return getans(fi , i) , 0;
		}
	cout << "NO" << endl;
	return 0;
}
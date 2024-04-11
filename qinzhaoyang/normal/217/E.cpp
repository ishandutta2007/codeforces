#include <iostream>
#include <cstdio>

using namespace std;

string str;
int k , n;
int l[5010] , r[5010] , fa[3000010];
int node[12000010];
char c[3000010];

int find(int x)
{
	if(fa[x] == x)
		return fa[x];
	return fa[x] = find(fa[x]);
}

void update(int p)
{
	node[p] = node[p << 1] + node[p << 1 | 1];
}

void build(int p , int l , int r)
{
	if(l == r)
	{
		node[p] = 1;
		return;
	}
	int mid = (l + r) >> 1;
	build(p << 1 , l , mid);
	build(p << 1 | 1 , mid + 1 , r);
	update(p);
}

inline int query(int x , int y)
{
	int p = 1 , l = 1 , r = k;
	while(l < r)
	{
		node[p] -= y;
		int mid = (l + r) >> 1;
		if(node[p << 1] >= x)
		{
			p = p << 1;
			r = mid;
		}
		else
		{
			x -= node[p << 1];
			p = p << 1 | 1;
			l = mid + 1;
		}
	}
	node[p] -= y;
	return l;
}

int main()
{
	ios::sync_with_stdio(false);
	cin >> str >> k >> n;
	for(int i = 1; i <= n; i++)
		cin >> l[i] >> r[i];
	for(int i = 1; i <= k; i++)
		fa[i] = i;
	build(1 , 1 , k);
	int len = k;
	for(int i = n; i >= 1; i--)
	{
		if(r[i] >= len)
			continue;
		int temp = r[i] - l[i] + 1 , tmp = len;
		for(int j = r[i] + 1; j <= r[i] + r[i] - l[i] + 1 && j <= len; j++)
		{
			int p;
			if(j - r[i] <= temp / 2)
				p = l[i] - 1 + (j - r[i]) * 2;
			else
				p = l[i] - 2 + (j - r[i] - temp / 2) * 2;
			int t1 = query(p , 0) , t2 = query(r[i] + 1 , 1);
			fa[find(t2)] = find(t1);
			tmp--;
		}
		len = tmp;
	}
	for(int i = 1; i <= len; i++)
		c[query(i , 0)] = str[i - 1];
	for(int i = 1; i <= k; i++)
		if(!c[i])
			c[i] = c[find(i)];
	for(int i = 1; i <= k; i++)
		cout << c[i];
	cout << endl;
	return 0;
}
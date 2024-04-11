#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 10;

struct Node
{
	int ch[26] , len , fa;
	Node() {memset(ch , 0 , sizeof ch) , len = fa = 0;}
}	sam[N << 1];

int cnt = 1 , lst = 1;
long long num[N << 1];

void insert(int x)
{
	int p = lst , np = lst = ++cnt;
	sam[np].len = sam[p].len + 1 , num[np] = 1;
	for(; p && !sam[p].ch[x]; p = sam[p].fa)
		sam[p].ch[x] = np;
	if(!p)
		sam[np].fa = 1;
	else
	{
		int q = sam[p].ch[x];
		if(sam[q].len == sam[p].len + 1)
			sam[np].fa = q;
		else
		{
			int nq = ++cnt;
			sam[nq] = sam[q];
			sam[nq].len = sam[p].len + 1;
			sam[q].fa = sam[np].fa = nq;
			for(; p && sam[p].ch[x] == q; p = sam[p].fa)
				sam[p].ch[x] = nq;
		}
	}
}

struct Edge
{
	int nxt , to;
	Edge(int nxt = 0 , int to = 0) : nxt(nxt) , to(to) {};
}	e[N << 2];

int first[N << 1] , cur;

void init()
{
	for(int i = 1; i <= cnt; i++)
		first[i] = 0;
	for(int i = 1; i <= cnt; i++)
		for(int j = 0; j < 26; j++)
			sam[i].ch[j] = 0;
	for(int i = 1; i <= cnt; i++)
		num[i] = 0;
	cnt = 1 , lst = 1 , cur = 0;
}

string s;

void connect(int x , int y)
{
	e[++cur] = Edge(first[x] , y);
	first[x] = cur;
}

void dfs(int x)
{
	for(int i = first[x]; i; i = e[i].nxt)
		dfs(e[i].to) , num[x] += num[e[i].to];
}

int main()
{
	ios::sync_with_stdio(false);
	int T;
	cin >> T;
	while(T--)
	{
		init() , cin >> s;
		for(int i = 0; i < s.size(); i++)
			insert(s[i] - 'a');
		for(int i = 2; i <= cnt; i++)
			connect(sam[i].fa , i);
		dfs(1);
		long long ans = 0;
		for(int i = 2; i <= cnt; i++)
			ans += 1ll * num[i] * num[i] * (sam[i].len - sam[sam[i].fa].len);
		cout << ans << endl;
	}
	return 0;
}
#include <bits/stdc++.h>

using namespace std;

const int N = 100010;
const long long oo = 0x3f3f3f3f3f3f3f3f;

struct Edge
{
	int nxt , to , w;
	Edge(int nxt = 0 , int to = 0 , int w = 0) : nxt(nxt) , to(to) , w(w) {};
}	e[N * 20];

int first[N * 3] , cur;

void connect(int x , int y , int z)
{
	e[++cur] = Edge(first[x] , y , z);
	first[x] = cur;
}

int cnt = 0;

int root[2] , ch[N * 3][2];

int build1(int l , int r)
{
	if(l == r)
		return l;
	int mid = (l + r) >> 1 , tmp = ++cnt;
	ch[tmp][0] = build1(l , mid) , ch[tmp][1] = build1(mid + 1 , r);
	connect(tmp, ch[tmp][0] , 0) , connect(tmp , ch[tmp][1] , 0);
	return tmp;
}

int build2(int l , int r)
{
	if(l == r)
		return l;
	int mid = (l + r) >> 1 , tmp = ++cnt;
	ch[tmp][0] = build2(l , mid) , ch[tmp][1] = build2(mid + 1 , r);
	connect(ch[tmp][0] , tmp , 0) , connect(ch[tmp][1] , tmp , 0);
	return tmp;
}

inline void add(int op , int p , int l , int r , int &tl , int &tr , int &v , int &w)
{
	if(tl <= l && r <= tr)
	{
		if(op == 0)
			connect(v , p , w);
		else
			connect(p , v , w);
		return;
	}
	int mid = (l + r) >> 1;
	if(tl <= mid)
		add(op , ch[p][0] , l , mid , tl , tr , v , w);
	if(tr > mid)
		add(op , ch[p][1] , mid + 1 , r , tl , tr , v , w);
	return;
}

int n , T , s;

long long dis[N * 3];

struct Node
{
	int p;
	long long w;
	Node(int p = 0 , long long w = 0) : p(p) , w(w) {}
};

bool operator < (const Node &A , const Node &B) {return A.w > B.w;}

priority_queue <Node> q;

int main()
{
	ios::sync_with_stdio(false);
	cin >> n >> T >> s;
	cnt = n;
	root[0] = build1(1 , n) , root[1] = build2(1 , n);
	while(T--)
	{
		int op , u , v , w , l , r;
		cin >> op;
		if(op == 1)
		{
			cin >> v >> u >> w;
			connect(v , u , w);
		}
		else
		{
			cin >> v >> l >> r >> w;
			add(op - 2 , root[op - 2] , 1 , n , l , r , v , w);
		}
	}
	memset(dis , 0x3f , sizeof dis);
	dis[s] = 0;
	q.push(Node(s , 0));
	while(!q.empty())
	{
		Node t = q.top();
		q.pop();
		if(t.w > dis[t.p])
			continue;
		for(int i = first[t.p]; i; i = e[i].nxt)
			if(dis[e[i].to] > t.w + e[i].w)
			{
				dis[e[i].to] = t.w + e[i].w;
				q.push(Node(e[i].to , dis[e[i].to]));
			}
	}
	for(int i = 1; i <= n; i++)
		cout << (dis[i] == oo ? -1 : dis[i]) << " ";
	cout << endl;
	return 0;
}
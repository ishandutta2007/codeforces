#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int id[100000];
int sz[100000];

void init()
{
	for(int i=0;i<100000;i++)
	{
		id[i] = i;
		sz[i] = 1;
	}
}

int find(int i)
{
	int j = i;
	while(j != id[j])
		j = id[j];
	id[i] = j;
	return j;
}

void join(int i,int j)
{
	int ri = find(i);
	int rj = find(j);
	if(ri==rj)
		return;
	if(sz[ri] < sz[rj])
	{
		id[ri] = rj;
		sz[rj] += sz[ri];
	}
	else
	{
		id[rj] = ri;
		sz[ri] += sz[rj];
	}
}


struct Query
{
	int t,a,b;
	int id;
	int place;
	int ans;
};

vector<vector<int> >child;
int N,M;
vector<Query> Q;
vector<Query> op;
vector<int> inorder;
int first[100000];
int last[100000];
bool vis[100000];

void dfs(int i)
{
	if(vis[i])
		return;
	vis[i] = 1;
	inorder.push_back(i);
	for(int j=0;j<child[i].size();j++)
		dfs(child[i][j]);
	inorder.push_back(i);
}

void calc()
{
	for(int i=0;i<2*N;i++)
		last[inorder[i]] = i;
	for(int i=(2*N-1);i>=0;i--)
		first[inorder[i]] = i;
}

vector<int> aiRec;
vector<int> aiPlace;
bool hasBoss[100000];

bool cmp(Query a,Query b)
{
	return a.place<b.place;
}
bool cmp2(Query a,Query b)
{
	return a.id<b.id;
}
int main()
{
	ios::sync_with_stdio(0);
	cin >> N >> M;
	for(int i=0;i<N;i++)
	{
		child.push_back(vector<int>());
		vis[i] = 0;
		hasBoss[i] = 0;
	}
	for(int i=0;i<M;i++)
	{
		int t,a,b;
		cin >> t >> a;
		if(t!=2)
		{
			cin >> b;
			b--;
		}
		a--;
		if(t==1)
		{
			hasBoss[a] = 1;
			child[b].push_back(a);
		}
		if(t==2)
		{
			aiRec.push_back(a);
			aiPlace.push_back(i);
		}
		else
		{
			Query q;
			q.t = t;
			q.a = a;
			q.b = b;
			q.id = i;
			if(t==1)
				q.place = i;
			else
				q.place = aiPlace[b];
			Q.push_back(q);
		}
	}
	for(int i=0;i<N;i++)
		if(!hasBoss[i])
			dfs(i);
	calc();
	init();
	sort(Q.begin(),Q.end(),cmp);
	for(int i=0;i<Q.size();i++)
	{
		if(Q[i].t==1)
			join(Q[i].a,Q[i].b);
		else
		{
			int x = Q[i].a;
			int y = aiRec[Q[i].b];
			if((first[x]<=first[y])&&(first[y]<=last[x])&&(find(x)==find(y)))
				Q[i].ans = 1;
			else
				Q[i].ans = 0;
		}
	}
	sort(Q.begin(),Q.end(),cmp2);
	for(int i=0;i<Q.size();i++)
		if(Q[i].t==3)
		{
			if(Q[i].ans)
				cout << "YES" << endl;
			else
				cout << "NO" << endl;
		}
	return 0;
}
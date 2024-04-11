#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

vector<int> fb[300000];
int N,M,K;

int prv[300000],nxt[300000];
bool vis[300000];
int fst;

void cut(int i)
{
	if(prv[i] != -1)
		nxt[prv[i]] = nxt[i];
	if(nxt[i] != N)
		prv[nxt[i]] = prv[i];
	if(i==fst)
		fst = nxt[i];	
}

void dfs(int i)
{
//	cout << "In " << i << '\n';
	vis[i] = 1;
	int cur = fst;
	while(cur != N)
	{
//		cout << cur << ' ';
		cur = nxt[cur];
	}
//	cout << '\n';
	int j = fst;
	int k = 0;
	vector<int> v;
	while(j != N)
	{
		while(k<fb[i].size() && fb[i][k]<j)
			k++;
		if(k==fb[i].size() || fb[i][k]>j)
			v.push_back(j);
		j = nxt[j];
	}
	for(j=0;j<v.size();j++)
		cut(v[j]);
	for(j=0;j<v.size();j++)
		dfs(v[j]);
//	cout << "Out " << i << '\n';
}

int cnum()
{
	for(int i=0;i<N;i++)
		prv[i] = i-1, nxt[i] = i+1, vis[i] = 0;
	fst = 0;
	int cnt = 0;
	for(int i=0;i<N;i++)
		if(!vis[i])
		{
			cut(i);
			dfs(i), cnt++;
		}
	return cnt;
}

int main()
{
	cin >> N >> M >> K;
	int a,b;
	for(int i=0;i<M;i++)
	{
		cin >> a >> b;
		a--,b--;
		fb[a].push_back(b);
		fb[b].push_back(a);
	}
	for(int i=0;i<N;i++)
		sort(fb[i].begin(),fb[i].end());
	if(fb[0].size()+K >= N)
	{
		cout << "impossible\n";
		return 0;
	}
	if(cnum() > 1)
	{
		cout << "impossible\n";
		return 0;
	}
	fb[0].clear();
	for(int i=1;i<N;i++)
	{
		fb[0].push_back(i);
		fb[i].push_back(0);
	}
	for(int i=0;i<N;i++)
		sort(fb[i].begin(),fb[i].end());
	if(cnum() > K+1)
	{
		cout << "impossible\n";
		return 0;
	}
	cout << "possible\n";
	return 0;
}
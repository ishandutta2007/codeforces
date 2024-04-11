#include <iostream>
#include <vector>
using namespace std;

bool con[500][500];
int ncon[500];
bool isb[500];

int vis[500];
int N,M;

bool dfs(int i,int tp)
{
	if(ncon[i]==N-1) return 0;
	if(vis[i]==0)
		vis[i] = tp;
	else if(vis[i] != tp)
		return 1;
	else
		return 0;
	for(int j=0;j<N;j++)
	{
		if(con[i][j]) {if(dfs(j,tp)) return 1;}
		else {if(dfs(j,3-tp)) return 1;}
	}
	return 0;
}

int main()
{
	ios::sync_with_stdio(0);
	cin >> N >> M;
	int a,b;
	for(int i=0;i<M;i++)
	{
		cin >> a >> b;
		a--,b--;
		con[a][b] = con[b][a] = 1;
		ncon[a]++,ncon[b]++;
	}
	for(int i=0;i<N;i++)
	{
		con[i][i] = 1;
		if(ncon[i]==N-1)
			isb[i] = 1;
	}
	for(int i=0;i<N;i++)
		if(vis[i]==0)
			if(dfs(i,1))
			{
				cout << "No\n";
				return 0;
			}
	cout << "Yes\n";
	for(int i=0;i<N;i++)
	{
		if(ncon[i]==N-1) cout << 'b';
		else if(vis[i]==1) cout << 'a';
		else cout << 'c';
	}
	cout << '\n';
}
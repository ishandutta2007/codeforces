#include <iostream>
#include <vector>
using namespace std;

int occ[200000][2];
int nxt[400000],tr[400000],index[400000],neg[400000],other[400000];
vector<int> edges[200000];

int cid[200000];
int sz[200000];
void init(int n)
{
	for(int i=0;i<n;i++)
		cid[i] = i, sz[i] = 1;
}
int find(int i)
{
	if(i == cid[i]) return i;
	cid[i] = find(cid[i]);
	return cid[i];
}
bool join(int i,int j)
{
	i = find(i), j = find(j);
	if(i==j) return 0;
	if(sz[i] > sz[j])
	{
		cid[j] = i;
		sz[i] += sz[j];
	}
	else
	{
		cid[i] = j;
		sz[j] += sz[i];
	}
	return 1;
}

bool vis[200000];
void dfs(int i,int par)
{
	vis[i] = 1;
	for(int j=0;j<edges[i].size();j++)
	{
		if(par != other[edges[i][j]])
			tr[edges[i][j]] ^= 1;
		if(!vis[nxt[edges[i][j]]])
			dfs(nxt[edges[i][j]],edges[i][j]);
	}
}

vector<int> heads;
int ans[200000];
bool good[200000];

int main()
{
	ios::sync_with_stdio(0);
	int N,M;
	cin >> N >> M;
	int k,a;
	for(int i=0;i<M;i++)
		occ[i][0] = occ[i][1] = -1;
	int E = 0;
	for(int i=0;i<N;i++)
	{
		cin >> k;
		for(int j=0;j<k;j++)
		{
			cin >> a;
			if(a > 0)
			{
				if(occ[a-1][0]==-1) occ[a-1][0] = i;
				else
				{
					edges[i].push_back(E);
					nxt[E] = i;
					index[E] = a-1;
					neg[E] = tr[E] = 0;
					other[E] = -1;
					E++;
					heads.push_back(i);
				}
			}
			else
			{
				if(occ[-a-1][1]==-1) occ[-a-1][1] = i;
				else
				{
					edges[i].push_back(E);
					nxt[E] = i;
					index[E] = -a-1;
					neg[E] = tr[E] = 1;
					other[E] = -1;
					E++;
					heads.push_back(i);
				}
			}
		}	
	}
	init(N);
	for(int i=0;i<M;i++)
	{
		if(occ[i][1] == -1)
		{
			edges[occ[i][0]].push_back(E);
			nxt[E] = occ[i][0];
			index[E] = i;
			neg[E] = tr[E] = 0;
			other[E] = -1;
			E++;
			heads.push_back(occ[i][0]);
		}
		else if(occ[i][0] == -1)
		{
			edges[occ[i][1]].push_back(E);
			nxt[E] = occ[i][1];
			index[E] = i;
			neg[E] = tr[E] = 1;
			other[E] = -1;
			E++;
			heads.push_back(occ[i][1]);
		}
		else
		{
			edges[occ[i][0]].push_back(E);
			nxt[E] = occ[i][1];
			index[E] = i;
			neg[E] = tr[E] = 1;
			other[E] = E+1;
			E++;
			edges[occ[i][1]].push_back(E);
			nxt[E] = occ[i][0];
			index[E] = i;
			neg[E] = tr[E] = 0;
			other[E] = E-1;
			E++;
			if(!join(occ[i][0],occ[i][1]))
				heads.push_back(occ[i][0]);
		}
	}
	for(int i=0;i<heads.size();i++)
		if(!vis[heads[i]])
		{
//			cout << '\t' << heads[i] << '\n';
			dfs(heads[i],-2);
		}
	for(int i=0;i<E;i++)
	{
//		if(tr[i] ^ neg[i]) cout << nxt[i] << '\n';
		good[nxt[i]] |= tr[i]^neg[i];
	}
	for(int i=0;i<N;i++)
		if(!good[i])
		{
			cout << "NO\n";
			return 0;
		}
	cout << "YES\n";
	for(int i=0;i<E;i++)
		ans[index[i]] = tr[i];
	for(int i=0;i<M;i++)
		cout << ans[i];
	cout << '\n';
}
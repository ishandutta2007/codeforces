#include <iostream>
#include <cstdio>
#include <vector>
using namespace std;

vector<int> primes;
vector<vector<int> > pStack(150000);
int id[2000000];

void gen()
{
	id[0] = -1;
	id[1] = -1;
	for(int i=2;i<2000000;i++)
	{
		int j;
		for(j=0;j<primes.size();j++)
		{
			if(primes[j]*primes[j] > i)
			{
				j = primes.size();
				break;
			}
			if(!(i%primes[j]))
				break;
		}
		if(j==primes.size())
		{
			primes.push_back(i);
			id[i] = primes.size()-1;
		}
		else
			id[i] = -1;
	}
}

vector<vector<int> > factors;

void getFactors(int n,int spot)
{
	factors[spot].clear();
	int m = n;
	for(int j=0;j<primes.size();j++)
	{
		if(primes[j]*primes[j] > n)
			break;
		if(!(m%primes[j]))
		{
			factors[spot].push_back(primes[j]);
			while(!(m%primes[j]))
				m /= primes[j];
		}
	}
	if(m > 1)
		factors[spot].push_back(m);
}

bool vis[100000];
int depth[100000];
int vals[100000];
int best[100000];
vector<vector<int> > edges;

void dfs(int i,int d)
{
	if(vis[i]) return;
	vis[i] = 1;
	depth[i] = d;
	int iBest = -2;
	int bestDepth = -1;
	getFactors(vals[i],i);
	for(int j=0;j<factors[i].size();j++)
	{
		int pi = id[factors[i][j]];
		if(pStack[pi].size() > 0)
			if(depth[pStack[pi][pStack[pi].size()-1]] > bestDepth)
			{
				bestDepth = depth[pStack[pi][pStack[pi].size()-1]];
				iBest = pStack[pi][pStack[pi].size()-1];
			}
		pStack[pi].push_back(i);
	}

	best[i] = iBest+1;

	for(int j=0;j<edges[i].size();j++)
		dfs(edges[i][j],d+1);

	for(int j=0;j<factors[i].size();j++)
	{
		int pi = id[factors[i][j]];
		pStack[pi].pop_back();
	}

	vis[i] = 0;
}

int main()
{
	gen();

	int N,Q;
	scanf("%d %d",&N,&Q);
	//cin >> N >> Q;
	for(int i=0;i<N;i++)
	{
		scanf("%d",&vals[i]);
		//cin >> vals[i];
		edges.push_back(vector<int>());
		factors.push_back(vector<int>());
	}
	int a,b;
	for(int i=0;i<(N-1);i++)
	{
		scanf("%d %d",&a,&b);
		//cin >> a >> b;
		a--,b--;
		edges[a].push_back(b);
		edges[b].push_back(a);
	}
	dfs(0,0);
	int tp,v,w;
	for(int i=0;i<Q;i++)
	{
		scanf("%d %d",&tp,&v);
		//cin >> tp >> v;
		v--;
		if(tp==2)
		{
			scanf("%d",&w);
			//cin >> w;
			vals[v] = w;
			dfs(0,0);
		}
		else
		{
			printf("%d\n",best[v]);
			//cout << best[v] << endl;
		}
	}
}
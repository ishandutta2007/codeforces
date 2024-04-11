#include <cstdio>
#include <vector>
using namespace std;

int eend[10000];
int w[10000];

int par[5000];
long long subSize[5000];
long long inDist[5000];
bool used[5000];
vector<vector<int> > edges;
int N;
int avoid;
long long origDist;
int start,best;

int n;

void dfs3(int i)
{
	used[i] = 1;
	if(inDist[i] < inDist[best])
		best = i;
	for(int j=0;j<edges[i].size();j++)
	{
		n = eend[edges[i][j]];
		if(!used[n])
			if(n!=avoid)
			{
				inDist[n] = inDist[i]+w[edges[i][j]]*(subSize[start]-2*subSize[n]);
				dfs3(n);
			}
	}
	used[i] = 0;
}

int dfs2(int i,long long d)
{
	used[i] = 1;
	origDist += d;
	subSize[i] = 1;
	for(int j=0;j<edges[i].size();j++)
	{
		n = eend[edges[i][j]];
		if(!used[n])
			if(n!=avoid)
				subSize[i] += dfs2(n,d+w[edges[i][j]]);
	}
	used[i] = 0;
	return subSize[i];
}

int dfs(int i)
{
	used[i] = 1;
	subSize[i] = 1;
	for(int j=0;j<edges[i].size();j++)
	{
		n = eend[edges[i][j]];
		if(!used[n])
			if(n!=avoid)
			{
				par[n] = i;
				subSize[i] += dfs(n);
			}
	}
	used[i] = 0;
	return subSize[i];
}

int main()
{
	scanf("%d",&N);
	for(int i=0;i<N;i++)
	{
		used[i] = 0;
		edges.push_back(vector<int>());
	}
	int a,b,c;
	for(int i=0;i<(N-1);i++)
	{
		scanf("%d %d %d",&a,&b,&c);
		a--,b--;
		edges[a].push_back(2*i);
		edges[b].push_back(2*i+1);
		eend[2*i] = b;
		eend[2*i+1] = a;
		w[2*i] = w[2*i+1] = c;
	}
	long long curAns;
	long long bestAns = 0;
	long long nxt;
	for(int i=0;i<N;i++)
	{
		for(int j=0;j<edges[i].size();j++)
		{
			nxt = eend[edges[i][j]];
			if(nxt < i) continue;
			curAns = 0;

			origDist = 0;
			start = i;
			avoid = nxt;
//			dfs(i);
			dfs2(i,0);
			inDist[i] = origDist;
			best = i;
			dfs3(i);
//			if((i==2)&&(nxt==3))
//				printf("%d\n",subSize[i]);
			curAns += (N-subSize[i])*(inDist[best]-inDist[i]);
			
			origDist = 0;
			avoid = i;
			start = nxt;
//			dfs(nxt);
			dfs2(nxt,0);
			inDist[nxt] = origDist;
			best = nxt;
			dfs3(nxt);
			curAns += (N-subSize[nxt])*(inDist[best]-inDist[nxt]);
//			printf("%d %d : %d\n",i+1,nxt+1,curAns);
			bestAns = min(bestAns,curAns);
		}
	}
//	printf("%d\n",bestAns);
	avoid = -1;
//	dfs(0);
	origDist = 0;
	start = 0;
	dfs2(0,0);
	inDist[0] = origDist;
	best = 0;
	dfs3(0);
	long long origTot = 0;
	for(int i=0;i<N;i++)
		origTot += inDist[i];
	printf("%I64d\n",bestAns + origTot/2);
	return 0;
}
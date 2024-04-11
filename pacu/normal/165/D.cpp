#include <cstdio>
#include <cmath>
#include <vector>
using namespace std;

inline int aabs(int a)
{
	if(a<0) return -a;
	return a;
}

class fenwick
{
public:
	fenwick(int n)
	{
		size = n+3;
		T = new int[size+1];
		for(int i=0;i<=size;i++)
			T[i] = 0;
	}
	~fenwick()
	{
		delete [] T;
		T = NULL;
	}
	long long getSum(int i)
	{
		long long c=0;
		for(++i; i > 0 ; i -= (i & -i))
		{
			c += T[i];
		}
		return c;
	}
	void set(int i,int dif)
	{
		for(++i; i < size ; i += (i & -i))
			T[i] = (T[i]+dif);
	}
private:
	int *T;
	int size;
};

int eend[200000];
int eDepth[200000];
int eComp[200000];
vector<vector<int> > edges;
int vDepth[100000];
int vComp[100000];
bool vis[100000];
fenwick *F[100001];

int dfs(int i,int c,int d)
{
	vDepth[i] = d;
	vComp[i] = c;
	vis[i] = 1;

	for(int j=0;j<edges[i].size();j++)
	{
		if(!vis[eend[edges[i][j]]])
		{
			eDepth[2*(edges[i][j]/2)] = d;
			eComp[2*(edges[i][j]/2)] = c;
			eDepth[2*(edges[i][j]/2) + 1] = d;
			eComp[2*(edges[i][j]/2) + 1] = c;
			return 1+dfs(eend[edges[i][j]],c,d+1);
		}
	}
	return 1;
}

int main()
{
	int N;
	scanf("%d",&N);
	for(int i=0;i<N;i++)
	{
		edges.push_back(vector<int>());
		vis[i] = 0;
	}
	int a,b;
	for(int i=0;i<(N-1);i++)
	{
		scanf("%d %d",&a,&b);
		a--,b--;
		edges[a].push_back(2*i);
		edges[b].push_back(2*i+1);
		eend[2*i] = b;
		eend[2*i+1] = a;
	}
	int root = 0;
	for(int i=0;i<N;i++)
	{
		if(edges[i].size()>2)
		{
			root = i;
			break;
		}
	}
	vis[root] = 1;
	vDepth[root] = 0;
	vComp[root] = edges[root].size();
	F[vComp[root]] = new fenwick(0);
	for(int j=0;j<edges[root].size();j++)
	{
		F[j] = new fenwick(dfs(eend[edges[root][j]],j,1));
		eDepth[2*(edges[root][j]/2)] = 0;
		eComp[2*(edges[root][j]/2)] = j;
		eDepth[2*(edges[root][j]/2) + 1] = 0;
		eComp[2*(edges[root][j]/2) + 1] = j;
	}
	int Q;
	int tp,eid;
	scanf("%d",&Q);
	for(int i=0;i<Q;i++)
	{
		scanf("%d",&tp);
		if(tp==1)
		{
			scanf("%d",&eid);
			eid = (eid-1)*2;
			F[eComp[eid]]->set(eDepth[eid]+1,-1);
		}
		else if(tp==2)
		{
			scanf("%d",&eid);
			eid = (eid-1)*2;
			F[eComp[eid]]->set(eDepth[eid]+1,1);
		}
		else
		{
			scanf("%d %d",&a,&b);
			a--,b--;
			if(vComp[a]==vComp[b])
			{
				if(F[vComp[a]]->getSum(vDepth[a]) != F[vComp[b]]->getSum(vDepth[b]))
					printf("-1\n");
				else
					printf("%d\n",aabs(vDepth[a]-vDepth[b]));
			}
			else
			{
				if((F[vComp[a]]->getSum(vDepth[a]) != 0)||(F[vComp[b]]->getSum(vDepth[b]) != 0))
					printf("-1\n");
				else
					printf("%d\n",vDepth[a]+vDepth[b]);
			}
		}
	}
	return 0;
}
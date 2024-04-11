#include <iostream>
#include <vector>
using namespace std;
#define MAXN 400001
int T[MAXN];

int getSum(int i)
{
	int c=0;
	for(++i; i > 0 ; i -= (i & -i))
		c += T[i];
	return c;
}
void set(int i,int dif)
{
	for(++i; i < MAXN ; i += (i & -i))
		T[i] += dif;
}
void init()
{
	for(int i=0;i<MAXN;i++)
		T[i] = 0;
}

vector<vector<int> > edges;
int firstLoc[200000];	//first occurrence of vertex in in-order traversal
int lastLoc[200000];
int iCur;
int used[200000];
int orig[200000];
bool pos[200000];

void dfs(int i,int depth)
{
	if(used[i])
		return;
	used[i] = 1;
	firstLoc[i] = iCur++;
	pos[i] = !(depth%2);
	for(int j=0;j<edges[i].size();j++)
		dfs(edges[i][j],depth+1);
	lastLoc[i] = iCur++;
}

int main()
{
	int N,M;
	cin >> N >> M;
	int a,b;
	for(int i=0;i<N;i++)
	{
		cin >> orig[i];
		used[i] = 0;
		edges.push_back(vector<int>());
	}
	for(int i=0;i<(N-1);i++)
	{
		cin >> a >> b;
		a--,b--;
		edges[a].push_back(b);
		edges[b].push_back(a);
	}
	dfs(0,0);
	init();
	for(int i=0;i<M;i++)
	{
		int tp,a,b;
		cin >> tp >> a;
		a--;
		if(tp==1)
		{
			cin >> b;
			if(!pos[a])
				b = -b;
			set(firstLoc[a],b);
			set(lastLoc[a]+1,-b);
		}
		else
		{
			int c = getSum(firstLoc[a]);
			if(!pos[a])
				c = -c;
			cout << c+orig[a] << endl;
		}
	}
}
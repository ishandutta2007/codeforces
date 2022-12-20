#include <iostream>
#include <vector>
using namespace std;

vector<vector<int> > edges;
vector<int> order;
int occ[100000];
int depth[100000];
bool used[100000];
int N;

void dfs(int i,int d)
{
	order.push_back(i);
	occ[i] = order.size()-1;
	used[i] = 1;
	depth[i] = d;
	for(int j=0;j<edges[i].size();j++)
		if(!used[edges[i][j]])
		{
			dfs(edges[i][j],d+1);
			order.push_back(i);
		}
}

#define SEG (1<<18)
int seg[2*SEG];
int l[2*SEG],r[2*SEG];

void init()
{
	for(int i=SEG;i<2*SEG;i++)
	{
		if((i-SEG)<(2*N-1)) seg[i] = depth[order[i-SEG]];
		else seg[i] = 1000000000;
		l[i] = r[i] = i-SEG;
	}
	for(int i=SEG-1;i>0;i--)
	{
		l[i] = l[2*i];
		r[i] = r[2*i+1];
		seg[i] = min(seg[2*i],seg[2*i+1]);
	}
}
int low,high;
int getMin(int i)
{
	if((r[i]<low)||(l[i]>high)) return 1000000000;
	if((l[i]>=low)&&(r[i]<=high)) return seg[i];
	return min(getMin(i<<1),getMin((i<<1)+1));
}
inline int getDist(int u,int v)
{
	low = occ[u];
	high = occ[v];
	if(low>high) swap(low,high);
	return depth[u]+depth[v]-(getMin(1)<<1);
}

bool painted[100000];
int nearLeft[100000];
int nearRight[100000];

int lca[200000];
int lowd[200000];
int runningAns[200000];
int sz;

void updateLeft()
{
	sz = 1;
	lca[0] = 0;
	lowd[0] = 0;
	runningAns[0] = 0;
	int cur;
	int curlca,curlow;
	for(int i=1;i<2*N-1;i++)
	{
		cur = order[i];
		curlca = depth[cur];
		if(painted[cur])
			curlow = curlca;
		else
			curlow = 1000000000;
		while((sz>0)&&(curlca<lca[sz-1]))
		{
			curlow = min(curlow,lowd[sz-1]);
			sz--;
		}
		lca[sz] = curlca;
		lowd[sz] = curlow;
		if(sz>0)
			runningAns[sz] = min(runningAns[sz-1],curlow-(curlca<<1));
		else
			runningAns[sz] = curlow-(curlca<<1);
		nearLeft[cur] = depth[cur]+runningAns[sz];
		sz++;
	}
}

void updateRight()
{
	sz = 1;
	lca[0] = 0;
	lowd[0] = 0;
	runningAns[0] = 0;
	int cur;
	int curlca,curlow;
	for(int i=(2*N-3);i>=0;i--)
	{
		cur = order[i];
		curlca = depth[cur];
		if(painted[cur])
			curlow = curlca;
		else
			curlow = 1000000000;
		while((sz>0)&&(curlca<lca[sz-1]))
		{
			curlow = min(curlow,lowd[sz-1]);
			sz--;
		}
		lca[sz] = curlca;
		lowd[sz] = curlow;
		if(sz>0)
			runningAns[sz] = min(runningAns[sz-1],curlow-(curlca<<1));
		else
			runningAns[sz] = curlow-(curlca<<1);
		nearRight[cur] = depth[cur]+runningAns[sz];
		sz++;
	}
}

int main()
{
	cin.tie(0);
	ios::sync_with_stdio(0);
	int M;
	cin >> N >> M;
	int bsize = 1;
	while(bsize*bsize < M)
		bsize++;
	int a,b;
	for(int i=0;i<N;i++)
	{
		edges.push_back(vector<int>());
		painted[i] = 0;
		used[i] = 0;
	}
	for(int i=1;i<N;i++)
	{
		cin >> a >> b;
		a--,b--;
		edges[a].push_back(b);
		edges[b].push_back(a);
	}
	dfs(0,0);
	painted[0] = 1;
	int t,v;
	int ans;
	vector<int> qblock;
	init();
	for(int i=0;i<M;i++)
	{
		if(!(i%bsize))
		{ 
			updateLeft();
			updateRight();
			qblock.clear();
		}
		cin >> t >> v;
		v--;
		if(t==1)
		{
			qblock.push_back(v);
			painted[v] = 1;
		}
		else
		{
			ans = min(nearLeft[v],nearRight[v]);
//			cout << nearLeft[v] << " " << nearRight[v] << "\n";
			for(int j=0;j<qblock.size();j++)
				ans = min(ans,getDist(v,qblock[j]));
			cout << ans << "\n";
		}
	}
	return 0;
}
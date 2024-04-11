#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int out[200000];
int ans[200001];
bool isCorrectOrientation[200001];
vector<vector<int> > edges;
bool used[100000];
int parEdge[100000];

//DFS inorder
int C;
int order[200000];
int depth[100001];
int oa[100000],ob[100000];

void dfs(int i,int d,int pedge)
{
	used[i] = 1;
	oa[i] = C;
	depth[i] = d;
	parEdge[i] = pedge;
	isCorrectOrientation[pedge] = 1;
	order[C++] = i;
	for(int j=0;j<edges[i].size();j++)
	{
		if(!used[out[edges[i][j]]])
		{
			dfs(out[edges[i][j]],d+1,edges[i][j]);
			order[C++] = i;
		}
	}
	ob[i] = C-1;
	used[i] = 0;
}

//RMQ
#define SEG (1<<18)
int seg[2*SEG],l[2*SEG],r[2*SEG];

void init()
{
	depth[100000] = 1000000000;
	for(int i=SEG;i<2*SEG;i++)
	{
		if((i-SEG)<C) seg[i] = order[i-SEG];
		else seg[i] = 100000;
		l[i] = r[i] = i-SEG;
	}
	for(int i=SEG-1;i>0;i--)
	{
		if(depth[seg[2*i]] < depth[seg[2*i+1]])
			seg[i] = seg[2*i];
		else
			seg[i] = seg[2*i+1];
		l[i] = l[2*i];
		r[i] = r[2*i+1];
	}
}

int getLow(int i,int low,int high)
{
	if((l[i]>high)||(r[i]<low)) return 100000;
	if((l[i]>=low)&&(r[i]<=high)) return seg[i];
	int s1 = getLow(2*i,low,high);
	int s2 = getLow(2*i+1,low,high);
	if(depth[s1] < depth[s2]) return s1;
	return s2;
}

//LCA
int foolsEnd[100000],numFools[100000];
int a[100000],b[100000];
int K;

void calcLCA()
{
	init();
	for(int i=0;i<K;i++)
	{
			if(oa[a[i]] > oa[b[i]])
				swap(a[i],b[i]);
			foolsEnd[getLow(1,oa[a[i]],ob[b[i]])]++;
			numFools[a[i]]++;
			numFools[b[i]]++;
	}
}

//DFS for answer

int dfsAns(int i)
{
	used[i] = 1;
	int c = numFools[i];
	for(int j=0;j<edges[i].size();j++)
		if(!used[out[edges[i][j]]])
			c += dfsAns(out[edges[i][j]]);
	c -= 2*foolsEnd[i];
	ans[parEdge[i]] = c;
	return c;
}

int main()
{
	int N,u,v;
	cin >> N;
	for(int i=0;i<N;i++)
		edges.push_back(vector<int>());
	for(int i=0;i<(N-1);i++)
	{
		cin >> u >> v;
		u--,v--;
		edges[u].push_back(2*i);
		edges[v].push_back(2*i+1);
		out[2*i] = v;
		out[2*i+1] = u;
	}
	cin >> K;
	for(int i=0;i<K;i++)
	{
		cin >> a[i] >> b[i];
		a[i]--,b[i]--;
	}
	dfs(0,0,200000);
	calcLCA();
	dfsAns(0);
	for(int i=0;i<2*N-2;i++)
		if(isCorrectOrientation[i])
			cout << ans[i] << " ";
	cout << "\n";
	return 0;
}
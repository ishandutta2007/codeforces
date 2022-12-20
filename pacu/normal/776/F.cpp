#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int N,M;
int a[100001],b[100001];
int cid[100001];
int invcid[100001];
int cid2[100001];

bool cmp(int x,int y)
{
	if(a[x]==a[y]) return b[x] > b[y];
	return a[x] < a[y];
}

bool cmp2(int x,int y)
{
	if(b[x] == b[y]) return a[x] < a[y];
	return b[x] < b[y];
}

vector<int> edges[100000];
int sz[100000];
bool bad[100000];
int ans[100000];

int regid[100000];

void dfsSize(int i,int par)
{
	sz[i] = 1;
	for(int j=0;j<edges[i].size();j++)
		if(edges[i][j] != par && !bad[edges[i][j]])
		{
			dfsSize(edges[i][j],i);
			sz[i] += sz[edges[i][j]];
		}
}

int getCenter(int i,int par)
{
	int tot = sz[i];
	bool changed = 1;
	while(changed)
	{
		changed = 0;
		for(int j=0;j<edges[i].size();j++)
			if(edges[i][j] != par && !bad[edges[i][j]] && sz[edges[i][j]]*2 > tot)
			{
				par = i;
				i = edges[i][j];
				changed = 1;
				break;
			}
	}
	return i;
}

void centroidDecomposition(int i,int par,int depth)
{
	dfsSize(i,par);
	i = getCenter(i,par);
	ans[regid[i]] = depth;
	bad[i] = 1;
	for(int j=0;j<edges[i].size();j++)
		if(!bad[edges[i][j]])
			centroidDecomposition(edges[i][j],i,depth+1);
}

int main()
{
	cin >> N >> M;
	for(int i=0;i<M;i++)
	{
		cin >> a[i] >> b[i];
		a[i]--,b[i]--;
		if(a[i] > b[i]) swap(a[i],b[i]);
		cid[i+1] = i;
		cid2[i+1] = i;
	}
	vector<int> st;
	cid[0] = cid2[0] = M;
	a[M] = 0, b[M] = N-1;
	sort(cid,cid+M+1,cmp);
	sort(cid2,cid2+M+1,cmp2);
	st.push_back(0);
	for(int i=1;i<=M;i++)
	{
		while(a[cid[i]] >= b[cid[st.back()]])
			st.pop_back();
		edges[st.back()].push_back(i);
		edges[i].push_back(st.back());
		st.push_back(i);
	}
	for(int i=0;i<=M;i++)
		invcid[cid[i]] = i;
	for(int i=0;i<=M;i++)
		regid[invcid[cid2[i]]] = i;
	centroidDecomposition(0,-1,1);
	for(int i=0;i<=M;i++)
		cout << ans[i] << ' ';
	cout << '\n';
}
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<vector<int> > edgesOut;
vector<vector<int> > edgesIn;
int N,M;
int vis[100000];
int num[100000];
vector<int> cyc;

int gcd(int a,int b)
{
	if(b==0) return a;
	return gcd(b,a%b);
}

void dfs(int i,int nm)
{
	if(num[i] != -1)
	{
		if(num[i] != nm)
			cyc.push_back(abs(num[i]-nm));
		return;
	}
	num[i] = nm;
	vis[i] = 1;
	for(int j=0;j<edgesOut[i].size();j++)
		dfs(edgesOut[i][j],nm+1);
	for(int j=0;j<edgesIn[i].size();j++)
		dfs(edgesIn[i][j],nm-1);
}


int main()
{
	cin >> N >> M;
	for(int i=0;i<N;i++)
	{
		edgesOut.push_back(vector<int>());
		edgesIn.push_back(vector<int>());
		vis[i] = 0;
		num[i] = -1;
	}
	int a,b;
	for(int i=0;i<M;i++)
	{
		cin >> a >> b;
		a--,b--;
		edgesOut[a].push_back(b);
		edgesIn[b].push_back(a);
	}
	for(int i=0;i<N;i++)
	{
		sort(edgesOut[i].begin(),edgesOut[i].end());
		edgesOut[i].erase(unique(edgesOut[i].begin(),edgesOut[i].end()),edgesOut[i].end());
		sort(edgesIn[i].begin(),edgesIn[i].end());
		edgesIn[i].erase(unique(edgesIn[i].begin(),edgesIn[i].end()),edgesIn[i].end());
	}
	for(int i=0;i<N;i++)
		if(!vis[i])
			dfs(i,0);
	int ans = 0;
	for(int i=0;i<cyc.size();i++)
		ans = gcd(ans,cyc[i]);
	if(ans==0)
		ans = N;
	cout << ans << endl;
}
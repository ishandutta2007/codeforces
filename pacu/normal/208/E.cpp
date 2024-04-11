#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<vector<int> > edges;
vector<int> ord;
int depth[100001];
int loc[100001];
int loc2[100001];

void dfs(int i,int d)
{
	loc2[i] = loc[i] = ord.size();
	ord.push_back(i);
	depth[i] = d;
	for(int j=0;j<edges[i].size();j++)
	{
		dfs(edges[i][j],d+1);
		ord.push_back(i);
		loc2[i] = ord.size()-1;
	}
}

vector<int> ad[100001];
vector<int> adf[100001];

struct Query
{
	int v,p,ans,qid;
};

bool cmp(Query a,Query b)
{
	return loc[a.v]<loc[b.v];
}

bool cmp2(Query a,Query b)
{
	return loc2[a.v]<loc2[b.v];
}

bool cmpid(Query a,Query b)
{
	return a.qid<b.qid;
}

Query aq[100000];

int main()
{
	int N,Q;
	cin >> N;
	N++;
	int v,p;
	for(int i=0;i<N;i++)
		edges.push_back(vector<int>());
	for(int i=1;i<N;i++)
	{
		cin >> p;
		edges[p].push_back(i);
	}
	dfs(0,0);

	cin >> Q;

	for(int i=0;i<Q;i++)
	{
		cin >> aq[i].v >> aq[i].p;
		aq[i].qid = i;
		aq[i].ans = 0;
	}
	sort(aq,aq+Q,cmp);
	int j = 0;
	for(int i=0;i<Q;i++)
	{
		v = aq[i].v;
		while(j < loc[v])
		{
			ad[depth[ord[j]]].push_back(j);
			if(loc[ord[j]] == j)
				adf[depth[ord[j]]].push_back(j);
			j++;
		}
		p = aq[i].p;
		if(p >= depth[v])
			continue;
		int l = ad[depth[v]-p-1][ad[depth[v]-p-1].size()-1];
		aq[i].ans += adf[depth[v]].end()-lower_bound(adf[depth[v]].begin(),adf[depth[v]].end(),l);
	}
	for(int i=0;i<N;i++)
	{
		ad[i].clear();
		adf[i].clear();
	}
	sort(aq,aq+Q,cmp2);
	j = ord.size()-1;
	for(int i=Q-1;i>=0;i--)
	{
		v = aq[i].v;
		while(j > loc2[v])
		{
			ad[depth[ord[j]]].push_back(j);
			if(loc2[ord[j]] == j)
				adf[depth[ord[j]]].push_back(j);
			j--;
		}
		p = aq[i].p;
		if(p >= depth[v])
			continue;
		int l = ad[depth[v]-p-1][ad[depth[v]-p-1].size()-1];
		aq[i].ans += adf[depth[v]].end()-lower_bound(adf[depth[v]].begin(),adf[depth[v]].end(),l,greater<int>());
	}
	sort(aq,aq+Q,cmpid);
	for(int i=0;i<Q;i++)
		cout << aq[i].ans << " ";
	cout << "\n";
	return 0;
}
#include <iostream>
#include <vector>
using namespace std;

int a[200000];
vector<int> edges[200000];
vector<int> ssl[200000];
vector<int> ml[200000];
vector<int> ssr[200000];
vector<int> mr[200000];
vector<int> safel[200000];
vector<int> safer[200000];
int nxt[400000];
int dist[400000];
bool safe[400000];

bool vis[200000];

int lval;
int best;

int N,K;

void calcDown(int i,int par,int e)
{
	vis[i] = 1;
	int c;
	bool s;
	bool tots = 1;
	for(int j=0;j<edges[i].size();j++)
	{
		if(nxt[edges[i][j]] == par)
			c = 0, s = 1;
		else if(a[nxt[edges[i][j]]]<lval)
			c = 0, s = 0;
		else
		{
			calcDown(nxt[edges[i][j]],i,edges[i][j]);
			c = dist[edges[i][j]];
			s = safe[edges[i][j]];
		}
		if(j==0)
		{
			if(s) ssl[i][j] = c, ml[i][j] = 0, safel[i][j] = 1;
			else ssl[i][j] = 0, ml[i][j] = c, safel[i][j] = 0;
		}
		else
		{
			if(s) ssl[i][j] = ssl[i][j-1]+c, ml[i][j] = ml[i][j-1];
			else ssl[i][j] = ssl[i][j-1], ml[i][j] = max(c,ml[i][j-1]);
			safel[i][j] = safel[i][j-1]&&s;
		}
	}
	for(int j=edges[i].size()-1;j>=0;j--)
	{
		if(nxt[edges[i][j]] == par)
			c = 0, s = 1;
		else if(a[nxt[edges[i][j]]]<lval)
			c = 0, s = 0;
		else
		{
			c = dist[edges[i][j]];
			s = safe[edges[i][j]];
		}
		if(j==edges[i].size()-1)
		{
			if(s) ssr[i][j] = c, mr[i][j] = 0, safer[i][j] = 1;
			else ssr[i][j] = 0, mr[i][j] = c, safer[i][j] = 0;
		}
		else
		{
			if(s) ssr[i][j] = ssr[i][j+1]+c, mr[i][j] = mr[i][j+1];
			else ssr[i][j] = ssr[i][j+1], mr[i][j] = max(c,mr[i][j+1]);
			safer[i][j] = safer[i][j+1]&&s;
		}			
	}
	if(e != -1)
	{
		dist[e] = 1+ssr[i][0]+mr[i][0];
		safe[e] = safer[i][0];
		//best = max(best,dist[e]+1);
		//cout << i << ": " << dist[e] << ' ' << safe[e] << '\n';
	}
}

void calcUp(int i,int par,int e,int eid,int gedge)
{
	if(e != -1)
	{
		for(int j=0;j<edges[i].size();j++)
		{
			if(nxt[edges[i][j]]  == par)
			{
				int c = 0;
				bool tots = 1;
				if(eid>0) tots &= safel[par][eid-1];
				if(eid<edges[par].size()-1) tots &= safer[par][eid+1];
				if(eid>0) c += ssl[par][eid-1];
				if(eid<edges[par].size()-1) c += ssr[par][eid+1];
				int m = 0;
				if(eid>0) m = max(m,ml[par][eid-1]);
				if(eid<edges[par].size()-1) m = max(m,mr[par][eid+1]);
				if(gedge != -1)
				{
					if(safe[gedge]) c += dist[gedge];
					else m = max(m,dist[gedge]);
					tots &= safe[gedge];
				}
				dist[e] = 1+c+m;
				safe[e] = tots;
				//best = max(best,dist[e]+1);
			}
		}
		int s = 0;
		int m = 0;
		if(safe[e]) s += dist[e];
		else m = max(m,dist[e]);
		if(edges[i].size()>0)
			s += ssr[i][0], m = max(m,mr[i][0]);
		best = max(best,1+s+m);
	}
	for(int j=0;j<edges[i].size();j++)
	{
		if(nxt[edges[i][j]]!=par && a[nxt[edges[i][j]]]>=lval)
			calcUp(nxt[edges[i][j]],i,edges[i][j],j,e);	
	}
}

bool pos()
{
	best = 0;
	for(int i=0;i<N;i++) vis[i] = 0;
	for(int i=0;i<N;i++)
		if(!vis[i] && a[i]>=lval)
		{
			calcDown(i,-1,-1);
			calcUp(i,-1,-1,-1,-1);
			if(edges[i].size()>0)
				best = max(best,1+ssr[i][0]+mr[i][0]);
		}
	return best >= K;
}

int binSearch(int low,int high)
{
	if(low==high) return low;
	if(low+1==high)
	{
		lval = high;
		if(pos()) return high;
		return low;
	}
	int mid = (low+high)/2;
	lval = mid;
	if(pos()) return binSearch(mid,high);
	else return binSearch(low,mid-1);
}

int main()
{
	ios::sync_with_stdio(0);
	cin >> N >> K;
	int high = 0;
	for(int i=0;i<N;i++)
	{
		cin >> a[i];
		high = max(high,a[i]);
	}
	int u,v;
	for(int i=0;i<N-1;i++)
	{
		cin >> u >> v;
		u--,v--;
		edges[u].push_back(2*i);
		nxt[2*i] = v;
		edges[v].push_back(2*i+1);
		nxt[2*i+1] = u;
	}
	for(u=0;u<N;u++)
	{
		for(int j=0;j<edges[u].size();j++)
		{
			ssl[u].push_back(0);
			ssr[u].push_back(0);
			ml[u].push_back(0);
			mr[u].push_back(0);
			safel[u].push_back(0);
			safer[u].push_back(0);
		}
	}
	if(K==1)
		cout << high << '\n';
	else
		cout << binSearch(1,1000000) << '\n';
}
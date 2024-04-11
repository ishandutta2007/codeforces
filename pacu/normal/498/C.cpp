#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int A[100];
int pfit[100];
int good[100][2];
int tOp;

int pre[400];
int nxt[400];
int cap[400];
int flow[102][102];
vector<int> edges[102];
int N,G;

vector<int> st;
int vis[102];
bool findPath(int i,int vv)
{
	if(i == N+1)
		return 1;
	vis[i] = vv;
	for(int j=0;j<edges[i].size();j++)
		if(vis[nxt[edges[i][j]]]!=vv && cap[edges[i][j]]>0)
		{
			st.push_back(edges[i][j]);
			if(findPath(nxt[edges[i][j]],vv))
				return 1;
			st.pop_back();
		}
	return 0;
}

void fflow()
{
	for(int i=0;i<400;i++)
		flow[pre[i]][nxt[i]] = flow[nxt[i]][pre[i]] = 0;
	for(int i=0;i<N+2;i++)
		vis[i] = 0;
	int fval;
	st.clear();
	for(int vv=1;findPath(N,vv);vv++)
	{
		fval = 1000000000;
		for(int j=0;j<st.size();j++)
			fval = min(fval,cap[st[j]]);
		for(int j=0;j<st.size();j++)
		{
			cap[st[j]] -= fval;
			cap[st[j]^1] += fval;
			flow[pre[st[j]]][nxt[st[j]]] += fval;
			flow[nxt[st[j]]][pre[st[j]]] -= fval;
		}
		st.clear();
	}
	for(int j=0;j<edges[N].size();j++)
		tOp += flow[N][nxt[edges[N][j]]];
}

void setup(int p)
{
			for(int i=0;i<N;i++)
			{
				pfit[i] = 0;
				while((A[i]%p)==0)
					pfit[i]++, A[i] /= p;
			}
			for(int j=0;j<edges[N].size();j++)
			{
				cap[edges[N][j]] = pfit[nxt[edges[N][j]]];
				cap[edges[N][j]+1] = 0;
			}
			for(int i=0;i<N;i++)
			{
				for(int j=0;j<edges[i].size();j++)
				{
					if(nxt[edges[i][j]] == N+1)
					{
						cap[edges[i][j]] = pfit[i];
						cap[edges[i][j]+1] = 0;
					}
					else if(!(i&1) && nxt[edges[i][j]]<N)
						cap[edges[i][j]] = 1000000000;
					else
						cap[edges[i][j]] = 0;
				}
			}
			fflow();
}

int main()
{
	cin >> N >> G;
	for(int i=0;i<N;i++)
	{
		cin >> A[i];
		if(i&1)
		{
			edges[i].push_back(2*i), pre[2*i] = i, nxt[2*i] = N+1;
			edges[N+1].push_back(2*i+1), pre[2*i+1] = N+1, nxt[2*i+1] = i;
		}
		else
		{
			edges[N].push_back(2*i), pre[2*i] = N, nxt[2*i] = i;
			edges[i].push_back(2*i+1), pre[2*i+1] = i, nxt[2*i+1] = N;
		}
	}
	for(int i=0;i<G;i++)
	{
		cin >> good[i][0] >> good[i][1];
		good[i][0]--,good[i][1]--;
		if(good[i][0]&1) swap(good[i][0],good[i][1]);
		edges[good[i][0]].push_back(2*N+2*i);
		edges[good[i][1]].push_back(2*N+2*i+1);
		pre[2*N+2*i] = good[i][0];
		nxt[2*N+2*i] = good[i][1];
		pre[2*N+2*i+1] = good[i][1];
		nxt[2*N+2*i+1] = good[i][0];
	}
	bool inc;
	for(int p=2;p*p<=1000000000;p++)
	{
		inc = 0;
		for(int i=0;i<N;i++)
			if((A[i]%p)==0)
				inc = 1;
		if(inc)
		{
			setup(p);
		}
	}
	for(int i=0;i<N;i++)
		if(A[i]>1)
			setup(A[i]);
	cout << tOp << '\n';
}
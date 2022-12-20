#include <iostream>
#include <iomanip>
#include <vector>
using namespace std;

vector<int> edges[50];
long long nxt[1000],flow[1000],cap[1000],w[1000];
int N,M,X;

int source,dest;

vector<int> st;
int vis[40000];
bool findPath(int i,int vv)
{
	if(i == dest)
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
long long totflow;
bool fflow(double car)
{
	source = 0, dest = N-1;
	for(int i=0;i<M;i++)
	{
		cap[2*i] = (long long)(((double)w[2*i])/car);
		cap[2*i+1] = 0;
		flow[2*i] = flow[2*i+1] = 0;
	}
	for(int i=0;i<N;i++) vis[i] = 0;
	long long fval;
	st.clear();
	totflow = 0;
	for(int vv=1;findPath(source,vv);vv++)
	{
		fval = 100000000000000000LL;
		for(int j=0;j<st.size();j++)
		{
			fval = min(fval,cap[st[j]]);
		}
		totflow += fval;
		for(int j=0;j<st.size();j++)
		{
			cap[st[j]] -= fval;
			cap[st[j]^1] += fval;
			flow[st[j]] += fval;
			flow[st[j]^1] -= fval;
		}
		st.clear();
	}
	return totflow >= X;
}

double binSearch(double low,double high,int tms)
{
	if(tms >= 200) return low;
	double mid = (low+high)/2.0;
	if(fflow(mid)) return binSearch(mid,high,tms+1);
	else return binSearch(low,mid,tms+1);
}

int main()
{
	cin >> N >> M >> X;
	int a,b,c;
	for(int i=0;i<M;i++)
	{
		cin >> a >> b >> c;
		a--,b--;
		edges[a].push_back(2*i);
		nxt[2*i] = b;
		edges[b].push_back(2*i+1);
		nxt[2*i+1] = a;
		w[2*i] = w[2*i+1] = c;
	}
	cout << setprecision(20) << X*binSearch(0,1000000,0) << '\n';
}
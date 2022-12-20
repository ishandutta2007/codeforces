#include <iostream>
#include <vector>
#include <iomanip>
using namespace std;

struct edge
{
	int dest,w,id;
};

vector<vector<edge> > edges;
bool used[100000];
int N,Q;
int roada[100000];
int roadb[100000];
long long roadw[100000];
long long roadm[100000];

long long choose(long long a)	//a choose 2
{
	return (a*(a-1))/2;
}

long long dfs(int i,long long &m)
{
	used[i] = 1;
	long long sz = 1;
	for(int j=0;j<edges[i].size();j++)
	{
		if(!used[edges[i][j].dest])
		{
			sz += dfs(edges[i][j].dest,roadm[edges[i][j].id]);
		}
	}
	m = sz*(N-sz);
	return sz;
}

int main()
{
	int a,b,l;
	cin >> N;
	for(int i=0;i<N;i++)
	{
		edges.push_back(vector<edge>());
		used[i] = 0;
	}
	edge e;
	for(int i=0;i<(N-1);i++)
	{
		cin >> a >> b >> l;
		roadw[i] = l;
		a--,b--;
		e.w = l;
		e.id = i;
		e.dest = b;
		edges[a].push_back(e);
		e.dest = a;
		edges[b].push_back(e);
	}
	long long temp;
	dfs(0,temp);
	long long ans = 0;
	for(int i=0;i<(N-1);i++)
		ans += roadm[i]*roadw[i];
	cin >> Q;
	for(int q=0;q<Q;q++)
	{
		int r,w;
		cin >> r >> w;
		r--;
		ans -= roadm[r]*roadw[r];
		ans += roadm[r]*w;
		roadw[r] = w;
		long double x = ((long double)ans)/((long double)choose(N));
		cout << setprecision(20) << ((long double)3.0)*x << endl;
	}
}
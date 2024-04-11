#include <iostream>
#include <vector>
using namespace std;

vector<vector<int> > edges;
vector<int> order;
int o1[100000],o2[100000];
bool vis[100000];

void dfs(int i)
{
	order.push_back(i);
	o1[i] = order.size()-1;
	for(int j=0;j<edges[i].size();j++)
		dfs(edges[i][j]);
	order.push_back(i);
	o2[i] = order.size()-1;
}

int cid[100000];

void init(int n)
{
	for(int i=0;i<n;i++)
		cid[i] = i;
}

int find(int i)
{
	if(i != cid[i])
		cid[i] = find(cid[i]);
	return cid[i];
}

void join(int i,int j)
{
	int ri = find(i);
	int rj = find(j);
	if(ri != rj)
		cid[ri] = rj;
}

int aI[100000],aV[100000],aX[100000];

#define MOD 1000000007
#define MAXN 200100

long long T[MAXN];

void init()
{
	for(int i=0;i<MAXN;i++)
		T[i] = 0;
}

void inc(int i,long long dif)
{
	for(i++;i<MAXN;i+=(i&-i))
		T[i] = (T[i]+dif)%MOD;
}

long long getSum(int i)
{
	long long c = 0;
	for(i++;i>0;i-=(i&-i))
		c = (c+T[i])%MOD;
	return c;
}

int main()
{
	cin.tie(0);
	ios::sync_with_stdio(0);
	int N;
	cin >> N;
	int M = 0;
	int K,v;
	init(N);
	for(int i=0;i<N;i++)
	{
		edges.push_back(vector<int>());
		cin >> K;
		for(int j=0;j<K;j++)
		{
			aI[M] = i;
			cin >> aV[M] >> aX[M];
			if(aX[M]<0)
				aX[M] += MOD;
			aV[M]--;
			v = find(aV[M]);
			cid[v] = i;
			edges[i].push_back(v);
			M++;
		}
	}
	for(int i=0;i<N;i++)
		if(cid[i] == i)
			dfs(i);
	long long ans = 0;
	long long elen;
	init();
	init(N);
	for(int i=0;i<M;i++)
	{
		elen = (getSum(o1[aV[i]])+aX[i])%MOD;
		ans = (ans+elen)%MOD;
		aV[i] = find(aV[i]);
		cid[aV[i]] = aI[i];
		inc(o1[aV[i]],elen);
		inc(o2[aV[i]]+1,(MOD-elen)%MOD);
	}
	cout << ans << "\n";
	return 0;
}
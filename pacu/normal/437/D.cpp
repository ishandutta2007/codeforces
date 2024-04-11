#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdio>
using namespace std;
#define MAXN 100001

int id[MAXN];
long long sz[MAXN];

void init(int N)
{
	for(int i=0;i<N;i++)
	{
		id[i] = i;
		sz[i] = 1;
	}
}

int root(int i)
{
	int j=i;
	while(i!=id[i])
		i = id[i];
	id[j]=i;
	return i;
}

long long join(int i,int j)
{
	int ri = root(i);
	int rj = root(j);
	if(ri==rj)
		return 0;
	long long ans = sz[ri]*sz[rj];
	if(sz[ri]<sz[rj])
	{
		id[ri] = rj;
		sz[rj] += sz[ri];
	}
	else
	{
		id[rj] = ri;
		sz[ri] += sz[rj];
	}
	return ans;
}



vector<int> aVal;

struct Path
{
	int p,q;
	int bneck;
};

bool operator<(Path a,Path b)
{
	return min(aVal[a.p],aVal[a.q])>min(aVal[b.p],aVal[b.q]);
}

vector<Path> A;

int main()
{
	int N,M;
	int i;
	int j;
	cin >> N >> M;
	for(i=0;i<N;i++)
	{
		cin >> j;
		aVal.push_back(j);
	}
	Path k;
	for(i=0;i<M;i++)
	{
		cin >> k.p >> k.q;
		k.p--,k.q--;
		k.bneck = min(aVal[k.p],aVal[k.q]);
		A.push_back(k);
	}
	sort(A.begin(),A.end());
	long long tot = 0;
	init(N);
	for(i=0;i<M;i++)
		tot += ((long long)A[i].bneck)*join(A[i].p,A[i].q);
	long double ans = tot*2;
	ans /= (long double)N;
	ans /= (long double)(N-1);
	printf("%.6lf\n",ans);
}
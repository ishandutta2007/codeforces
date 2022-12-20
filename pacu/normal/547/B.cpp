#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <string>
#include <set>
#include <map>
using namespace std;

int cid[201000];
int sz[201000];

void init(int n)
{
	for(int i=0;i<n;i++)
	{
		cid[i] = i;
		sz[i] = 1;
	}
}

int find(int i)
{
	int j = cid[i];
	while(j != cid[j]) j = cid[j];
	cid[i] = j;
	return j;
}

void join(int i,int j)
{
	int ri = find(i);
	int rj = find(j);
	if(sz[ri] > sz[rj])
	{
		cid[rj] = ri;
		sz[ri] += sz[rj];
	}
	else
	{
		cid[ri] = rj;
		sz[rj] += sz[ri];
	}
}

int A[200100];
int ai[200100];
int best[201001];
bool seen[201000];

bool cmp(int a,int b)
{
	return A[a] > A[b];
}

int main()
{
	int N;
	cin >> N;
	init(N);
	for(int i=0;i<N;i++)
	{
		cin >> A[i];
		ai[i] = i;
	}
	sort(ai,ai+N,cmp);
	int k;
	for(int i=0;i<N;i++)
	{
		k = ai[i];
		if((k>0)&&(seen[k-1]))
			join(k-1,k);
		if((k<(N-1))&&(seen[k+1]))
			join(k,k+1);
		seen[k] = 1;
		int c = find(k);
		best[sz[c]] = max(best[sz[c]],A[k]);
	}
	for(int i=N-1;i>=1;i--)
		best[i] = max(best[i],best[i+1]);
	for(int i=1;i<=N;i++)
		cout << best[i] << " ";
	cout << endl;
}
#include <cstdio>
#include <algorithm>
#include <map>
using namespace std;

int N,M;
int *A[1000000];
int mxr[1000000];
int mxc[1000000];
int v[1000000],cid[1000000];
int *B[1000000];
int tmp[1000000];

int fid[1000000];

bool cmp(int a,int b)
{
	if(v[a]==v[b]) return fid[a]<fid[b];
	return v[a]<v[b];
}

void init()
{
	for(int i=0;i<N*M;i++) fid[i] = i;
}
int find(int i)
{
	if(fid[i]==i) return i;
	fid[i] = find(fid[i]);
	return fid[i];
}
void join(int i,int j)
{
	i = find(i), j = find(j);
	fid[i] = j;
}

int main()
{
	scanf("%d %d",&N,&M);
	for(int i=0;i<N;i++) A[i] = new int[M], B[i] = new int[M];
	for(int i=0;i<N;i++)
	{
		for(int j=0;j<M;j++)
		{
			scanf("%d",&A[i][j]);
			v[M*i+j] = A[i][j];
			cid[M*i+j]  = M*i+j;
		}
	}
	init();
	for(int i=0;i<N;i++)
	{
		map<int,int> mp;
		for(int j=0;j<M;j++)
		{
			if(mp.find(A[i][j]) != mp.end())
				join(M*i+j,mp[A[i][j]]);
			else
				mp[A[i][j]] = M*i+j;
		}
	}
	for(int j=0;j<M;j++)
	{
		map<int,int> mp;
		for(int i=0;i<N;i++)
		{
			if(mp.find(A[i][j]) != mp.end())
				join(M*i+j,mp[A[i][j]]);
			else
				mp[A[i][j]] = M*i+j;
		}
	}
	for(int i=0;i<N*M;i++) find(i);
	sort(cid,cid+N*M,cmp);
	long long ans = 0;
	int start = 0;
	for(int i=0;i<M*N;i++)
	{
		if(i<M*N-1 && fid[cid[i]] == fid[cid[i+1]]) continue;
		int outval = 1;
		for(int j=start;j<=i;j++)
		{
			outval = max(outval,1+mxr[cid[j]/M]);
			outval = max(outval,1+mxc[cid[j]%M]);
		}
		for(int j=start;j<=i;j++)
		{
			B[cid[j]/M][cid[j]%M] = outval;
			mxr[cid[j]/M] = max(mxr[cid[j]/M],outval);
			mxc[cid[j]%M] = max(mxc[cid[j]%M],outval);
		}
		start = i+1;
	}
	for(int i=0;i<N;i++)
	{
		for(int j=0;j<M;j++)
			printf("%d ",B[i][j]);
		printf("\n");
	}
}
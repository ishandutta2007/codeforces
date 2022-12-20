#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
#define BSIZE 317

int N,D;
long long height[100000];
int id[100000];
int loc[100000];
int low[100000];
int high[100000];
bool cmp(int a,int b)
{
	return height[a]<height[b];
}

int last[100000];
int dp[100000];
int mx[317];
int imx[317];

void update(int i,int val)
{
	dp[i] = val;
	if(dp[i] > mx[i/BSIZE])
		imx[i/BSIZE] = i;
	mx[i/BSIZE] = max(mx[i/BSIZE],val);
}

int getMax(int l,int r,int &index)
{
	int best = 0;
	index = -1;
	while((l<=r)&&(l%BSIZE))
	{
		if(dp[l] > best)
			index = l;
		best = max(best,dp[l]);
		l++;
	}
	while((r>=l)&&((r+1)%BSIZE))
	{
		if(dp[r] > best)
			index = r;
		best = max(best,dp[r]);
		r--;
	}
	while(l < r)
	{
		if(mx[l/BSIZE] > best)
			index = imx[l/BSIZE];
		best = max(best,mx[l/BSIZE]);
		l += BSIZE;
	}
	return best;
}

vector<int> ans;

int main()
{
	cin >> N >> D;
	if(D==0)
	{
		cout << N << endl;
		for(int i=0;i<N;i++)
			cout << i+1 << " ";
		return 0;
	}
	for(int i=0;i<N;i++)
	{
		cin >> height[i];
		id[i] = i;
	}
	sort(id,id+N,cmp);
	for(int i=0;i<N;i++)
		loc[id[i]] = i;

	low[0] = 0;
	for(int i=1;i<N;i++)
	{
		low[i] = low[i-1];
		while(height[id[low[i]]] <= (height[id[i]]-D))
			low[i]++;
	}
	high[N-1] = N-1;
	for(int i=(N-2);i>=0;i--)
	{
		high[i] = high[i+1];
		while(height[id[high[i]]] >= (height[id[i]]+D))
			high[i]--;
	}

	int nBlocks = N/BSIZE;
	if(nBlocks*BSIZE < N)
		nBlocks++;

	for(int i=0;i<nBlocks;i++)
		mx[i] = 0;
	for(int i=0;i<N;i++)
		dp[i] = 0;

	update(loc[0],1);
	last[loc[0]] = -1;

	for(int i=1;i<N;i++)
	{
		int v1,v2,i1,i2;
		v1 = getMax(0,low[loc[i]]-1,i1);
		v2 = getMax(high[loc[i]]+1,N-1,i2);
		if(max(v1,v2)==0)
			last[loc[i]] = -1;
		else if(v1>v2)
			last[loc[i]] = i1;
		else
			last[loc[i]] = i2;
		update(loc[i],1+max(v1,v2));
	}
	int j = 0;
	for(int i=0;i<N;i++)
	{
		if(dp[i] > dp[j])
			j = i;
	}
	cout << dp[j] << endl;
	while(j != -1)
	{
		ans.push_back(j);
		j = last[j];
	}
	for(int i=ans.size()-1;i>=0;i--)
		cout << id[ans[i]]+1 << " ";
	return 0;
}
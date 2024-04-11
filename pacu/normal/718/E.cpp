#include <iostream>
#include <string>
#include <vector>
using namespace std;

int N;
string s;
int A[100000];
vector<int> lst[8];
int d[8][100000];
int mask[100000];
bool occ[8];


bool inque[100000];
int que[100000];
bool hit[8];

void bfs(int c)
{
	for(int i=0;i<N;i++)
		inque[i] = 0, d[c][i] = 1000000000;
	int len = 0;
	int cur = 0;
	for(int j=0;j<lst[c].size();j++)
	{
		inque[lst[c][j]] = 1;
		que[len++] = lst[c][j];
		d[c][lst[c][j]] = 0;
	}
	for(int i=0;i<8;i++)
		hit[i] = 0;
	hit[c] = 1;
	while(cur < len)
	{
		int x = que[cur];
		if(x>0 && !inque[x-1])
		{
			inque[x-1] = 1;
			que[len++] = x-1;
			d[c][x-1] = 1 + d[c][x];
		}
		if(x<N-1 && !inque[x+1])
		{
			inque[x+1] = 1;
			que[len++] = x+1;
			d[c][x+1] = 1 + d[c][x];
		}
		int k = A[x];
		if(!hit[k])
		{
			hit[k] = 1;
			for(int j=0;j<lst[k].size();j++)
			{
				if(!inque[lst[k][j]])
				{
					inque[lst[k][j]] = 1;
					que[len++] = lst[k][j];
					d[c][lst[k][j]] = 1 + d[c][x];
				}
			}
		}
		cur++;
	}
}

int cnt[8][1<<8];
int low[8][8];

long long ans[17];

int main()
{
	cin >> N >> s;
	for(int i=0;i<N;i++)
	{
		A[i] = s[i]-'a';
		occ[A[i]] = 1;
		lst[A[i]].push_back(i);
	}
	for(int i=0;i<8;i++)
		bfs(i);
	for(int i=0;i<8;i++)
	{
		for(int j=0;j<8;j++)
		{
			low[i][j] = 1000000000;
			for(int k=0;k<lst[j].size();k++)
				low[i][j] = min(low[i][j],d[i][lst[j][k]]);
			for(int k=0;k<lst[j].size();k++)
				if(d[i][lst[j][k]] > low[i][j])
					mask[lst[j][k]] |= (1<<i);
		}
	}
	for(int i=0;i<N;i++)
	{
		cnt[A[i]][mask[i]]++;
	}
	int maxDist = 0;
	long long numMax = 0;
	for(int i=0;i<8;i++) for(int m=0;m<(1<<8);m++) if(cnt[i][m]>0)
	{
		for(int j=0;j<8;j++) for(int n=0;n<(1<<8);n++) if(cnt[j][n]>0)
		{
			int dist = 1000000000;
			for(int k=0;k<8;k++)
				dist = min(dist,low[i][k]+((m>>k)&1)+1+((n>>k)&1)+low[k][j]);
			if(i!=j || m!=n)
				ans[dist] += cnt[i][m]*((long long)cnt[j][n]);
			else
				ans[dist] += (cnt[i][m]*((long long)(cnt[i][m]-1)));
		}
	}
	for(int i=0;i<N;i++)
		for(int j=max(0,i-16);j<i;j++)
		{
			int dist = 1000000000;
			for(int k=0;k<8;k++)
				dist = min(dist,d[k][i]+1+d[k][j]);
			ans[dist]-=2;
			dist = min(dist,i-j);
			ans[dist]+=2;
		}
	int mx = 16;
	while(ans[mx]==0)
		mx--;
	cout << mx << ' ' << ans[mx]/2 << '\n';
}
#include <iostream>
#include <string>
using namespace std;

int cost[20][20];
int tmp[1<<20];

string A[20];

int grp[20][20];

int chgrp[26];

int maxCost[1<<20][20];
int totCost[1<<20][20];

int ans[1<<20];

int main()
{
	int N,M;
	cin >> N >> M;
	for(int i=0;i<N;i++)
		cin >> A[i];
	for(int i=0;i<N;i++)
		for(int j=0;j<M;j++)
			cin >> cost[i][j];
	for(int j=0;j<M;j++)
	{
		totCost[0][j] = maxCost[0][j] = 0;
		for(int i=0;i<N;i++)
			tmp[1<<i] = cost[i][j];
		for(int i=1;i<(1<<N);i++)
		{
			totCost[i][j] = totCost[i-(i&-i)][j] + tmp[i&-i];
			maxCost[i][j] = max(maxCost[i-(i&-i)][j],tmp[i&-i]);
		}
	}
	for(int j=0;j<M;j++)
	{
		for(int c=0;c<26;c++)
			chgrp[c] = 0;
		for(int i=0;i<N;i++)
			chgrp[A[i][j]-'a'] |= (1<<i);
		for(int i=0;i<N;i++)
			grp[i][j] = chgrp[A[i][j]-'a'];
	}
	ans[0] = 0;
	for(int i=0;i<N;i++)
		tmp[1<<i] = i;
	int cur;
	int best;
	for(int i=1;i<(1<<N);i++)
	{
		cur = tmp[i&-i];
		best = 20000000;
		for(int j=0;j<M;j++)
		{
			best = min(best,cost[cur][j]+ans[i-(i&-i)]);
			best = min(best,totCost[grp[cur][j]][j]-maxCost[grp[cur][j]][j] + ans[i&~grp[cur][j]]);
			//cout << '\t' << totCost[i&grp[cur][j]][j] << ' ' << maxCost[i&grp[cur][j]][j] << '\n';
		}
		ans[i] = best;
		//cout << i << ' ' << best << '\n';
	}
	cout << best << '\n';
}
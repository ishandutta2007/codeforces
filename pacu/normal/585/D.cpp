#include <iostream>
#include <algorithm>
using namespace std;

int N;
int A[25][3];

int dp1[1600000][2], dp2[1600000][2];
int att1[1600000], att2[1600000];
int cid1[1600000], cid2[1600000];

bool cmp1(int a,int b)
{
	if(dp1[a][0]==dp1[b][0])
	{
		if(dp1[a][1]==dp1[b][1])
			return att1[a] < att1[b];
		return dp1[a][1] < dp1[b][1];
	}
	return dp1[a][0] < dp1[b][0];
}

bool cmp2(int a,int b)
{
	if(dp2[a][0]==dp2[b][0])
	{
		if(dp2[a][1]==dp2[b][1])
			return att2[a] < att2[b];
		return dp2[a][1] < dp2[b][1];
	}
	return dp2[a][0] < dp2[b][0];
}

int main()
{
	cin >> N;
	for(int i=0;i<N;i++)
		for(int j=0;j<3;j++)
			cin >> A[i][j];
	int c1 = N/2;
	int ways1 = 1;
	for(int i=0;i<c1;i++) ways1 *= 3;
	int c2 = N-c1;
	int ways2 = 1;
	for(int i=0;i<c2;i++) ways2 *= 3;
	for(int i=0;i<ways1;i++)
	{
		int cur = i;
		for(int j=0;j<c1;j++)
		{
			if(cur%3 != 0) dp1[i][0] -= A[j][0], dp1[i][1] -= A[j][0], att1[i] += A[j][0];
			if(cur%3 != 1) dp1[i][0] += A[j][1];
			if(cur%3 != 2) dp1[i][1] += A[j][2];
			cur /= 3;
		}
		cid1[i] = i;
	}
	for(int i=0;i<ways2;i++)
	{
		int cur = i;
		for(int j=c1;j<N;j++)
		{
			if(cur%3 != 0) dp2[i][0] -= A[j][0], dp2[i][1] -= A[j][0], att2[i] += A[j][0];
			if(cur%3 != 1) dp2[i][0] += A[j][1];
			if(cur%3 != 2) dp2[i][1] += A[j][2];
			cur /= 3;
		}
		dp2[i][0] = -dp2[i][0];
		dp2[i][1] = -dp2[i][1];
		cid2[i] = i;
	}
	sort(cid1,cid1+ways1,cmp1);
	sort(cid2,cid2+ways2,cmp2);
	int best1,best2;
	int bestatt = -1000000000;
	int j = 0;
	for(int i=0;i<ways1;i++)
	{
		if(i<ways1-1 && dp1[cid1[i]][0]==dp1[cid1[i+1]][0] && dp1[cid1[i]][1]==dp1[cid1[i+1]][1]) continue;
		while(j<ways2-1 && (dp2[cid2[j]][0]<dp1[cid1[i]][0] || ((dp2[cid2[j]][0]==dp1[cid1[i]][0])&&(dp2[cid2[j]][1]<dp1[cid1[i]][1]))))
			j++;
		while(j<ways2-1 && ((dp2[cid2[j]][0]==dp2[cid2[j+1]][0])&&(dp2[cid2[j]][1]==dp2[cid2[j+1]][1])))
			j++;
		if((dp2[cid2[j]][0]==dp1[cid1[i]][0])&&(dp2[cid2[j]][1]==dp1[cid1[i]][1]))
		{
			if(att1[cid1[i]] + att2[cid2[j]] > bestatt)
			{
				bestatt = att1[cid1[i]] + att2[cid2[j]];
				best1 = cid1[i], best2 = cid2[j];
			}
		}
	}
	if(bestatt == -1000000000)
	{
		cout << "Impossible\n";
		return 0;
	}
	for(int i=0;i<c1;i++)
	{
		if(best1%3 == 0) cout << "MW\n";
		if(best1%3 == 1) cout << "LW\n";
		if(best1%3 == 2) cout << "LM\n";
		best1 /= 3;
	}
	for(int i=0;i<c2;i++)
	{
		if(best2%3 == 0) cout << "MW\n";
		if(best2%3 == 1) cout << "LW\n";
		if(best2%3 == 2) cout << "LM\n";
		best2 /= 3;
	}
}
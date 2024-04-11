#include <iostream>
#include <cstdio>
#include <vector>
#include <cmath>
using namespace std;

int N,L;
int aPos[1000];
int aFun[1000];
long double dp[1000];
int last[1000];
long double f[1000][1000];
vector<int> ans;

inline long double frust(int dist)
{
	return pow(fabs((long double)dist - L),(long double)0.5);
}

bool works(long double M)
{
	ans.clear();
	for(int i=0;i<N;i++)
	{
		dp[i] = M*aFun[i] - frust(aPos[i]-0);
		last[i] = -1;
		for(int j=0;j<i;j++)
		{
			long double c = dp[j] + M*aFun[i] - f[i][j];
			if(c > dp[i])
			{
				last[i] = j;
				dp[i] = c;
			}
		}
	}
	int k = N-1;
	while(k != -1)
	{
		ans.push_back(k);
		k = last[k];
	}
	return (dp[N-1] >= 0);
}

void binSearch(long double low,long double high)
{
	if((high-low)<10e-9)
		return;
	long double mid = (low+high)/2;
	if(works(mid))
		binSearch(low,mid);
	else
		binSearch(mid,high);
}

int main()
{
	scanf("%d %d",&N,&L);
	for(int i=0;i<N;i++)
		scanf("%d %d",&aPos[i],&aFun[i]);
	for(int i=0;i<N;i++)
		for(int j=0;j<i;j++)
			f[i][j] = frust(aPos[i]-aPos[j]);
	binSearch(0,10e6);
	for(int i=(ans.size()-1);i>=0;i--)
		printf("%d ",ans[i]+1);
	return 0;
}
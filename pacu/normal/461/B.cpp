#include <iostream>
#include <vector>
using namespace std;

vector<vector<int> > chil;
vector<bool> black;
int dp0[100000];
int dp1[100000];
long long prodUpTo[100000];
long long prodDownTo[100000];

void dfs(int i)
{
	if(chil[i].size()==0)
	{
		if(black[i])
		{
			dp0[i] = 1;
			dp1[i] = 1;
		}
		else
		{
			dp0[i] = 1;
			dp1[i] = 0;
		}
		return;
	}
	long long prod0 = 1;
	long long c;
	for(int j=0;j<chil[i].size();j++)
	{
		dfs(chil[i][j]);
		prod0 *= dp0[chil[i][j]];
		prod0 %= 1000000007;
	}
	prodUpTo[0] = dp0[chil[i][0]];
	for(int j=1;j<chil[i].size();j++)
	{
		prodUpTo[j] = prodUpTo[j-1]*dp0[chil[i][j]];
		prodUpTo[j] %= 1000000007;
	}
	prodDownTo[chil[i].size()-1] = dp0[chil[i][chil[i].size()-1]];
	for(int j=(chil[i].size()-2);j>=0;j--)
	{
		prodDownTo[j] = prodDownTo[j+1]*dp0[chil[i][j]];
		prodDownTo[j] %= 1000000007;
	}
	if(black[i])
	{
		dp1[i] = prod0;
		dp0[i] = prod0;
	}
	else
	{
		dp1[i] = 0;
		for(int j=0;j<chil[i].size();j++)
		{
			c = 1;
			if(j>0)
				c *= prodUpTo[j-1];
			if(j<(chil[i].size()-1))
				c *= prodDownTo[j+1];
			c %= 1000000007;
			c *= dp1[chil[i][j]];
			c %= 1000000007;
			dp1[i] += c;
			dp1[i] %= 1000000007;
		}
		dp0[i] = prod0 + dp1[i];
	}
}

int main()
{
	int N;
	int a,b;
	int i,j;
	cin >> N;
	for(i=0;i<N;i++)
	{
		chil.push_back(vector<int>());
		black.push_back(0);
	}
	for(i=0;i<(N-1);i++)
	{
		cin >> a;
		chil[a].push_back(i+1);
	}
	for(i=0;i<N;i++)
	{
		cin >> a;
		black[i] = a;
	}
	dfs(0);
	cout << dp1[0] << endl;
}
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

vector<string> A;
int N;
vector<vector<char> > dp;
vector<vector<char> > dp2;
vector<int> lcp;

void getdp(int iString,int ch)
{
	if(dp[iString][ch]>0)
		return;
	if(iString>0)
		if(A[iString-1].size()>ch)
			if(lcp[iString-1]>=(ch+1))
				return;
	int j = iString;
	if(A[j].size()>(ch+1))
	{
		getdp(j,ch+1);
		if(dp[j][ch+1]=='L')
		{
			dp[iString][ch] = 'W';
			return;
		}
	}
	j++;
	while((j<N)&&(lcp[j-1]>ch))
	{
		if(A[j].size()>(ch+1))
		{
			getdp(j,ch+1);
			if(dp[j][ch+1]=='L')
			{
				dp[iString][ch] = 'W';
				return;
			}
		}
		j++;
	}
	dp[iString][ch] = 'L';
}

int lc(string &a,string &b)
{
	for(int i=0;i<min(a.size(),b.size());i++)
	{
		if(a[i]==b[i]) continue;
		return i;
	}
	return min(a.size(),b.size());
}

void getdp2(int iString,int ch)
{
	if(dp2[iString][ch]>0)
		return;
	if(iString>0)
		if(A[iString-1].size()>ch)
			if(lcp[iString-1]>=(ch+1))
				return;
	int j = iString;
	bool canmove = 0;
	if(A[j].size()>(ch+1))
	{
		canmove = 1;
		getdp2(j,ch+1);
		if(dp2[j][ch+1]=='W')
		{
			dp2[iString][ch] = 'L';
			return;
		}
	}
	j++;
	while((j<N)&&(lcp[j-1]>ch))
	{
		if(A[j].size()>(ch+1))
		{
			canmove = 1;
			getdp2(j,ch+1);
			if(dp2[j][ch+1]=='W')
			{
				dp2[iString][ch] = 'L';
				return;
			}
		}
		j++;
	}
	if(canmove)
		dp2[iString][ch] = 'W';
	else
		dp2[iString][ch] = 'L';
}

int main()
{
	int K;
	int i,j,ch;
	cin >> N >> K;
	for(i=0;i<N;i++)
	{
		A.push_back(string());
		cin >> A[i];
		dp.push_back(vector<char>());
		dp2.push_back(vector<char>());
	}
	sort(A.begin(),A.end());
	for(i=0;i<N;i++)
		for(j=0;j<A[i].length();j++)
		{
			dp[i].push_back(0);
			dp2[i].push_back(0);
		}
	for(i=0;i<(N-1);i++)
	{
		lcp.push_back(lc(A[i],A[i+1]));
	}
	lcp.push_back(-1);
	int forceWin = 2;
	for(i=0;i<N;i++)
	{
		getdp(i,0);
		if(dp[i][0]=='L')
			forceWin = 1;
	}
	int forceLose = 2;
	for(i=0;i<N;i++)
	{
		getdp2(i,0);
		if(dp2[i][0]=='W')
			forceLose = 1;
	}
	if(forceWin==2)
	{
		cout << "Second" << endl;
		return 0;
	}
	if(forceLose==1)
	{
		cout << "First" << endl;
		return 0;
	}
	if(!(K%2))
		cout << "Second" << endl;
	else
		cout << "First" << endl;
}
#include <iostream>
#include <string>
using namespace std;

int dp[2000][2001];
int last[2000];
string s,p;

int calc(int i)
{
	int j = p.size()-1;
	for(;i>=0;i--)
	{
		if(s[i]==p[j])
			j--;
		if(j<0)
			return i;
	}
	return -1;
}

int main()
{
	cin >> s >> p;
	int N = s.size();
	int M = p.size();
	for(int i=0;i<s.size();i++)
		last[i] = calc(i);
	for(int i=0;i<s.size();i++)
	{
		for(int x=0;x<=s.size();x++)
		{
			dp[i][x] = -1;
			if(x>(i+1))
				continue;
			if(((i+1-last[i]-M)<=x)&&((i+1-M)>=x))
				dp[i][x] = 1;
			if((last[i]>0)&&(((i+1-last[i])-M)<=x)&&(dp[last[i]-1][x-((i+1-last[i])-M)]>-1))
				dp[i][x] = 1+dp[last[i]-1][x-((i+1-last[i])-M)];
			else
				dp[i][x] = max(dp[i][x],0);
			if(i>0)
				dp[i][x] = max(dp[i][x],dp[i-1][x]);
		}
	}
	for(int x=0;x<=s.size();x++)
		cout << dp[s.size()-1][x] << " ";
	return 0;
}
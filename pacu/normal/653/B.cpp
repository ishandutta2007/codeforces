#include <iostream>
#include <string>
#include <vector>
using namespace std;

long long dp[7][6];

vector<string> v[6];

int main()
{
	int N,Q;
	cin >> N >> Q;
	string s;
	char c;
	for(int i=0;i<Q;i++)
	{
		cin >> s >> c;
		v[c-'a'].push_back(s);
	}
	for(int i=0;i<6;i++)
		dp[1][i] = 1;
	for(int j=2;j<=N;j++)
	{
		for(int i=0;i<6;i++)
		{
			dp[j][i] = 0;
			for(int k=0;k<v[i].size();k++)
				dp[j][i] += dp[j-1][v[i][k][0]-'a'];
		}
	}
	cout << dp[N][0] << '\n';
}
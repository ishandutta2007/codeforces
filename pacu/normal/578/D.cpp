#include <iostream>
#include <string>
using namespace std;

int N,M;
string s;

long long dp[100000];
int ndif[100000];
long long wand[100000][26];

string b;
int lcs(int i,int j)
{
	if(i<0 || j<0) return 0;
	if(s[i]==b[j]) return 1+lcs(i-1,j-1);
	return max(lcs(i-1,j),lcs(i,j-1));
}

int main()
{
	cin >> N >> M >> s;
	dp[0] = M-1;
	ndif[0] = 1;
	for(int i=0;i<M;i++)
		wand[0][i] = 1;
	for(int i=1;i<N;i++)
	{
		ndif[i] = ndif[i-1] + (s[i] != s[i-1]);
		dp[i] = 0;
		if(s[i-1]==s[i])
			dp[i] += M-1;
		else
			dp[i] += (M-1)*i+M-1;
//		cout << "1. Now " << dp[i] << '\n';
		for(char c='a';c<'a'+M;c++)
		{
			if(c == s[i])
			{
				dp[i] += dp[i-1];
//				cout << "P-Added " << dp[i-1] << ". Now " << dp[i] << '\n';
			}
			else
			{
				dp[i] += ndif[i];
//				cout << "Added " << i+1-ndif[i] << ". Now " << dp[i] << '\n';
				wand[i][c-'a'] = 1;
				if(s[i-1] == c)
					wand[i][c-'a'] += wand[i-1][s[i]-'a'];
				dp[i] -= wand[i][c-'a'];
//				cout << "Now " << dp[i] << '\n';
			}
		}
//		cout << dp[i] << '\n';
		ndif[i] = ndif[i-1] + (s[i] != s[i-1]);
	}
	cout << dp[N-1] << '\n';
}
#include <iostream>
#include <vector>
#include <string>
#include <map>
using namespace std;
#define MOD 1000000007
#define B 29LL

int N;
string s;
long long sh[10000];
long long pw[20000];

int M;
string t[100000];
long long th[100000];
map<int,int> MP[1002];

int dp[10000];

int main()
{
	//ios::sync_with_stdio(0);
	cin >> N >> s >> M;
	for(int i=0;i<M;i++)
	{
		cin >> t[i];
		th[i] = 0;
		for(int j=t[i].size()-1;j>=0;j--)
		{
			if(t[i][j]<='Z') th[i] = (th[i]*B+1+t[i][j]-'A')%MOD;
			else th[i] = (th[i]*B+1+t[i][j]-'a')%MOD;
		}
		MP[t[i].size()][th[i]] = i;
	}
	sh[0] = (s[0]+1-'a');
	for(int i=1;i<N;i++)
		sh[i] = (sh[i-1]*B+1+s[i]-'a')%MOD;
	pw[0] = 1;
	for(int i=1;i<2*N;i++)
		pw[i] = (pw[i-1]*B)%MOD;
	for(int i=0;i<N;i++)
	{
		dp[i] = -1;
		int h;
		if(i<=1000 && (MP[i+1].find(sh[i])!=MP[i+1].end()))
		{
			dp[i] = MP[i+1][sh[i]];
			continue;
		}
		for(int j=max(i-1000,1);j<=i;j++)
		{
			if(dp[j-1]!=-1)
			{
				int h = (sh[i]+MOD-(pw[i+1-j]*sh[j-1])%MOD)%MOD;
				if(MP[i+1-j].find(h)!=MP[i+1-j].end())
				{
					dp[i] = MP[i+1-j][h];
					break;
				}
			}
		}
	}
	vector<int> ans;
	int cur = N-1;
	while(cur >= 0)
	{
		ans.push_back(dp[cur]);
		cur -= t[dp[cur]].size();
	}
	for(int i=ans.size()-1;i>=0;i--)
		cout << t[ans[i]] << ' ';
	cout << '\n';
}
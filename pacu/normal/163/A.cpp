#include <iostream>
#include <vector>
#include <string>
using namespace std;

int dp[2][5000];	//dp[i][j] = number of pairs with last letters a_i and b_j
int sm[2][5000];	//sm[i][j] = number of pairs with last letters a_i and any of b_0 ... b_j

int main()
{
	string a,b;
	int i,j;
	int alen,blen;
	cin >> a >> b;
	dp[0][0] = (a[0]==b[0]);
	sm[0][0] = dp[0][0];
	blen = b.size();
	alen = a.size();
	for(j=1;j<blen;j++)
	{
		dp[0][j] = (a[0]==b[j]);
		sm[0][j] = dp[0][j] + sm[0][j-1];
	}
	int ans = sm[0][blen-1];
	for(i=1;i<a.size();i++)
	{
		for(j=0;j<blen;j++)
		{
			if(a[i]==b[j])
			{
				if(j==0)
					dp[1][j] = 1;
				else
					dp[1][j] = 1+sm[0][j-1];
			}
			else
				dp[1][j] = 0;
			sm[1][j] = dp[1][j];
			if(j>0)
				sm[1][j] += sm[1][j-1];
			sm[1][j] %= 1000000007;
		}
		for(j=0;j<blen;j++)
		{
			dp[0][j] = dp[1][j];
			sm[0][j] = sm[1][j];
		}
		ans += sm[0][blen-1];
		ans %= 1000000007;
	}
	cout << ans << endl;
}
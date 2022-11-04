#include <bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define lsb(x) (x & (-x))
#define uint unsigned int
    
using namespace std;

int dp[1 << 24];
   
int main() 
{
#if 0
    ifstream cin("A.in");
    ofstream cout("A.out");
#endif
   	int i, j, n;
    ios::sync_with_stdio(false);
   	cin.tie(0), cout.tie(0);
	
	cin >> n;

	for(i = 0; i < n; i++)
	{
		string str;
		cin >> str;

		int cur = 0;
		for(j = 0; j < 3; j++)
		{	
			cur |= (1 << (str[j] - 'a'));				
		}
		dp[cur]++;
	}

	for(int bit = 0; bit < 24; bit++) 
	{
		for(i = 0; i < (1 << 24); i++)
		{
			if(i & (1 << bit))
				dp[i] += dp[i ^ (1 << bit)];
		}
	}

	int tot = (1 << 24) - 1;
	int ans = 0;
	for(i = 0; i < (1 << 24); i++)
	{
		int cur = n - dp[tot ^ i];
		cur *= cur;
		ans ^= cur;
		/*if(cur && i < 20) {
			cerr << sqrt(cur) << " " << i << "\n";
		}*/
	}

	cout << ans;

	return 0;
}
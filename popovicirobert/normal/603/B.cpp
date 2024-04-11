#include <bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define lsb(x) (x & (-x))
#define uint unsigned int
    
using namespace std;

const int MOD = (int) 1e9 + 7;

inline int lgput(int a, int b) 
{
	int ans = 1;
	while(b > 0) 
	{
		if(b & 1) ans = (1LL * ans * a) % MOD;
		b >>= 1;
		a = (1LL * a * a) % MOD;
	}
	return ans;
}
  
int main() 
{
#if 0
    ifstream cin("A.in");
    ofstream cout("A.out");
#endif
   	int i, j, p, k;
    ios::sync_with_stdio(false);
   	cin.tie(0), cout.tie(0);
	
	cin >> p >> k;

	if(k == 0)
	{
		cout << lgput(p, p - 1);
		return 0;
	}
	
	vector <bool> vis(p);
	vector <int> dp(p + 1), fr(p + 1);
	
	for(i = 0; i < p; i++)
	{
		if(vis[i] == 0)
		{
			int cnt = 0;
			int j = i;
			while(vis[j] == 0)
			{
				vis[j] = 1, cnt++;
				j = (1LL * j * k) % p;
			}	
			dp[cnt] += cnt;
			fr[cnt]++;
		}
	}

	int ans = 1;
	for(i = p; i >= 1; i--) 
	{
		for(j = 2 * i; j <= p; j += i)
		{
			dp[j] += dp[i];
		}
	}
	for(i = 1; i <= p; i++)
	{
		ans = (1LL * ans * lgput(dp[i], fr[i])) % MOD;
	}

	cout << ans;
	
	return 0;
}
#include <bits/stdc++.h>

using namespace std;

int t;
long long n , tmp[210];

long long prime[100010] , g[100010];
int cnt;

int main()
{
	for(int i = 2; i <= 100000; i++)
	{
		if(!g[i])
		{
			prime[++cnt] = i;
			g[i] = i;
		}
		for(int j = 1; j <= cnt; j++)
		{
			if(i * prime[j] > 100000 || g[i] < prime[j])
				break;
			g[i * prime[j]] = prime[j];
		}
	}
	ios::sync_with_stdio(false);
	cin >> t;
	while(t--)
	{
		cin >> n;
		for(int i = 0; i <= 200; i++)
			tmp[i] = 1;
		long long ans = 0;
		long long temp = n;
		for(int i = 1; prime[i] * prime[i] <= temp && i <= cnt; i++)
		{
			if(temp % prime[i] == 0)
			{
				long long cnt = 0;
				while(temp % prime[i] == 0)
				{
					cnt++;
					temp /= prime[i];
				}
				ans = max(ans , cnt);
			}
		}
		if(temp != 1)
			ans = max(ans , 1ll);
		for(int i = 1; prime[i] * prime[i] <= n && i <= cnt; i++)
		{
			if(n % prime[i] == 0)
			{
				int cnt = 0;
				while(n % prime[i] == 0)
				{
					cnt++;
					n /= prime[i];
				}
				tmp[ans - cnt + 1] *= prime[i];
			}
		}
		if(n > 1)
			tmp[ans] *= n;
		cout << ans << endl;
		for(int i = 1; i <= ans; i++)
		{
			tmp[i] *= tmp[i - 1];
			cout << tmp[i] << " ";
		}
		cout << endl;
	}
	return 0;
}
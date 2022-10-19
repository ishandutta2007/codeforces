#include <bits/stdc++.h>

using namespace std;

int t;
int n , k;
int c[100010];

int main()
{
	ios::sync_with_stdio(false);
	cin >> t;
	while(t--)
	{
		cin >> n >> k;
		for(int i = 1; i <= n; i++)
			cin >> c[i];
		int ans = 0x3f3f3f3f;
		for(int i = 1; i <= 100; i++)
		{
			int nxt = 1 , cnt = 0;
			for(int j = 1; j <= n; j++)
				if(c[j] == i)
				{
					if(nxt < j)
					{
						int temp = (j - nxt) / k;
						if((j - nxt) % k != 0)
							temp++;
						cnt += temp;
						nxt += temp * k;
					}
					nxt = max(nxt , j + 1);
				}
			if(nxt < n + 1)
			{
				int temp = (n + 1 - nxt) / k;
				if((n + 1 - nxt) % k != 0)
					temp++;
				cnt += temp;
				nxt += temp * k;
			}
			ans = min(ans , cnt);
		}
		cout << ans << endl;
	}
	return 0;
}
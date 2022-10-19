#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int t;
int n;
int last[200010];
int cnt[200010];

int main()
{
	ios::sync_with_stdio(false);
	cin >> t;
	while(t--)
	{
		memset(last , 0 , sizeof last);
		memset(cnt , 0 , sizeof cnt);
		cin >> n;
		for(int i = 1; i <= n; i++)
		{
			int a;
			cin >> a;
			last[i] = cnt[a];
			cnt[a] = i;
		}
		int ans = 0x3f3f3f3f;
		for(int i = 1; i <= n; i++)
			if(cnt[i] != 0)
			{
				int temp = cnt[i] , t = 0;
				if(temp != n)
					t++;
				while(temp != 0)
				{
					if(last[temp] != temp - 1)
						t++;
					temp = last[temp];
				}
				ans = min(ans , t);
			}
		cout << ans << endl;
	}
	return 0;
}
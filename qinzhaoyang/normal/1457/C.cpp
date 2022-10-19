#include <bits/stdc++.h>

using namespace std;

int t;
int a[100010];
int cnt1[100010] , cnt2[100010];

int main()
{
	ios::sync_with_stdio(false);
	cin >> t;
	while(t--)
	{
		int n , p , k , x , y;
		cin >> n >> p >> k;
		for(int i = 1; i <= n; i++)
		{
			char c;
			cin >> c;
			a[i] = int(c - '0');
		}
		for(int i = 0; i < k; i++)
		{
			for(int j = i + p; j <= n; j += k)
			{
				if(a[j])
					cnt1[i]++;
				cnt2[i]++;
			}
		}
		cin >> x >> y;
		int ans = 0x3f3f3f3f;
		for(int i = 0; n - i >= p; i++)
		{
			ans = min(ans , (cnt2[i % k] - cnt1[i % k]) * x + i * y);
			if(a[i + p])
				cnt1[i % k]--;
			cnt2[i % k]--;
		}
		cout << ans << endl;
	}
	return 0;
}
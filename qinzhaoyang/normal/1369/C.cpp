#include <iostream>
#include <algorithm>

using namespace std;

int n , k;
int a[200010] , b[200010] , cnt;
long long ans = 0;

int main()
{
	int times;
	cin >> times;
	while(times--)
	{
		ans = cnt = 0;
		cin >> n >> k;
		for(int i = 1; i <= n; i++)
			cin >> a[i];
		sort(a + 1 , a + n + 1);
		for(int i = 1; i <= k; i++)
		{
			int t;
			cin >> t;
			if(t == 1)
			{
				ans += 2 * a[n];
				--n;
			}
			else
				b[++cnt] = t;
		}
		sort(b + 1 , b + cnt + 1);
		int l = 1 , r = n;
		for(int i = cnt; i >= 1; i--)
		{
			ans += a[l] + a[r];
			l++ , r--;
			l += b[i] - 2;
		}
		cout << ans << endl;
	}
	return 0;
}
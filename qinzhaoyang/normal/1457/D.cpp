#include <bits/stdc++.h>

using namespace std;

int n;
int a[100010];

int main()
{
	ios::sync_with_stdio(false);
	cin >> n;
	for(int i = 1; i <= n; i++)
		cin >> a[i];
	if(n == 2)
	{
		cout << -1 << endl;
		return 0;
	}
	for(int i = 1; i <= n - 2; i++)
		if(int(log2(a[i])) == int(log2(a[i + 1])) && int(log2(a[i + 1])) == int(log2(a[i + 2])))
		{
			cout << 1 << endl;
			return 0;
		}
	int ans = 0x3f3f3f3f;
	for(int i = 1; i <= n; i++)
		for(int j = i + 1; j <= n; j++)
			for(int k = i; k < j; k++)
			{
				int x1 = 0 , x2 = 0;
				for(int g = i; g <= k; g++)
					x1 ^= a[g];
				for(int g = k + 1; g <= j; g++)
					x2 ^= a[g];
				if(x1 > x2)
					ans = min(ans , j - i - 1);
			}
	if(ans == 0x3f3f3f3f)
		cout << -1 << endl;
	else
		cout << ans << endl;
	return 0;
}
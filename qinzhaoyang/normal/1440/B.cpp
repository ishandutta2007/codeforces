#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

long long a[1000002];

int main()
{
	ios::sync_with_stdio(false);
	int t;
	cin >> t;
	while(t--)
	{
		int n , k;
		cin >> n >> k;
		for(int i = 1; i <= n * k; i++)
			cin >> a[i];
		long long temp = n / 2 + 1 , t = n * k + 1 , ans = 0;
		for(int i = 1; i <= k; i++)
		{
			t -= temp;
			if(t <= 0)
				break;
			ans += a[t];
		}
		cout << ans << endl;
	}
	return 0;
}
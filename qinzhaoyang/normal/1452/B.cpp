#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int t;
long long a[100010];

int main()
{
	ios::sync_with_stdio(false);
	cin >> t;
	while(t--)
	{
		ll n;
		cin >> n;
		for(int i = 1; i <= n; i++)
			cin >> a[i];
		ll max1 = 0 , sum = 0;
		for(int i = 1; i <= n; i++)
			max1 = max(max1 , a[i]);
		for(int i = 1; i <= n; i++)
			sum += a[i];
		if(max1 * (n - 1) >= sum)
			cout << max1 * (n - 1) - sum << endl;
		else
			cout << ((max1 * (n - 1) - sum) % (n - 1) + (n - 1)) % (n - 1) << endl;
	}
	return 0;
}
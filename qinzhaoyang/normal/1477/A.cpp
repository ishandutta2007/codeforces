#include <stdio.h>
#include <bits/stdc++.h>
#define int long long

using namespace std;

int gcd(int x ,  int y)
{
	if(y == 0)
		return x;
	return gcd(y , x % y);
}

int T;
int n , k;
int a[200010];

signed main()
{
	ios::sync_with_stdio(false);
	cin >> T;
	while(T--)
	{
		cin >> n >> k;
		for(int i = 1; i <= n; i++)
			cin >> a[i];
		sort(a + 1 , a + n + 1);
		int g = a[2] - a[1];
		for(int i = 2; i < n; i++)
			g = gcd(g , a[i + 1] - a[i]);
		if(abs(k - a[1]) % g != 0)
			cout << "NO" << endl;
		else
			cout << "YES" << endl; 
	}
	return 0;
}
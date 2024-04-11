#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int T;
int a[52] , n;

int main()
{
	ios::sync_with_stdio(false);
	cin >> T;
	while(T--)
	{
		cin >> n;
		for(int i = 1; i <= n; i++)
			cin >> a[i];
		ll sum1 = 0 , sum2 = 0;
		for(int i = 1; i <= n; i++)
		{
			if(i % 2 == 1)
				sum1 += a[i];
			else
				sum2 += a[i];
		}
		if(sum1 < sum2)
		{
			for(int i = 1; i <= n; i++)
			{
				if(i % 2 == 1)
					cout << 1 << " ";
				else
					cout << a[i] << " ";
			}
			cout << endl;
		}
		else
		{
			for(int i = 1; i <= n; i++)
			{
				if(i % 2 == 0)
					cout << 1 << " ";
				else
					cout << a[i] << " ";
			}
			cout << endl;
		}
	}
	return 0;
}
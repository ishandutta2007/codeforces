#include <bits/stdc++.h>
 
using namespace std;

//int y = 1E9 + 7;

long long query(int a, int b)
{
	cout << "? " << a << " " << b << endl;
	long long q;
	//assert(a != b && a > 0 && b > 0);
	//q = __gcd(y + a, y + b);
	cin >> q;
	//cout << "return " << a << " " << b << " " << q << endl;
	return q;
}

int main()
{
	int t;
	cin >> t;
	while (t--)
	{
		int ans = 0;
		int pref = 0;
		for (int i = 0; i < 30; i++)
		{
			if (pref)
			{
				int x = (1 << i) - pref;
				long long q = query((1 << 30) + x, x);
				if (!((q >> i) & 1))
					ans = ans ^ (1 << i);
			}
			else
			{
				long long q = query((1 << 30) + (1 << i), (1 << i));
				if (!((q >> i) & 1))
					ans = ans ^ (1 << i);
			}
			//cout << "iter " << i << " " << ans << endl;
			pref = ans;
		}
		cout << "! " << ans << endl;
	}
	return 0;
}
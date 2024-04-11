#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int t , n;

int main()
{
	cin >> t;
	while(t--)
	{
		cin >> n;
		if(n == 1)
			cout << 1 << endl;
		else
		{
			for(int i = 1; i < n; i++)
				cout << i + 1 << " ";
			cout << 1 << endl;
		}
	}
	return 0;
}
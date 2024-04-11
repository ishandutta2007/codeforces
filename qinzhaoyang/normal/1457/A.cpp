#include <bits/stdc++.h>

using namespace std;

int t;

int main()
{
	cin >> t;
	while(t--)
	{
		int n , m , r , c;
		cin >> n >> m >> r >> c;
		cout << max(max(abs(r - 1) + abs(c - 1) , abs(r - 1) + abs(m - c)) , max(abs(n - r) + abs(c - 1) , abs(n - r) + abs(m - c))) << endl;
	}
	return 0;
}
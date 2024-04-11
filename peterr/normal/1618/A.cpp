#include <bits/stdc++.h>
 
using namespace std;

const int MAXN = 7;
int b[MAXN];

int main()
{
	int t;
	cin >> t;
	while (t--)
	{
		for (int i = 0; i < 7; i++)
		{
			cin >> b[i];
		}
		cout << b[0] << " " << b[1] << " " << (b[6] - b[0] - b[1]) << "\n";
	}
	return 0;
}
#include <bits/stdc++.h>
 
using namespace std;

int main()
{
	int t;
	cin >> t;
	while (t--)
	{
		int n;
		cin >> n;
		for (int i = 0; i < n; i++)
		{
			int ptr = n;
			for (int j = 0; j < n; j++)
			{
				if (j == i)
					cout << "1 ";
				else
					cout << (ptr--) << " ";
			}	
			cout << "\n";
		}
	}
	return 0;
}
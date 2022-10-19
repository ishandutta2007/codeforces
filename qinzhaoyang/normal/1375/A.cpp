#include <iostream>
#include <cmath>

using namespace std;

int n , a[102];

int main()
{
	int t;
	cin >> t;
	while(t--)
	{
		cin >> n;
		for(int i = 1; i <= n; i++)
		{
			int temp;
			cin >> temp;
			a[i] = abs(temp); 
		}
		int f = 1;
		for(int i = 1; i <= n; i++)
		{
			if(f)
				cout << a[i] << " ";
			else
				cout << -a[i] << " ";
			f = !f;
		}
		cout << endl;
	}
	return 0;
}
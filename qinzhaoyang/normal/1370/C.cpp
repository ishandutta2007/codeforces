#include <iostream>

using namespace std;

int n;

bool check(int t)
{
	for(int i = 2; i * i <= t; i++)
		if(t % i == 0)
			return false;
	return true; 
}

int main()
{
	int t;
	cin >> t;
	while(t--)
	{
		cin >> n;
		if(n == 1)
			cout << "FastestFinger" << endl;
		else if(n == 2)
			cout << "Ashishgup" << endl;
		else
		{
			if(n % 2 == 1)
			{
				cout << "Ashishgup" << endl;
				continue;
			}
			if(n % 2 == 0 && n % 4 != 0 && check(n / 2))
			{
				cout << "FastestFinger" << endl;
				continue;
			}
			while(n % 2 == 0)
				n /= 2;
			if(n != 1)
					cout << "Ashishgup" << endl;
			else
				cout << "FastestFinger" << endl;
		}
	}
	return 0;
}
#include <iostream>

using namespace std;

int main()
{
	int n;
	cin >> n;
	if(n % 2 == 0)
	{
		cout << n / 2 << endl;
		for(int i = 1; i <= n / 2; i++)
			cout << 2 << " ";
		cout << endl;
	}
	else
	{
		cout << (n - 1) / 2 << endl;
		for(int i = 1; i <= (n - 3) / 2; i++)
			cout << 2 << " ";
		cout << 3 << endl;
	}
	return 0;
}
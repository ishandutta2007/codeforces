#include <iostream>

using namespace std;

int n , a[102];

int main()
{
	cin >> n;
	for(int i = 1; i <= n; i++)
	{
		int temp;
		cin >> temp;
		a[temp] = i;
	}
	for(int i = 1; i <= n; i++)
		cout << a[i] << " ";
	cout << endl;
	return 0;
}
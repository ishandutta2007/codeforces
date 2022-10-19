#include <iostream>

using namespace std;

int t;
long long a , b , c;

int main()
{
	cin >> t;
	while(t--)
	{
		cin >> a >> b >> c;
		if(a < c)
			cout << 1 << " ";
		else
			cout << -1 << " ";
		if(a * b > c)
			cout << b << endl;
		else
			cout << -1 << endl;
	}
	return 0;
}
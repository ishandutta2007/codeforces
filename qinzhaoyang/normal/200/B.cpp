#include <iostream>
#include <iomanip>

using namespace std;

int main()
{
	int n , sum = 0;
	cin >> n;
	for(int i = 1; i <= n; i++)
	{
		int a;
		cin >> a;
		sum += a;
	}
	cout << fixed << setprecision(10) << sum * 1.0 / n << endl;
	return 0;
}
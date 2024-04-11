#include <iostream>
using namespace std;

int main()
{
	long long n;
	cin >> n;
	cout << ((n+4)*(n+3)*(n+2)*(n+1)*n)/120 * (((n+2)*(n+1)*n)/6) << '\n';
}
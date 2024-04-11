#include <iostream>
using namespace std;

int main()
{
	long long n;
	cin >> n;
	cout << 6*(1LL<<(2*n-4)) + 9*(n-3)*(1LL<<(2*n-6)) << '\n';
}
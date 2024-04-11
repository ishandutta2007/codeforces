#include <iostream>
using namespace std;

int main()
{
	long long n;
	cin >> n;
	cout << ((n*(n-1)*(n-2)*(n-3)*(n-4))/120)*(n*(n-1)*(n-2)*(n-3)*(n-4)) << '\n';
}
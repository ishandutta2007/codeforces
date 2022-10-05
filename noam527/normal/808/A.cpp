#include <iostream>
using namespace std;

int main()
{
	long long n; cin >> n;
	long long l = n;
	while (l >= 10) l /= 10;
	l++;
	while (l < n) l *= 10;
	cout << l - n << endl;
}
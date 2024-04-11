#include <iostream>
using namespace std;

int main()
{
	long long x;
	cin >> x;
	long long p = 1LL;
	while(!(x%p))
		p *= 3LL;
	cout << 1+(x/p) << '\n';
	return 0;
}
#include <iostream>
using namespace std;

int main()
{
	long long l,r,k;
	cin >> l >> r >> k;
	long long c = 1;
	bool pt = 0;
	while(c <= r)
	{
		if(c >= l)
		{
			pt = 1;
			cout << c << ' ';
		}
		if(c > 2000000000000000000.0/k)
			break;
		c *= k;
	}
	if(pt==0)
		cout << -1;
	cout << '\n';
}
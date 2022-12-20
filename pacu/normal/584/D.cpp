#include <iostream>
using namespace std;

bool prime(int n)
{
	if(n == 2) return 1;
	if(!(n&1)) return 0;
	for(int i=3;i*i<=n;i+=2)
		if(!(n%i)) return 0;
	return 1;
}

int main()
{
	int n;
	cin >> n;
	int m = n;
	while(!prime(m))
		m -= 2;
	if(m == n)
	{
		cout << 1 << '\n' << m << '\n';
		return 0;
	}
	if(m == n-2)
	{
		cout << 2 << '\n' << 2 << ' ' << m << '\n';
		return 0;
	}
	for(int i=2;i<=n-m;i++)
	{
		if(prime(i) && prime(n-m-i))
		{
			cout << 3 << '\n' << m << ' ' << i << ' ' << n-m-i << '\n';
			return 0;
		}
	}
}
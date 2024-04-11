#include <iostream>
using namespace std;

int pcount(int x)
{
	if(x==0) return 0;
	return (x&1)+pcount(x>>1);
}

int main()
{
	int x;
	cin >> x;
	cout << pcount(x) << '\n';
}
#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
	int a,b;
	cin >> a >> b;
	a = min(a,b);
	long long i = 1;
	for(;a>=1;a--)
		i *= a;
	cout << i << '\n';
}
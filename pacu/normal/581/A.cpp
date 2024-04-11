#include <iostream>
using namespace std;

int main()
{
	int a,b;
	cin >> a >> b;
	int m = min(a,b);
	cout << m << ' ';
	a -= m;
	b -= m;
	cout << (a+b)/2 << '\n';
}
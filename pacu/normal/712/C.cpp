#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
	int x,y;
	cin >> x >> y;
	int a = y;
	int b = y;
	int c = y;
	int t = 0;
	for(;a!=x || b!=x || c != x;t++)
	{
		if(a<=b && a<=c) a = min(x,b+c-1);
		else if(b<=a && b<=c) b = min(x,a+c-1);
		else c = min(x,a+b-1);
		//cout << a << ' ' << b << ' ' << c << '\n';
	}
	cout << t << '\n';
}
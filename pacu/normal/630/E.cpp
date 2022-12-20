#include <iostream>
using namespace std;

int main()
{
	long long x1,y1,x2,y2;
	cin >> x1 >> y1 >> x2 >> y2;
	cout << (x2+1-x1)*((y2-y1)/2) + (x2-x1)/2 + 1 << '\n';
}
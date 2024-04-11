#include <iostream>
#include <iomanip>
using namespace std;

int main()
{
	int D,L,v1,v2;
	cin >> D >> L >> v1 >> v2;
	cout << fixed << setprecision(20) << (L-D)/(((double)v1)+v2) << '\n';
}
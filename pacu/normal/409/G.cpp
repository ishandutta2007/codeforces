#include <iostream>
#include <iomanip>
using namespace std;

int main()
{
	int N;
	double x,y;
	double sm = 0;
	cin >> N;
	for(int i=0;i<N;i++)
	{
		cin >> x >> y;
		sm += y;
	}
	sm /= N;
	cout << setprecision(10) << 5 + sm << '\n';
}
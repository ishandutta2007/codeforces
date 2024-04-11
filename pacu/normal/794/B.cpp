#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;

int main()
{
	int N,H;
	cin >> N >> H;
	for(int i=1;i<N;i++)
		cout << setprecision(20) << H*sqrt(i/((double)N)) << ' ';
	cout << '\n';
}
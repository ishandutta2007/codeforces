#include <iostream>
#include <cmath>
using namespace std;

double rad[11][11];

int main()
{
	double x;
	cin >> x;
	for(int i=1;i<=10;i++)
		for(int j=1;j<=10;j++)
			rad[i][j] = (i*j/2.0)/sqrt(i*i+j*j/4.0);
	int ai = 1;
	int aj = 1;
	for(int i=1;i<=10;i++)
		for(int j=1;j<=10;j++)
			if(abs(x-rad[i][j]) < abs(x-rad[ai][aj]))
				ai = i, aj = j;
	cout << aj << ' ' << ai << '\n';
}
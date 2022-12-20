#include <iostream>
#include <iomanip>
#include <set>
using namespace std;

double f[100];
int k[100];
double cpw[100];
int N;

double calc(int i)
{
	return (1-cpw[i]*f[i])/(1-cpw[i]);
}

int main()
{
	cin >> N;
	int c;
	int highInc = 0;
	double P = 1;
	for(int i=0;i<N;i++)
	{
		cin >> c;
		cpw[i] = f[i] = 1.0-(c/100.0);
		k[i] = 1;
		if(calc(i) > calc(highInc))
			highInc = i;
		P *= (1-f[i]);
	}
	double expval = 0;
	double oldP;
	for(int i=1;i<=300000;i++)
	{
		oldP = P;
		P *= calc(highInc);
		//cout << highInc << '\n';
		k[highInc]++;
		cpw[highInc] *= f[highInc];
		expval += i*(P-oldP);
		for(int j=0;j<N;j++)
			if(calc(j)>calc(highInc))
				highInc = j;
	}
	cout << fixed << setprecision(20) << expval+N << '\n';
}
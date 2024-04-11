#include <iostream>
#include <cmath>
using namespace std;

int A[250];

void test()
{
	for(int i=0;i<250;i++)
		cin >> A[i];
	double mu = 0;
	for(int i=0;i<250;i++)
		mu += A[i];
	mu /= 250.0;
	double var = 0.0;
	for(int i=0;i<250;i++)
		var += (A[i]-mu)*(A[i]-mu);
	var /= 250.0;
	if(abs(mu-var) < abs((mu*(mu+1))/3 - var))
		cout << "poisson\n";
	else
		cout << "uniform\n";
}

int main()
{
	int N;
	cin >> N;
	for(int i=0;i<N;i++)
		test();
}
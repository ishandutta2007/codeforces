#include <iostream>
#include <algorithm>
#include <iomanip>
#include <cmath>
using namespace std;

int N;
long long x[1000];
long long y[1000];

double dist(int i,int j,int k)
{
	double num = abs((double)((y[k]-y[j])*x[i] - (x[k]-x[j])*y[i] + x[k]*y[j] - y[k]*x[j]));
	double den = sqrt((y[k]-y[j])*(y[k]-y[j]) + (x[k]-x[j])*(x[k]-x[j]));
	return num/den;
}

int main()
{
	cin >> N;
	for(int i=0;i<N;i++)
		cin >> x[i] >> y[i];
	double ans = 4000000000.0;
	for(int i=0;i<N;i++)
		ans = min(ans,dist(i,(i+N-1)%N,(i+1)%N));
	cout << setprecision(20) << ans/2.0 << '\n';
}
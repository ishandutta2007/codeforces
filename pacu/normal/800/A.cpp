#include <iostream>
#include <algorithm>
#include <iomanip>
using namespace std;

int N,P;
int A[100000];
int B[100000];

bool pos(double t)
{
	double req = 0.0;
	for(int i=0;i<N;i++)
		req += max(0.0,A[i] - B[i]/t);
	return req <= P;
}

int main()
{
	cin >> N >> P;
	for(int i=0;i<N;i++)
		cin >> A[i] >> B[i];
	double low = 0.0;
	double high = 1.0e12;
	if(pos(high)) cout << -1 << '\n';
	else
	{
		for(int i=0;i<100;i++)
		{
			double mid = (low+high)/2;
			if(pos(mid)) low = mid;
			else high = mid;
		}
		cout << setprecision(10) << low << '\n';
	}
}
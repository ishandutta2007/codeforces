#include <cmath>
#include <iostream>
#include <iomanip>
using namespace std;

int main()
{
	int N,R;
	cin >> N >> R;
	double ans = 0;
	double root = pow(2,0.5);
	for(int i=0;i<N;i++)
	{
		double cur = 0;
		cur += 2-2*root;
		if(i>0) cur += 2-root;
		if(i<N-1) cur += 2-root;
		cur += 2.0*N*root;
		cur += ((double)i*((double)i-1.0));
		cur += (((double)N-i-2.0)*((double)N-i-1.0));
		cur /= ((double)N)*N;
		cur *= R;
		ans += cur;
	}
	cout << fixed << setprecision(20) << ans << '\n';
}
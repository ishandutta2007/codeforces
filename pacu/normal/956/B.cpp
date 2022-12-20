#include <iostream>
#include <iomanip>
#include <algorithm>
using namespace std;

int N,U;
int E[100000];

int main()
{
	cin >> N >> U;
	for(int i=0;i<N;i++)
		cin >> E[i];
	double best = -1.0;
	int k = N-1;
	for(int i=N-2;i>=0;i--)
	{
		while(E[k] - E[i] > U)
			k--;
		if(k - i < 2) continue;
		best = max(best, (E[k]-E[i+1])/((double)(E[k]-E[i])));
	}
	if(best < 0) cout << -1 << '\n';
	else cout << setprecision(20) << best << '\n';
}
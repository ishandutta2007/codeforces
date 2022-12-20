#include <iostream>
#include <iomanip>
#include <algorithm>
using namespace std;

int main()
{
	int N;
	long long l;
	long long A[1000];
	double ans = 0;
	cin >> N >> l;
	for(int i=0;i<N;i++)
		cin >> A[i];
	sort(A,A+N);
	ans = (long double)max(A[0],l-A[N-1]);
	for(int i=1;i<N;i++)
		ans = max(ans,0.5*(A[i]-A[i-1]));
	cout << setprecision(20) << ans << endl;
}
#include <iostream>
#include <algorithm>
using namespace std;

long long A[3000];

int main()
{
	int N;
	cin >> N;
	for(int i=0;i<N;i++)
		cin >> A[i];
	sort(A,A+N);
	long long ans = 0;
	for(int i=1;i<N;i++)
	{
		ans += max(0LL,A[i-1]+1-A[i]);
		A[i] = max(A[i],A[i-1]+1);
	}
	cout << ans << endl;
}
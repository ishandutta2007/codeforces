#include <iostream>
#include <algorithm>
using namespace std;

int A[100000];
int N,K;

int main()
{
	cin >> N >> K;
	for(int i=0;i<N;i++)
		cin >> A[i];
	for(int i=1;i<N;i++)
		if(A[i]%K != A[0]%K)
		{
			cout << -1 << '\n';
			return 0;
		}
	int low = 1000000000;
	for(int i=0;i<N;i++)
		low = min(low,A[i]);
	long long ans = 0;
	for(int i=0;i<N;i++)
		ans += (A[i]-low)/K;
	cout << ans << '\n';
}
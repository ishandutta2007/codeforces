#include <iostream>
using namespace std;

int A[100000];
int N,K;

int main()
{
	cin >> N >> K;
	for(int i=0;i<N;i++)
		cin >> A[i];
	int ans = 0;
	int j = N-1;
	while(j>=0 && j+1 < 2*K)
	{
		ans = max(ans,A[j]);
		j--;
		K--;
	}
	for(int i=0;i<j;i++)
	{
		ans = max(ans,A[i]+A[j]);
		j--;
	}
	cout << ans << '\n';
}
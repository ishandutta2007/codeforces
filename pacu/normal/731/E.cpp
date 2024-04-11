#include <iostream>
#include <algorithm>
using namespace std;

int N;
int A[200000];
long long s[200000];
long long dp[200000];

int main()
{
	cin >> N;
	for(int i=0;i<N;i++) cin >> A[i];
	s[0]= A[0];
	for(int i=1;i<N;i++) s[i] = s[i-1] + A[i];
	dp[N-1] = 0;
	long long mx = s[N-1] - dp[N-1];
	for(int i=N-2;i>=0;i--)
	{
		dp[i] = mx;
		mx = max(mx,s[i]-dp[i]);
	}
	cout << dp[0] << '\n';
}
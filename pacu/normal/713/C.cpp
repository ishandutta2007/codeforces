#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

long long dp[3000][3000];
int A[3000];

int main()
{
	int N;
	cin >> N;
	vector<int> v;
	for(int i=0;i<N;i++)
	{
		cin >> A[i];
		A[i] -= i;
		v.push_back(A[i]);
	}
	sort(v.begin(),v.end());
	v.resize(distance(v.begin(),unique(v.begin(),v.end())));
	for(int i=0;i<v.size();i++)
		dp[0][i] = abs(A[0]-v[i]);
	for(int j=1;j<N;j++)
	{
		long long low = 1000000000000000LL;
		for(int i=0;i<v.size();i++)
		{
			low = min(low,dp[j-1][i]);
			dp[j][i] = abs(A[j]-v[i])+low;
		}
	}
	long long ans = 1000000000000000LL;
	for(int i=0;i<v.size();i++)
		ans = min(ans,dp[N-1][i]);
	cout << ans << '\n';
}
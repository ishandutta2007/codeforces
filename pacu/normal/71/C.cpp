#include <iostream>
#include <vector>
#include <string>
using namespace std;

vector<int> factors;
int dp[100000];

int main()
{
	int N;
	int A[100000];
	cin >> N;
	for(int i=0;i<N;i++)
		cin >> A[i];
	for(int i=1;2*i<N;i++)
		if(!(N%i))
			factors.push_back(i);
	for(int i=0;i<factors.size();i++)
	{
		int mx = 0;
		for(int j=0;j<N;j++)
		{
			if(A[j]==0) dp[j] = 0;
			else if(j<factors[i]) dp[j] = 1;
			else dp[j] = 1+dp[j-factors[i]];
			mx = max(mx,dp[j]);
		}
		if(mx*factors[i] == N)
		{
			cout << "YES\n";
			return 0;
		}
	}
	cout << "NO" << endl;
	return 0;
}
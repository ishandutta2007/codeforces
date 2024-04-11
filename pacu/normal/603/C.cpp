#include <iostream>
using namespace std;

int A[100000];
int K;
int N;

int dp[100001];

int main()
{
	cin >> N >> K;
	for(int i=0;i<N;i++)
		cin >> A[i];
	if(K%2)
	{
		dp[0] = 0;
		dp[1] = 1;
		dp[2] = 0;
		dp[3] = 1;
		dp[4] = 2;
		dp[5] = 0;
		int ans = 0;
		for(int i=0;i<N;i++)
		{
			int c = A[i];
			while(!(c%2) && c>=6)
				c /= 2;
			int cur;
			if(c < 6)
				cur = dp[c];
			else cur = 0;
			while(c != A[i])
			{
				c *= 2;
				if(cur==1) cur = 2;
				else cur = 1;
			}
			ans ^= cur;
//			cout << cur << ' ';
		}
		if(ans == 0) cout << "Nicky\n";
		else cout << "Kevin\n";
	}
	else
	{
		dp[0] = 0;
		dp[1] = 1;
		dp[2] = 2;
		dp[3] = 0;
		dp[4] = 1;
		int ans = 0;
		for(int i=0;i<N;i++)
		{
			if(A[i] < 5) ans ^= dp[A[i]];
			else if(A[i]%2) ans ^= 0;
			else ans ^= 1;
		}
		if(ans == 0) cout << "Nicky\n";
		else cout << "Kevin\n";
	}
}
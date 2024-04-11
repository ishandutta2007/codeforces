#include <iostream>
#include <algorithm>
using namespace std;

int N,P,K;
int A[2000];
int B[2000];
int AB[2000];
int smA[2000];
int smB[2000];
int smAB[2000];

int *dp[2000][2000];

int main()
{
	cin.tie(0);
	ios::sync_with_stdio(0);
	cin >> N >> P >> K;
	P = min(P,2*((N+K-1)/K));
	int num,c;
	cin >> num;
	for(int i=0;i<num;i++)
	{
		cin >> c;
		A[c] = 1;
		AB[c] = 1;
	}
	cin >> num;
	for(int j=0;j<num;j++)
	{
		cin >> c;
		B[c] = 1;
		AB[c] = 1;
	}
	smA[0] = A[0], smB[0] = B[0], smAB[0] = AB[0];
	for(int i=0;i<=N+K;i++)
		smA[i] = A[i] + smA[i-1], smB[i] = B[i] + smB[i-1], smAB[i] = AB[i] + smAB[i-1];
	int back = 0;
	for(int i=0;i<=N+K;i++)
	{
		for(int j=0;j<=N+K;j++)
			if(abs(i-j)<=K)
			{
				//cout << i << ' ' << j << '\n';
				dp[i][j] = new int[P+1];
				for(int p=0;p<=P;p++)
					dp[i][j][p] = 0;
				if(i<=j) dp[i][j][0] = smA[j] - smA[i];
				else dp[i][j][0] = smB[i] - smB[j];
				if(i==0 || j==0) continue;
				if(i<K && j<K)
				{
					for(int p=1;p<=P;p++)
						dp[i][j][p] = 0;
				}
				else if(i<K)
				{
					for(int p=1;p<=P;p++)
						dp[i][j][p] = max(A[j] + dp[i][j-1][p],smAB[j]-smAB[i]+dp[i][j-K][p-1]);
				}
				else if(j<K)
				{
					for(int p=1;p<=P;p++)
						dp[i][j][p] = max(B[i] + dp[i-1][j][p],smAB[i]-smAB[j]+dp[i-K][j][p-1]);
				}
				else if(i<j)
				{
					for(int p=1;p<=P;p++)
						dp[i][j][p] = max(dp[i][j-K][p-1] + smAB[j] - smAB[i], A[j] + dp[i][j-1][p]);
				}
				else if(i>j)
				{
					for(int p=1;p<=P;p++)
						dp[i][j][p] = max(dp[i-K][j][p-1] + smAB[i] - smAB[j], B[i] + dp[i-1][j][p]);
				}
				else
				{
					for(int p=2;p<=P;p++)
						dp[i][j][p] = max(max(dp[i-K][j-K][p-2] + smAB[i] - smAB[i-K], dp[i-1][j-1][p]), max(dp[i-K][j][p-1], dp[i][j-K][p-1]));
					dp[i][j][1] = max(dp[i-1][j-1][1], max(dp[i-K][j][0], dp[i][j-K][0]));
				}
			}
		if(i-back >= K)
		{
			for(int j=0;j<=N-K;j++)
				if(abs(back-j)<=K)
					delete [] dp[back][j];
			back++;
		}
	}
	int ans = 0;
	for(int p=1;p<=P;p++)
		ans = max(ans,dp[N+K][N+K][p]);
	cout << ans << '\n';
}
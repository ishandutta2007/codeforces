#include <iostream>
using namespace std;

int A[100];
int N,T;

int dp2[301][301];
int dp[100][100];
int tmp[100];
int sdp[301][301],edp[301][301];

int main()
{
	cin >> N >> T;
	for(int i=0;i<N;i++)
		cin >> A[i];
	for(int i=0;i<N;i++)
		dp[i][i] = 1, dp2[A[i]][A[i]] = 1;
	for(int i=0;i<N;i++)
		for(int j=i+1;j<N;j++)
		{
			if(A[j]<A[i])
				continue;
			for(int k=i;k<j;k++)
				if(A[k]<=A[j])
					dp[i][j] = max(dp[i][j],dp[i][k]+1);
			dp2[A[i]][A[j]] = max(dp2[A[i]][A[j]],dp[i][j]);
		}
	for(int i=300;i>=1;i--)
		for(int j=i+1;j<=300;j++)
			dp2[i][j] = max(dp2[i][j],max(dp2[i][j-1],dp2[i+1][j]));
	for(int len=1;len<=300;len++)
		for(int i=1;i<=300;i++)
			for(int j=1;j<i;j++)
				sdp[i][len] = max(sdp[i][len],sdp[j][len-1]+dp2[j][i]);
	for(int len=1;len<=300;len++)
		for(int i=1;i<=300;i++)
			for(int j=i+1;j<=300;j++)
				edp[i][len] = max(edp[i][len],edp[j][len-1]+dp2[i][j]);
	int ans = 0;
	for(int i=1;i<=300;i++)
		for(int len1=0;len1<=300;len1++)
			for(int len2=0;len2<=300 && len1+len2<=T;len2++)
			{
				ans = max(ans,sdp[i][len1]+edp[i][len2]+(T-len1-len2)*dp2[i][i]);
			}
	cout << ans << '\n';
}
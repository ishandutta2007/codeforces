#include <bits/stdc++.h>
using namespace std;
int ncnt=1;
int gt[6500000][2];
int dp[6500000];
int sz[6500000];
int arr[200001];
int n,m,i,j,k,t,u,v,a,b;
void dfs(int g)
{
    if (gt[g][0]) dfs(gt[g][0]);
    if (gt[g][1]) dfs(gt[g][1]);
    if (sz[g]<=1) dp[g]=1;
    else
    dp[g]=max(dp[gt[g][0]]+min(sz[gt[g][1]],1),dp[gt[g][1]]+min(sz[gt[g][0]],1));
  ///  cout<<g<<' '<<sz[g]<<' '<<gt[g][0]<<' '<<gt[g][1]<<' '<<dp[g]<<endl;
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>n;
    for (i=1;i<=n;i++)
    {
        cin>>arr[i];
            u=1;
        
            sz[u]++;
		for (j=29;j>=0;j--)
        {
	//		cout<<(((arr[i])>>j)%2);
            if (!gt[u][((arr[i]>>j)%2)])
            {
                ncnt++;
                gt[u][((arr[i]>>j)%2)]=ncnt;
            }
            u=gt[u][((arr[i]>>j)%2)];
            sz[u]++;
        }
  //      cout<<endl;
    }
    dfs(1);
    cout<<n-dp[1];
}
#include <bits/stdc++.h>
using namespace std;

long long dp[505][505];
int n,m,mod,r2,r1;
int col[505];
string s;
long long solve(int i,int j)
{
    if (dp[i][j]!=-1) return dp[i][j];
    long long ans=0;
    if (i+2<=n && j-2>=0)
    {
        ans+=solve(i+2,j-2)*((i+2)*(i+1)/2);
        //if (i==0 && j==0) cout<<ans;
        ans%=mod;
    }
    if (i+1<=n)
    {
        ans+=solve(i+1,j)*(i+1)*j;//if (i==0 && j==0) cout<<ans;
        ans%=mod;
    }
    if (j+2<=n)
    {
        ans+=solve(i,j+2)*((j+2)*(j+1)/2);//if (i==0 && j==0) cout<<ans;
        ans%=mod;
    }
    dp[i][j]=ans;
    return ans;
}
int main()
{
    //freopen("input.txt","r",stdin);
    ios::sync_with_stdio(0);
    cin>>n>>m>>mod;
    for (int i=0;i<n;i++) col[i]=2;
    r2=0;
    r1=0;
    while (m--)
    {
        cin>>s;
        for (int i=0;i<n;i++) if(s[i]=='1') col[i]--;
    }
    for (int i=0;i<n;i++)
    {
        if (col[i]==1) r1++;
        else if (col[i]==2) r2++;
    }
    for (int i=0;i<=n;i++)
    {
        for (int j=0;j<=n;j++) dp[i][j]=-1;
    }
    dp[r2][r1]=1;
    //cout<<r2<<r1<<endl;
    cout << solve(0,0);
    return 0;
}
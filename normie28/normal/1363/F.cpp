#include <bits/stdc++.h>
using namespace std;
string s,t;
int n,m,i,j,k,u,v,a,b,dp[3001][3001];
int presums[26][3001],presumt[26][3001];
int aa,bb;
int main()
{
    cin>>aa;
    for (bb=0;bb<aa;bb++)
    {
    cin>>n>>s>>t;
    string s1=s,t1=t;
    sort(s1.begin(),s1.end());
    sort(t1.begin(),t1.end());
    if (s1!=t1) {cout<<-1<<endl; continue;}
    for (i=1;i<=n;i++)
    {
        for (j=0;j<26;j++) presums[j][i]=presums[j][i-1];
        presums[s[i-1]-97][i]++;
    }
    for (i=1;i<=n;i++)
    {
        for (j=0;j<26;j++) presumt[j][i]=presumt[j][i-1];
        presumt[t[i-1]-97][i]++;
    }
    for (i=n;i>=0;i--) for (j=n;j>=0;j--)
    {
        dp[i][j]=-1e9;
        if ((i==n)or(j==n)) {dp[i][j]=0;continue;}
        int fail=0;
        for (k=0;k<26;k++) if (presums[k][i]>presumt[k][j]) fail=1;
        if ((s[i]==t[j])and(!fail)) dp[i][j]=max(dp[i][j],dp[i+1][j+1]+1);
        dp[i][j]=max(dp[i][j],dp[i+1][j]);
        dp[i][j]=max(dp[i][j],dp[i][j+1]);
    }
    cout<<n-dp[0][0]<<endl;
    }
}
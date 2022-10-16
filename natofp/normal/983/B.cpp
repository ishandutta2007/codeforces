#include <iostream>

using namespace std;

int naj(int a,int b,int c)
{
    int m=a;
    if(m<b) m=b;
    if(m<c) m=c;
    return m;
}

int main()
{
  ios_base::sync_with_stdio(0);
cin.tie(0);
    int ** dp;

int n;
    cin>>n;
    dp=new int*[n];
    for(int i=0;i<n;i++)
        dp[i]=new int[n];
    for(int i=0;i<n;i++)
        cin>>dp[0][i];
    for(int i=1;i<n;i++)
        for(int j=0;j<n-i;j++)
            dp[i][j]=dp[i-1][j]^dp[i-1][j+1];
    for(int i=1;i<n;i++)
        for(int j=0;j<n-i;j++)
            dp[i][j]=naj(dp[i][j],dp[i-1][j],dp[i-1][j+1]);

    int q;
    cin>>q;
    for(int i=0;i<q;i++)
    {

        int l,r;
        cin>>l>>r;
        l--;
        int d=r-l-1;
        cout<<dp[d][l]<<"\n";
    }
    for(int i=0;i<n;i++)
        delete dp[i];
    delete dp;
    return 0;
}
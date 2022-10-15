#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
double a[25][25];
double dp[1<<20];
int main() {
    int n;
    cin>>n;
    for(int i=0;i<n;i++)
        for(int j=0;j<n;j++)
        cin>>a[i][j];
    dp[(1<<n)-1]=1;
    for(int i=(1<<n)-1;i>=0;i--)
    {
        int cnt=0;
        for(int j=0;j<n;j++)
        {
            if(((1<<j)&i)) cnt++;
        }
        for(int k=0;k<n;k++)
        {
            for(int kk=0;kk<n;kk++)
            {
                if(k==kk) continue;
                if((i&(1<<k))==0||(i&(1<<kk))==0) continue;
                dp[i^(1<<k)]+=a[kk][k]*dp[i]/(cnt*(cnt-1)/2);
            }
        }
    }
    for(int i=0;i<n;i++)
    {
        cout<<fixed<<setprecision(8)<<dp[1<<i]<<' ';
    }
}
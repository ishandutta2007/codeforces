#include <bits/stdc++.h>
typedef long long ll;
using namespace std;
int a[101][101][2];
ll dp[101][101][2];
int main()
{
    ll n,t;cin>>n>>t;n++;
    if ((t&(t-1ll))){
        cout<<0;
        return 0;
    }
    int cnt=0;
    while (t>1){
        t/=2ll;
        cnt++;
    }
    vector<int>v;
    while (n){
        v.push_back(n%2);
        n/=2ll;
    }
    reverse(v.begin(),v.end());
    if (cnt==0){
        cout<<(int)v.size()-1;
        return 0;
    }
    dp[0][0][0]=1ll;
    dp[0][1][1]=1ll;
    int sum=v[0];
    cnt++;
    for (int i=1;i<v.size();i++){
        sum+=v[i];
        dp[i][sum][1]=1ll;
        dp[i][0][0]=1ll;
        for (int j=1;j<=100;j++){
             dp[i][j][0]=(dp[i-1][j][0]+dp[i-1][j-1][0])*1ll;
             if (v[i]) dp[i][j][0]+=dp[i-1][j][1]*1ll;

        }
    }
    cout<<dp[(int)v.size()-1][cnt][0]+dp[(int)v.size()-1][cnt][1];
    /*int m;cin>>m;
    for (int i=1;i<=m;i++) a[1][i]=0;
    a[1][m+1]=1;
    for (int i=2;i<=m+1;i++){
        for (int j=1;j<=m+1;j++){
            if (j==1) a[i][j]=a[i-1][j+1];
            else if (j==m+1) a[i][j]=a[i-1][j-1];
            else a[i][j]=(a[i-1][j-1]^a[i-1][j+1]);
        }
    }
    for (int i=1;i<=m+1;i++){
        int sum=0;
        for (int j=1;j<=m+1;j++){
            sum+=a[i][j];
            //cout<<a[i][j]<<" ";
        }
        cout<<sum<<",";
    }*/
    return 0;
}
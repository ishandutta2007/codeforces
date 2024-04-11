#pragma GCC optimize ("Ofast")
#include <bits/stdc++.h>
#define endl '\n'
//#define int long long
typedef long long ll;
using namespace std;
int dp[53][53][53][53];
int s[53][53];
int get(int l1,int r1,int l2,int r2){
    return s[r1][r2]-s[l1-1][r2]-s[r1][l2-1]+s[l1-1][l2-1];
}
int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n;cin>>n;
    for (int i=1;i<=n;i++){
        for (int j=1;j<=n;j++){
            char c;cin>>c;
            s[i][j]=s[i][j-1]+(c=='#');
        }
        for (int j=1;j<=n;j++) s[i][j]+=s[i-1][j];
    }
    for (int t1=1;t1<=n;t1++){
        for (int t2=1;t2<=n;t2++){
            for (int l1=1;l1+t1-1<=n;l1++){
                for (int l2=1;l2+t2-1<=n;l2++){
                    int r1=l1+t1-1;
                    int r2=l2+t2-1;
                    if (!get(l1,r1,l2,r2)){
                        dp[l1][r1][l2][r2]=0;
                        continue;
                    }
                    dp[l1][r1][l2][r2]=max(r1-l1+1,r2-l2+1);
                    for (int i=l1;i<r1;i++){
                        dp[l1][r1][l2][r2]=min(dp[l1][r1][l2][r2],dp[l1][i][l2][r2]+dp[i+1][r1][l2][r2]);
                    }
                    for (int i=l2;i<r2;i++){
                        dp[l1][r1][l2][r2]=min(dp[l1][r1][l2][r2],dp[l1][r1][l2][i]+dp[l1][r1][i+1][r2]);
                    }
                }
            }
        }
    }
    cout<<dp[1][n][1][n];
    return 0;
}
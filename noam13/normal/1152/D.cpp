#include<bits/stdc++.h>
#define int int64_t
#define vi vector<int>
#define ii pair<int,int>
#define x first
#define y second
#define mp make_pair
#define pb push_back
#define loop(i,s,e) for(int i=(s);i<(e);i++)
#define chkmin(a,b) a=min((int)(a),(int)(b))
#define chkmax(a,b) a=max(a,b)
using namespace std;
const int INF=4*1e18;
const int MOD=1e9+7;




int32_t main(){
    int n;cin>>n;
    vector<vi> dp(n+1,vi(n+1,0)) ;
    loop(i,0,n+1){
        for(int j=min(n,i);j>=0;j--){
            if (i==j) dp[i][j]=(i+1)/2;
            else if (j==0) dp[i][j]=dp[i][j+1];
            else dp[i][j]=(dp[i][j+1]+dp[i-1][j-1]+(j%2?1:0))%MOD;
        }
    }
    cout<< dp[n][0] <<endl;
    return 0;
}
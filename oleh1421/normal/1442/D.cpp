#include <bits/stdc++.h>
typedef long long ll;
#define endl '\n'
using namespace std;
const int N=3010;
const ll mod=998244353;
ll a[N][N];
int l[N];
ll dp[N][N];
ll dp1[N][N];
ll S[N];
bool take[N][N];
void solve(){
    int n,k;cin>>n>>k;
    for (int i=1;i<=n;i++){
        cin>>l[i];
        ll sum=0ll;
        for (int j=1;j<=l[i];j++){
            int x;cin>>x;
            if (j<=k) {
                a[i][j]=x;
                sum+=x;
            }
        }
        l[i]=min(l[i],k);
        S[i]=sum;
    }
    for (int i=1;i<=n;i++){
        for (int j=0;j<l[i];j++) dp[i][j]=dp[i-1][j],take[i][j]=false;
        for (int j=k;j>=l[i];j--){
            dp[i][j]=max(dp[i-1][j],dp[i-1][j-l[i]]+S[i]);
            if (dp[i-1][j]>dp[i-1][j-l[i]]+S[i]) take[i][j]=false;
            else take[i][j]=true;
        }
    }
    for (int i=n;i>=1;i--){
        for (int j=0;j<l[i];j++) dp1[i][j]=dp1[i+1][j];
        for (int j=k;j>=l[i];j--){
            dp1[i][j]=max(dp1[i+1][j],dp1[i+1][j-l[i]]+S[i]);
        }
    }
    for (int i=1;i<=n;i++){
        for (int j=1;j<=k;j++){
            a[i][j]+=a[i][j-1];
        }
    }
//    cout<<dp1[2][2]<<endl;
    ll res=dp[n][k];
    for (int it=1;it<=k;it++){
        vector<int>v,u;
        int cur=it;
        for (int i=n;i>=1;i--){
            if (take[i][cur]) {
                v.push_back(i);
                cur-=l[i];
            } else {
                u.push_back(i);
            }
        }
        for (int i:u){
            if (k-it<=l[i]) res=max(res,dp[n][it]+a[i][k-it]);
        }
        for (int i:v){
            int tk=k-it;
            if (tk>l[i]) continue;
            for (int j=0;j<=it;j++){
                res=max(res,a[i][tk]+dp[i-1][j]+dp1[i+1][it-j]);
            }
        }


    }
    cout<<res<<endl;



}
int main()
{

    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int tt=1;
    while (tt--){
        solve();
    }
    return 0;
}
/*
1
7 4
1 4 7 3 6 2 5
3 2 4 5
*/
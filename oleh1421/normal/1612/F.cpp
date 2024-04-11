//#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
typedef long long ll;
typedef long double ld;
//#define int ll
#define endl '\n'
using namespace std;
const int N=200010;
const int A=55;
const ll mod=1000000007ll;
int a[N],b[N];
int dp[N][A+1];
map<int,int>mp[N];
void solve(){
    int n,m,q;cin>>n>>m>>q;
    for (int i=1;i<=q;i++){
        cin>>a[i]>>b[i];
    }
    if (n>m){
        swap(n,m);
        for (int i=1;i<=q;i++) swap(a[i],b[i]);
    }
    for (int i=1;i<=q;i++) mp[a[i]][b[i]]++;
    dp[1][0]=1;
    for (int i=1;i<=n;i++){
        for (int j=0;j<A;j++){
            if (dp[i][j]){
                int s=i+dp[i][j]+mp[i][dp[i][j]];
                dp[i][j+1]=max(dp[i][j+1],min(s,m));
                dp[min(s,n)][j+1]=max(dp[min(s,n)][j+1],dp[i][j]);
//                i,dp[i][j]
            }
        }
    }
    int ans=-1,j=-1;
    for (int i=0;i<=A;i++){
        if (dp[n][i]){
            ans=i;
            j=dp[n][i];
            break;
        }
    }
    while (j<m){
        j+=n+mp[n][j];
        ans++;
    }
    cout<<ans<<endl;
}
int32_t  main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int tt=1;
    while (tt--){
        solve();
    }
    return 0;
}

/**
11 3
1 2
2 3
3 4
4 5
5 6
6 7
4 8
8 9
9 10
10 11
**/
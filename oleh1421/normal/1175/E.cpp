#include <bits/stdc++.h>
typedef long long ll;
#define endl '\n'
///#define int long long
using namespace std;
const int N=500000;
const int L=25;
int r[N+11];
int a[N+11];
int dp[L+1][N+11];
int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    vector<pair<int,int> >v;
    int n,tt;cin>>n>>tt;
    for (int i=1;i<=n;i++){
        int l,r;cin>>l>>r;
        v.push_back({l,r});
    }
    sort(v.begin(),v.end());
    for (auto cur:v) a[cur.first]=cur.second;
    r[0]=a[0];
    for (int i=1;i<=N;i++){
        r[i]=max({r[i-1],a[i],i});
    }
    for (int i=0;i<=N;i++) dp[0][i]=r[i];
    for (int i=1;i<=L;i++){
         for (int j=0;j<=N;j++){
              dp[i][j]=dp[i-1][dp[i-1][j]];
         }
    }
    while (tt--){
        int l,r;cin>>l>>r;
        if (dp[L][l]<r) cout<<-1<<endl;
        else {
            int res=0;
            for (int i=L;i>=0;i--){
                if (dp[i][l]<r){
                    res+=(1<<i);
                    l=dp[i][l];
                }
            }
            cout<<res+1<<endl;
        }
    }
    return 0;
}
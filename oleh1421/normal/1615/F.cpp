#include <bits/stdc++.h>
typedef long long ll;
#define endl '\n'
#define int ll
using namespace std;
const int N=2010;
const ll mod=1000000007;
int a[N],b[N];
ll dp[N][N*4];
ll cnt[N][N*4];
void solve(){
    int n;cin>>n;
    for (int i=1;i<=n;i++){
        char c;cin>>c;
        if (c=='1') a[i]=1;
        else if (c=='0') a[i]=0;
        else a[i]=-1;
    }
    for (int i=1;i<=n;i++){
        char c;cin>>c;
        if (c=='1') b[i]=1;
        else if (c=='0') b[i]=0;
        else b[i]=-1;
    }

    for (int i=0;i<=n+1;i++){
        memset(dp[i],0,sizeof(dp[i]));
        memset(cnt[i],0,sizeof(cnt[i]));
    }

    dp[0][N*2]=0;
    cnt[0][N*2]=1;
    for (int i=0;i<n;i++){
        for (int bal=-n*2;bal<=n*2;bal++){
            for (int x=0;x<2;x++){
                for (int y=0;y<2;y++){
                    if (x==(a[i+1]^1)) continue;
                    if (y==(b[i+1]^1)) continue;
                    int cur=x*(1-(i%2)*2)+y*((i%2)*2-1);
                    ll S;
                    if (1ll*bal*cur>=0) S=i*abs(cur);
                    else S=mod-i*abs(cur);
//                    cout<<i<<" "<<bal+cur<<" "<<x<<" "<<y<<" "<<S<<" "<<cnt[i][bal+N*2]<<endl;
                    cnt[i+1][bal+cur+N*2]+=cnt[i][bal+N*2];
                    cnt[i+1][bal+cur+N*2]%=mod;
//                    cout<<cnt[i+1][bal+cur+N*2]<<endl;
                    dp[i+1][bal+cur+N*2]+=dp[i][bal+N*2]+cnt[i][bal+N*2]*S;
                    dp[i+1][bal+cur+N*2]%=mod;
                }
            }
        }
    }
    cout<<(mod-dp[n][N*2])%mod<<endl;

}
int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int tt;cin>>tt;
    while (tt--){
        solve();
    }
    return 0;
}
/**

4
3 3
1 2 -1
1 3 -1
1 2 0
1 3 1
2 3 0
2 1
1 2 1
1 2 0
6 5
1 2 -1
1 3 1
4 2 7
6 3 0
2 5 -1
2 3 1
2 5 0
5 6 1
6 1 1
4 5 1
5 3
1 2 -1
1 3 -1
1 4 1
4 5 -1
2 4 0
3 4 1
2 3 1


**/
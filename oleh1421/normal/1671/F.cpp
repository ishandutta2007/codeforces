#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#define endl '\n'
using namespace __gnu_pbds;
typedef long double ld;
#define int ll
using namespace std;
mt19937 rnd(time(NULL));
typedef long long ll;
const ll mod=998244353;
const ll inf=1000000000000000001;
ll binpow(ll a,ll b){
    if (!b) return 1;
    if (b%2) return binpow(a,b-1)*a%mod;
    else return binpow(a*a%mod,b/2ll);
}
const int N=36;
ll dp[N][N][N][N];
ll C[N][N];
ll take[N][N][N][N];
ll inv[N];
void solve(){
    int n,k,x;cin>>n>>k>>x;
    if (n<=11){
        ll res=0ll;
        for (int i=0;i<n;i++){
            res+=dp[n][i][x][k];
            res%=mod;
        }
        cout<<res<<endl;
        return;
    }

    ll res=0ll;

    for (int i=0;i<min(N,n+1);i++){
        for (int j=0;j<min(N,n+1);j++){
            //if (take[k][x][i][j]) cout<<i<<" "<<j<<" "<<take[k][x][i][j]<<endl;
            if (take[k][x][i][j]){
                ll C=1;
                for (int t=1;t<=j;t++){
                    C*=(n-i-t+1ll);
                    C%=mod;
                    C*=inv[t];
                    C%=mod;
                }
                res+=C*take[k][x][i][j];
                res%=mod;
            }
            //if (take[k][x][i][j])cout<<res<<endl;
        }
    }
    cout<<res<<endl;
}

int32_t main() {
    inv[0]=0;
    for (int i=1;i<N;i++){
        inv[i]=binpow(i,mod-2);
    }
    int k=11;
    int x=11;

    dp[1][0][0][0]=1;
    for (int i=1;i<k;i++){
        for (int last=0;last<i;last++){
            for (int cn=0;cn<=x;cn++){
                for (int j=0;j<=k;j++){
                    for (int nxt=0;nxt<=i && nxt+j<=k;nxt++){
                        dp[i+1][nxt][cn+(nxt>=(last+1))][j+nxt]+=dp[i][last][cn][j];
                        dp[i+1][nxt][cn+(nxt>=(last+1))][j+nxt]%=mod;
                    }
                }
            }
        }
    }



    ll res=0ll;
    for (int last=0;last<=k;last++){
        for (int cn=0;cn<=x;cn++){
            for (int j=0;j<=k;j++){
                for (int sum=0;sum<=k-j;sum++){
                    if (sum==0){
                        take[j][cn][0][0]+=dp[k][last][cn][j];
                        take[j][cn][0][0]%=mod;
                    } else {
                        for (int mask=0;mask<(1<<(sum-1));mask++){
                            vector<int>u={last};
                            int cur=1;
                            for (int i=0;i<sum-1;i++){
                                if (mask&(1<<i)){
                                    u.push_back(cur);
                                    cur=1;
                                } else cur++;
                            }
                            u.push_back(cur);
                            int sz=u.size();
                            int us=0;
                            for (int i=1;i<u.size();i++){
                                us+=(u[i]>=(u[i-1]+1));
                            }
                            for (int sub=0;sub<(1<<(sz-1));sub++){
                                vector<int>v;
                                int cnt=__builtin_popcount(sub);

                                int val=cn+us;
                                for (int i=0;i<sz-1;i++){
                                    if (sub&(1<<i)){
                                        val-=(u[i+1]>=(u[i]+1));
                                        val+=(u[i+1]>=1);
                                    }
                                }
                                    take[sum+j][val][k+u.size()-1][cnt]+=dp[k][last][cn][j];
                                    take[sum+j][val][k+u.size()-1][cnt]%=mod;

                            }

                        }
                    }
                }
            }
        }
    }
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int tt=0;cin>>tt;
    while (tt--){
        solve();
    }

    return 0;
}

/**
  ,        .
**/
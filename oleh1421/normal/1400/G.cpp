
#include<bits/stdc++.h>
typedef long long ll;
#define endl '\n'
using namespace std;
const int N=300010;
#define int ll
const int mod=998244353;
vector<int>g[N];
int l[N];
int r[N];
int cnt[N];
bool used[N];
vector<int>order;
int pos[N];
void dfs(int v){
    used[v]=true;
    pos[v]=order.size();
    order.push_back(v);
    for (int to:g[v]){
        if (!used[to]){
            dfs(to);
        }
    }
}
vector<int>dp[22][22];
int dp1[110][110];
ll f[N];
ll rf[N];
ll binpow(ll a,ll b){
    if (!b) return 1ll;
    if (b%2) return (binpow(a,b-1)*a)%mod;
    else return binpow((a*a)%mod,b/2);
}
ll C(int n,int k){
    if (k>n || k<0) return 0;
    return (((rf[k]*rf[n-k])%mod)*f[n])%mod;
}
void solve(){
    int n,m;cin>>n>>m;
    f[0]=1ll;
    for (ll i=1;i<=n;i++){
        f[i]=(f[i-1]*i)%mod;
    }
    rf[n]=binpow(f[n],mod-2);
    for (int i=n-1;i>=0;i--){
        rf[i]=(rf[i+1]*(i+1ll))%mod;
    }
    for (int i=1;i<=n;i++) cin>>l[i]>>r[i];
    for (int i=1;i<=m;i++){
        int x,y;cin>>x>>y;
        g[x].push_back(y);
        g[y].push_back(x);
    }
//    if (n>20) exit(1);
//    if (n==1) exit(1);

    vector<vector<int> >comp;
    int empt=0;
    for (int v=1;v<=n;v++){
        if (used[v]) continue;
        if (g[v].empty()){
            cnt[l[v]]++;
            cnt[r[v]+1]--;
            empt++;
        } else {
            int cur=comp.size();
            dfs(v);
            int k=order.size();
            for (int i=0;i<=k;i++){
                dp[cur][i].resize(1<<k);
            }
            for (int mask=0;mask<(1<<k);mask++){
                bool ok=true;
                for (int i=0;i<k;i++){
                    if (mask&(1<<i)){
                        for (int to:g[order[i]]){
                            if (mask&(1<<pos[to])){
                                ok=false;
                            }
                        }
                    }
                }
                if (!ok) continue;
                dp[cur][__builtin_popcount(mask)][mask]++;
            }
            for (int i=0;i<k;i++){
                for (int j=0;j<=k;j++){
                    for (int mask=0;mask<(1<<k);mask++){
                        if (mask&(1<<i)){
                            dp[cur][j][mask]+=dp[cur][j][mask^(1<<i)];
                        }
                    }
                }
            }
            comp.push_back(order);
            order.clear();
        }
    }
//    cout<<comp.size()<<endl;
    for (int i=1;i<=n;i++){
        cnt[i]+=cnt[i-1];
    }
    ll res=0ll;
    for (int sum=1;sum<=n;sum++){
        for (int i=0;i<=20;i++){
            for (int j=0;j<=40;j++){
                dp1[i][j]=0;
            }
        }
        dp1[0][0]=1;
        for (int i=0;i<comp.size();i++){
            int mask=0;
            for (int j=0;j<comp[i].size();j++){
                if (l[comp[i][j]]<=sum && r[comp[i][j]]>=sum){
                    mask|=(1<<j);
                }
            }
            for (int j=0;j<=comp[i].size();j++){
                for (int t=0;t+j<=40;t++){
                    dp1[i+1][j+t]+=((dp1[i][t]*1ll)*(dp[i][j][mask]*1ll));
                    dp1[i+1][j+t]%=mod;
                }
            }
        }
        for (int i=0;i<=40 && i<=sum;i++){
            res+=(dp1[comp.size()][i]*1ll)*C(cnt[sum],sum-i);
            res%=mod;
        }
//        cout<<sum<<" "<<res<<endl;
    }

    cout<<res<<endl;



}
int32_t main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int tt=1;
    while (tt--){
        solve();
    }
    return 0;
}
/*
10 10
6 9
6 7
1 6
10 10
5 9
3 9
2 10
5 7
9 10
5 10
9 10
2 6
1 7
3 8
6 10
5 9
1 5
1 4
5 6
7 8
*/
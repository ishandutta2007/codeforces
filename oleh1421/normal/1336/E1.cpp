//#pragma GCC optimize ("Ofast")
//#pragma GCC optimize ("unroll-loops")
//#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#include <bits/stdc++.h>
typedef long long ll;
typedef long double ld;
///#define endl '\n'
using namespace std;
using namespace __gnu_pbds;
typedef tree<int,null_type,less<int>,rb_tree_tag,tree_order_statistics_node_update> ordered_set;
const int N=200010;
const int c=20;
const ll mod=998244353ll;
ll a[N];
ll cnt[N];
ll dp[2][40][60000];
int pos[40];
bool used[40];
int32_t main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n,m;cin>>n>>m;
    if (m>35) return 1;
    vector<ll>basis;
    for (int i=1;i<=n;i++){
        cin>>a[i];
        ll x=a[i];
        for (auto y:basis){
            x=min(x,x^y);
        }
        if (x){
            for (auto &y:basis){
                y=min(y,y^x);
            }
            basis.push_back(x);
        }
    }
    int sz=basis.size();
    ll res=1ll;
    for (int i=0;i<n-sz;i++){
        res*=2ll;
        res%=mod;
    }
    if (basis.size()<=c){
        for (int mask=0;mask<(1ll<<sz);mask++){
            ll xr=0ll;
            for (int i=0;i<sz;i++){
                if (mask&(1ll<<i)) xr^=basis[i];
            }
            cnt[__builtin_popcountll(xr)]++;
        }
        for (int i=0;i<=m;i++) cout<<(cnt[i]*res)%mod<<" ";
        cout<<endl;
        return 0;

    }
    ll mask_bad=(1ll<<m)-1ll;
    for (auto x:basis){
        int h=m;
        while ((x&(1ll<<h))==0) h--;
        mask_bad^=(1ll<<h);
        used[h]=true;
    }
    vector<int>bad;
    for (int i=0;i<m;i++){
        if (mask_bad&(1ll<<i)){
            bad.push_back(i);
        }
    }
    for (auto &x:basis){
        x&=mask_bad;
        ll y=0ll;
        for (int i=0;i<bad.size();i++){
            if (x&(1ll<<(bad[i]))){
                y^=(1ll<<i);
            }
        }
        x=y;
    }
    dp[0][0][0]=1ll;
    for (int i=0;i<sz;i++){
        int nxt=(i+1)%2;
        for (int j=0;j<=i;j++){
            for (int mask=0;mask<(1ll<<(bad.size()));mask++){
                dp[nxt][j][mask]=0;
            }
        }
        for (int j=0;j<=sz;j++){
            for (int mask=0;mask<(1ll<<(bad.size()));mask++){
                dp[nxt][j][mask]=(dp[nxt][j][mask]+dp[i%2][j][mask])%mod;
                dp[nxt][j+1][mask^basis[i]]=(dp[nxt][j+1][mask^basis[i]]+dp[i%2][j][mask])%mod;
            }
        }
    }
    for (int i=0;i<=sz;i++){
        for (int mask=0;mask<(1ll<<(bad.size()));mask++){
            cnt[i+__builtin_popcount(mask)]=(cnt[i+__builtin_popcount(mask)]+dp[sz%2][i][mask])%mod;
        }
    }
    for (int i=0;i<=m;i++) cout<<(cnt[i]*res)%mod<<" ";
    cout<<endl;
    ///dp[i][j][mask]
    return 0;
}
//2 4 8
//1 1 0
/*
2 2
0 1
10 1
*/
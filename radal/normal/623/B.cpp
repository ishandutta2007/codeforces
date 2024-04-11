#include <bits/stdc++.h>
#pragma GCC target ("avx,avx2,fma")
#pragma GCC optimization ("O8")
#pragma GCC optimization ("unroll-loops")
#define X first
#define Y second
#define debug(x) cerr << #x << ": " << x << endl;
#define endl '\n'
#define pb push_back
#define rep(i,l,r) for (int i=l; i<r; i++)
#define repr(i,r,l) for (int i=r; i>=l; i--)
using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<ll,ll> pll;
const long long int N=1e6+10,mod = 2e18,inf=1e18,maxm = 1000;
const long double eps = 0.0001;
ll a[N],dp[N],pre[N],ed[N];
vector<int> tajz(ll val){
    int s = sqrt(val);
    vector <int> ve;
    rep(i,2,s+3){
        if (val%i == 0) ve.pb(i);
        while (val%i == 0) val /= i;
    }
    if (val > 1) ve.pb(val);
    return ve;
}
int main(){
    ll ans = inf;
    ll n,x,y;
    cin >> n >> x >> y;
    rep(i,0,n) cin >> a[i];
    vector <int> ve = tajz(a[0]);
    if (n == 1){
        cout << 0;
        return 0;
    }
    for (int u : ve){
        bool f = 0;
        pre[0] = 0;
        ed[0] = x;
        dp[0]  = 0;
        rep(i,1,n){
            if (dp[i-1] >= ans){
                dp[n-1] = ans;
                break;
            }
            if (a[i]%u == 0){
                pre[i] = pre[i-1];
                dp[i] = dp[i-1];
                if (!f) ed[i] = min(ed[i-1]+x,pre[i]*y+x);
                else ed[i] = ed[i-1]+x;
                continue;
            }
            pre[i] = pre[i-1]+1;
            if (!f) ed[i] = min(ed[i-1]+x,pre[i-1]*y+x);
            else ed[i] = ed[i-1]+x;
            if (a[i]%u == 1 || a[i]%u == u-1) dp[i] = min(dp[i-1]+y,ed[i]);
            else{
                f = 1;
                dp[i] = ed[i];
            }
        }
        ans = min(ans,dp[n-1]);
    }
    ve.clear();
    ve = tajz(a[0]+1);
    for (int u : ve){
        bool f = 0;
        pre[0] = 1;
        ed[0] = inf;
        dp[0]  = y;
        rep(i,1,n){
            if (a[i]%u == 0){
                pre[i] = pre[i-1];
                dp[i] = dp[i-1];
                if (!f) ed[i] = min(ed[i-1]+x,pre[i]*y+x);
                else ed[i] = ed[i-1]+x;
                continue;
            }
            pre[i] = pre[i-1]+1;
            if (!f) ed[i] = min(ed[i-1]+x,pre[i-1]*y+x);
            else ed[i] = ed[i-1]+x;
            if (a[i]%u == 1 || a[i]%u == u-1) dp[i] = min(dp[i-1]+y,ed[i]);
            else{
                f = 1;
                dp[i] = ed[i];
            }
        }
        ans = min(ans,dp[n-1]);
    }
    ve.clear();
    if (a[0] > 2){
        ve = tajz(a[0]-1);
        for (int u : ve){
            bool f = 0;
            pre[0] = 1;
            ed[0] = inf;
            dp[0]  = y;
            rep(i,1,n){
                if (a[i]%u == 0){
                    pre[i] = pre[i-1];
                    dp[i] = dp[i-1];
                    if (!f) ed[i] = min(ed[i-1]+x,pre[i]*y+x);
                    else ed[i] = ed[i-1]+x;
                    continue;
                }
                pre[i] = pre[i-1]+1;
                if (!f) ed[i] = min(ed[i-1]+x,pre[i-1]*y+x);
                else ed[i] = ed[i-1]+x;
                if (a[i]%u == 1 || a[i]%u == u-1) dp[i] = min(dp[i-1]+y,ed[i]);
                else{
                    f = 1;
                    dp[i] = ed[i];
                }
            }
            ans = min(ans,dp[n-1]);
        }
    }
    ve.clear();
    ve = tajz(a[n-1]);
    reverse(a,a+n);
    for (int u : ve){
        bool f = 0;
        pre[0] = 0;
        ed[0] = x;
        dp[0]  = 0;
        rep(i,1,n){
            if (a[i]%u == 0){
                pre[i] = pre[i-1];
                dp[i] = dp[i-1];
                if (!f) ed[i] = min(ed[i-1]+x,pre[i]*y+x);
                else ed[i] = ed[i-1]+x;
                continue;
            }
            pre[i] = pre[i-1]+1;
            if (!f) ed[i] = min(ed[i-1]+x,pre[i-1]*y+x);
            else ed[i] = ed[i-1]+x;
            if (a[i]%u == 1 || a[i]%u == u-1) dp[i] = min(dp[i-1]+y,ed[i]);
            else{
                f = 1;
                dp[i] = ed[i];
            }
        }
        ans = min(ans,dp[n-1]);
    }
    ve.clear();
    ve = tajz(a[0]+1);
    for (int u : ve){
        bool f = 0;
        pre[0] = 1;
        ed[0] = inf;
        dp[0]  = y;
        rep(i,1,n){
            if (a[i]%u == 0){
                pre[i] = pre[i-1];
                dp[i] = dp[i-1];
                if (!f) ed[i] = min(ed[i-1]+x,pre[i]*y+x);
                else ed[i] = ed[i-1]+x;
                continue;
            }
            pre[i] = pre[i-1]+1;
            if (!f) ed[i] = min(ed[i-1]+x,pre[i-1]*y+x);
            else ed[i] = ed[i-1]+x;
            if (a[i]%u == 1 || a[i]%u == u-1) dp[i] = min(dp[i-1]+y,ed[i]);
            else{
                f = 1;
                dp[i] = ed[i];
            }
        }
        ans = min(ans,dp[n-1]);
    }
    ve.clear();
    if (a[0] > 2){
        ve = tajz(a[0]-1);
        for (int u : ve){
            bool f = 0;
            pre[0] = 1;
            ed[0] = inf;
            dp[0]  = y;
            rep(i,1,n){
                if (a[i]%u == 0){
                    pre[i] = pre[i-1];
                    dp[i] = dp[i-1];
                    if (!f) ed[i] = min(ed[i-1]+x,pre[i]*y+x);
                    else ed[i] = ed[i-1]+x;
                    continue;
                }
                pre[i] = pre[i-1]+1;
                if (!f) ed[i] = min(ed[i-1]+x,pre[i-1]*y+x);
                else ed[i] = ed[i-1]+x;
                if (a[i]%u == 1 || a[i]%u == u-1) dp[i] = min(dp[i-1]+y,ed[i]);
                else{
                    f = 1;
                    dp[i] = ed[i];
                }
            }
            ans = min(ans,dp[n-1]);
        }
    }
    cout << ans;
    return 0;
}
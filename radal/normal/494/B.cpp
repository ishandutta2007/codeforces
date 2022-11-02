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
typedef pair<ll,ll> pll;
const long long int N=2e5+20,mod = 1e9+7,inf=1e18,dlt = 12250,maxm = 2e6;
int poww(ll a,int k){
    if (!k) return 1;
    if (k == 1) return a;
    ll r = poww(a,k/2);
    return (((r*r)%mod)*poww(a,k&1))%mod;
}
int f[N],l[N],dp[N],pre[N];
int main(){
    string s,t;
    cin >> s >> t;
    int n,m;
    n = s.size(),m = t.size();
    string w = t+'#'+s;
    int k = 0;
    f[0] = 0;
    rep(i,1,n+m+1){
        while (k && w[i] != w[k]) k = f[k-1];
        k += (w[i] == w[k]);
        f[i] = k;
    }
    l[0] = -1;
    rep(i,1,n+m+1){
        if (f[i] == m) l[i] = i;
        else l[i] = l[i-1];
    }
    dp[m] = 0;
    pre[m] = 0;
    rep(i,m+1,m+n+1){
        if(l[i] == -1){
            pre[i] = pre[i-1];
            continue;
        }
        dp[i] = pre[l[i]-m]+dp[i-1]+l[i]-2*m+1;
        dp[i] %= mod;
        pre[i] = pre[i-1]+dp[i];
        pre[i] %= mod;
    }
    cout << dp[n+m];
    return 0;
}
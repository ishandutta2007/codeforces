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
ll a[N];
ll pre[N];
bool mark[N];
int n;
int binary(ll val){
    if (a[0] > val) return -1;
    if (val >= a[n-1]) return n-1;
    int m,l = 0,r = n;
    while (r-l > 1){
        m = (l+r)/2;
        if (a[m] > val) r = m;
        else l = m;
    }
    return l;
}
int count(ll l,ll r){
    int u,v;
    v = binary(r);
    u = binary(l-1);
    return v-u;
}
int main(){
    ios :: sync_with_stdio(0);
    cin.tie(0);
    ll ans = inf;
    ll x,y,d;
    cin >> n >> x >> y;
    d = x/y;
    rep(i,0,n) cin >> a[i];
    sort(a,a+n);
    pre[0] = a[0];
    rep(i,1,n) pre[i] = pre[i-1]+a[i];
    vector<int> ve;
    ve.pb(2);
    for (int i = 3; i < N; i+=2){
        if (mark[i]) continue;
        ve.pb(i);
        for (int j = 2; j*i < N; j++) mark[j*i] = 1;
    }
    for (int i : ve){
        ll s = 0;
        ll k;
        if (d >= i) k = 1;
        else k = i-d;
        for (ll j = a[0]/i; j*i <= a[n-1]; j++){
            ll cnt = count(j*i+1,j*i+k-1),cnt2 = count(j*i+k,(j+1)*i-1);
            s += cnt*x;
            if (!cnt2) continue;
            ll l = binary(j*i+k-1);
            ll r = binary((j+1)*i-1);
            if (l==-1) s += y*(i*(j+1)*cnt2-pre[r]);
            else s += y*(i*(j+1)*cnt2-pre[r]+pre[l]);
        }
        ans = min(ans,s);
    }
    cout << ans;
}
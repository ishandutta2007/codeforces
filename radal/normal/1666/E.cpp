#include <bits/stdc++.h>
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2")
#pragma GCC optimize("unroll-loops")
#define rep(i,l,r) for (int i = l; i < r; i++)
#define repr(i,r,l) for (int i = r; i >= l; i--)
#define X first
#define Y second
#define pb push_back
#define endl '\n'
#define debug(x) cerr << #x << " : " << x << endl;
using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<ll,ll> pll;
constexpr int N = 3e5+20,mod = 1e9+7 ,inf = 1e9+10,maxm = (1 << 10)+10;
inline int mkay(int a,int b){
    if (a+b >= mod) return a+b-mod;
    if (a+b < 0) return a+b+mod;
    return a+b;
}
 
inline int poww(int a,int k){
    if (k < 0) return 0;
    int z = 1;
    while (k){
        if (k&1) z = 1ll*z*a%mod;
        a = 1ll*a*a%mod;
        k >>= 1;
    } 
    return z;
}
int a[N],n,x,L[N],R[N];
inline int bs1(){
    int l = 0,r = x,m;
    while(r-l > 1){
        m = (l+r) >> 1;
        bool f = 0;
        int cur = 0;
        rep(i,1,n+1){
            cur += m;
            if (cur > a[i]){
                f = 1;
                break;
            }
            cur = max(cur,a[i-1]);
        }
        if (f) r = m;
        else l = m;
    }
    return l;
}
inline int bs2(){
    int l = 0,r = x,m;
    while(r-l > 1){
        m = (l+r) >> 1;
        bool f = 0;
        int cur = 0;
        rep(i,0,n-1){
            cur += m;
            if (cur < a[i]){
                f = 1;
                break;
            }
            cur = min(cur,a[i+1]);
        }
        if (cur+m < x) f = 1;
        if (f) l = m;
        else r = m;
    }
    return r;
}
int main(){
    ios :: sync_with_stdio(0); cin.tie(0);
    cin >> x >> n;
    rep(i,0,n) cin >> a[i];
    a[n] = x;
    int mi = bs1(),mx = bs2(),cur[2] = {0,0};
    vector<int> ans;
    rep(i,1,n+1){
        cur[0] += mi;
        cur[1] += mx;
        cur[0] = max(cur[0],a[i-1]);
        cur[1] = min(cur[1],a[i]);
        L[i] = cur[0];
        R[i] = cur[1];
    }
    //cur[0] = cur[1] = x;
    ans.pb(x);
    repr(i,n-1,0){
        cur[1] = min(cur[1]-mi,R[i]);
        cur[0] = max(cur[0]-mx,L[i]);
        ans.pb(cur[1]);
    }
    repr(i,n,1) cout << ans[i] << ' ' << ans[i-1] << endl;

}
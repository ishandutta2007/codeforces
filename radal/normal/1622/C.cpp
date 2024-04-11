#include <bits/stdc++.h>
#pragma GCC optimize("O3")
#pragma GCC target("avx2,fma")
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
typedef pair<int,int> pll;
const long long int N = 2e5+20,mod = 1e9+7,inf = 4e18+10,sq = 400;
inline int mkay(int a,ll b){
    if (a+b >= mod) return a+b-mod;
    if (a+b < 0) return a+b+mod;
    return a+b;
}
inline int poww(int n,int k,int m){
    int c = 1;
    while (k){
        if (k&1) c = (1ll*c*n)%m;
        n = (1ll*n*n)%m;
        k >>= 1;
    }
    return c;
}
ll a[N];
ll suf[N];
int n;
ll k;
inline bool check(ll t){
    rep(i,0,n){
        if (i > t) break;
        ll s = suf[1]-suf[n-i];
        if (s+(a[0]-t+i)*(i+1) <= k) return 1;
    }
    return 0;
}
inline ll bs(){
    ll l = 0,r = 100000000000000000,m;
    while (r-l > 1){
        m = (l+r) >> 1;
        if (check(m)) r = m;
        else l = m;
    }
    return r;
}
int main(){
    ios :: sync_with_stdio(0); cin.tie(0);
    int T = 1;
    cin >> T;
    while(T--){
        cin >> n >> k;
        rep(i,0,n){
            cin >> a[i];
            suf[i] = 0;
        }
        suf[n] = 0;
        sort(a,a+n);
        repr(i,n-1,0){
            suf[i] = a[i]+suf[i+1];
        }
        if (suf[0] <= k){
            cout << 0 << endl;
            continue;
        }
        if (n == 1){
            cout << a[0]-k << endl;
            continue;
        }
        cout << bs() << endl;
    }
}
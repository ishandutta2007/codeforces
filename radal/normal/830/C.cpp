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
const long long int N = 1e7+20,mod = 1e9+7,inf = 1e18+10,sq = 32000;
inline int mkay(int a,int b){
    if (a+b >= mod) return a+b-mod;
    if (a+b < 0) return a+b+mod;
    return a+b;
}
inline int poww(int n,int k){
    int c = 1;
    while (k){
        if (k&1) c = (1ll*c*n)%mod;
        n = (1ll*n*n)%mod;
        k >>= 1;
    }
    return c;
}
int a[N],b[N];
int main(){
    ios :: sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n, p = 0;
    ll k;
    cin >> n >> k;
    rep(i,0,n){
        int x;
        cin >> x;
        b[i] = x;
        k += x;
        for(int j = 1; j*j <= x; j++){
            a[p] = (x+j-1)/j;
            p++;
            a[p] = j;
            p++;
        }
    }
    sort(a,a+p);
    p  = unique(a,a+p)-a;
    ll ans = 0;
    rep(i,0,p){
        ll s = 0;
        rep(j,0,n){
            s += (b[j]+a[i]-1)/a[i];
        }
        if (k/s >= a[i]) ans = max(ans,k/s);
    }
    cout << ans;
}
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
const long long int N = 2e5+20,mod = 1e9+7,inf = 1e9+10,sq = 300;
inline int mkay(int a,int b){
    if (a+b >= mod) return a+b-mod;
    if (a+b < 0) return a+b+mod;
    return a+b;
}
inline int poww(int a,int k){
    int z = 1;
    while (k){
        if (k&1) z = 1ll*z*a%mod;
        a = 1ll*a*a%mod;
        k >>= 1;
    }
    return z;
}
int a[N],n,k,b[N];
inline bool check(int x,int y){
    int ind = lower_bound(a,a+n,x)-a;
    int ind2 = upper_bound(a,a+n,y)-a;
    if (x == 11){
        debug(y);
        debug(ind);
        debug(ind2);
    }
    int t = ind2-ind;
    if (t-k >= n-t) return 1;
    else return 0;
}
inline int bs(int x){
    int l = x-1,r = n+1,m;
    while (r-l > 1){
        m = (l+r) >> 1;
        if (check(x,m)) r = m;
        else l = m;
    }
    return r;
}
void solve(){
    cin >> n >> k;
    rep(i,0,n){
        cin >> a[i];
        b[i] = a[i];
    }
    sort(a,a+n);
    int mi = inf,ans = -1;
    rep(x,1,n+1){
        int t = bs(x);
        if (!check(x,t)) break;
        if(t-x+1 < mi){
            ans = x;
            mi = t-x+1;
        }
    }
    cout << ans << ' ' << ans+mi-1 << endl;
    int l = 0,cnt = 0;
    while (l < n){
        if (cnt+1 == k){
            cout << l+1 << ' ' << n << endl;
            return;
        }
        int r = l,s = 0;
        while (s < 1){
            if (b[r] >= ans && b[r] < ans+mi) s++;
            else s--;
            r++;
        }
        cout << l+1 << ' ' << r << endl;
        l = r;
        cnt++;
    }
}
int main(){
    ios :: sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int T = 1;
    cin >> T;
    while (T--){
        solve();
    }
    return 0;
}
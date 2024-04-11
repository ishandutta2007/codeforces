#include <bits/stdc++.h>
//#pragma GCC target("sse,sse2,sse4,avx2")
#pragma GCC optimize("unroll-loops,O2")
#define rep(i,l,r) for (int i = l; i < r; i++)
#define repr(i,r,l) for (int i = r; i >= l; i--)
#define X first
#define Y second
#define all(x) (x).begin() , (x).end()
#define pb push_back
#define endl '\n'
#define debug(x) cerr << #x << " : " << x << endl;
using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int,int> pll;
constexpr int N = 4e5+20,mod = 1e9+7 ,inf = 1e9+10;
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

vector<int> taj[N];
int cnt[N];
inline ll cal(int v){
    return 1ll*v*(v-1)/2;
}
inline void solve(){
    int l,r;
    cin >> l >> r;
    rep(i,l,r+1){
        cnt[i] = upper_bound(all(taj[i]),r)-lower_bound(all(taj[i]),l);
    }
    ll ans = 1ll*(r-l+1)*(r-l)*(r-l-1)/6;
    rep(k,l,r+1){
        ans -= cal(cnt[k]-1);
        if (k%6 == 0 && k/2 >= l)
            ans--; // 2/3 2/4
        if (k%15 == 0 && 2*k/5 >= l)
            ans--;
    }
    cout << ans << endl;
}
int main(){
    ios_base :: sync_with_stdio(0); cin.tie(0);
    int T = 1;
    cin >> T;
    rep(i,1,N){
        for (int j = 1; j*i < N; j++)
            taj[j*i].pb(i);
    }
    while(T--){
        solve();
    }
}
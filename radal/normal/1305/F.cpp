#include <bits/stdc++.h>
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2")
#pragma GCC optimize("unroll-loops")
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
const int N = 2e5+20,mod = 1e9+7 ,inf = 1e9+10;
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
ll a[N];
int ans,n;
bool vis[N];
inline void f(ll x){
    ll cnt = 0;
    rep(i,0,n){
        if (a[i] > x) cnt += min(a[i]%x,x-a[i]%x);
        else cnt += x-a[i];
        if (cnt >= ans) break;
    }
    if (cnt < ans){
        ans = cnt;
        if (cnt == 1999) debug(x);
    }
}
inline void taj(ll x){
    for (int i = 2; 1ll*i*i <= x; i++){
        if (x % i == 0){
            f(i);
            while (x%i == 0) x /= i;
        }
    }
    if (x > 1) f(x);
}
int main(){
    ios :: sync_with_stdio(0); cin.tie(0);
    mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
    cin >> n;
    ans = n;
    set<ll> s;
    rep(i,0,n){
        cin >> a[i];
        s.insert(a[i]);
    }
    int mx = min((int)s.size(),30);
    set<ll> st;
    rep(j,0,mx){
        int ind = rng()%n;
        while (st.find(a[ind]) != st.end()) ind = rng()%n;
        st.insert(a[ind]);
        taj(a[ind]);
        taj(a[ind]+1);
        if (a[ind] > 2) taj(a[ind]-1);
    }
    cout << ans;
}
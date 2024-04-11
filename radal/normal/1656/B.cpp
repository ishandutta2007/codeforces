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
typedef pair<int,int> pll;

constexpr int N = 4e5+20,mod = 1e9+7,inf = 1e9+10,maxm = (1 << 18)+10;
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
        k /= 2;
    }
    return z;
}
int a[N];
set<int> st;
inline void solve(){
    int n,k;
    cin >> n >> k;
    st.clear();
    bool f = 0;
    rep(i,0,n){
        cin >> a[i];
        if (st.find(a[i]-k) != st.end()){
            f = 1;
        }
        if (st.find(a[i]+k) != st.end()){
            f = 1;
        }
        st.insert(a[i]);
    }
    if (!f){
        cout << "NO" << endl;
        return;
    }
    cout << "YES" << endl;

}
int main(){
    ios :: sync_with_stdio(0); cin.tie(0);
    int T = 1;
    cin  >> T;
    while (T--) solve();
}
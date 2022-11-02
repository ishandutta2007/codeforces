#include <bits/stdc++.h>
#pragma GCC target("sse,sse2,sse4,avx2")
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
constexpr int N = 2e5+20,mod = 1e9+7,inf = 1e9+10;
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
int pre[N],suf[N];
inline void solve(){
    int n;
    string s,t;
    cin >> n >> s >> t;
    ll ac[2] = {0,0},ca[2] = {0,0};
    int a[2] = {0,0},c[2] = {0,0};
    rep(i,0,n){
        if (s[i] == 'a'){ 
            pre[i] = 1;
            a[0]++;
            ca[0] += c[0];
        }
        else{
            pre[i] = 0;
            if (s[i] == 'c'){
                c[0]++;
                ac[0] += a[0];
            }
        }
        if (t[i] == 'a'){
            pre[i]--;
            a[1]++;
            ca[1] += c[1];
        }
        else if (t[i] == 'c'){
            c[1]++;
            ac[1] += a[1];
        }
        if (i){
            pre[i] += pre[i-1];
        }
        if (pre[i] < 0){
            cout << "NO" << endl;
            return;
        }
    }
    if (pre[n-1] != 0 || ac[0] != ac[1] || ca[0] != ca[1] || c[0] != c[1]){
        cout << "NO" << endl;
        return;
    }
    repr(i,n-1,0){
        if (s[i] == 'c')
            suf[i] = -1;
        else suf[i] = 0;
        if (t[i] == 'c') suf[i]++;
        if (i < n-1) suf[i] += suf[i+1];
        if (suf[i] > 0){
            cout << "NO" << endl;
            return;
        }
    }
    cout << "YES" << endl;
}
int main(){
    ios :: sync_with_stdio(0); cin.tie(0);
    int T = 1;
    cin >> T;
    while(T--){
        solve();
    }
}
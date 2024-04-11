#include <bits/stdc++.h>
//#pragma GCC target("sse,sse2,sse4")
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
constexpr int N = 5e5+20,mod = 1e9+7 ,inf = 1e9+10;
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
inline void solve(){
    int n,k,t = 0,lst = -1,mi = -1;
    string s;
    cin >> n >> k;
    cin >> s;
    rep(i,0,n){
        if (s[i] == '1'){
            t++;
            lst = i;
            if (mi == -1) mi = i;
        }
    }
    if (t == 0){
        cout << 0 << endl;
        return;
    }
    if (s[0] == '1' && s[n-1] == '1'){
        cout << (t-1)*11 << endl;
        return;
    }
    if (n-1-lst <= k){
        if (t == 1){
            cout << 1 << endl;
            return;
        }
        k -= (n-1-lst);
        if (mi <= k){
            cout << (t-1)*11 << endl;
            return;
        }
        cout << t*11-10 << endl;
        return;
    }
    if (mi <= k){
        cout << t*11-1 << endl;
        return;
    }
    cout << t*11 << endl;


}
int main(){
    ios :: sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int T;
    cin >> T;
    while (T--){
        solve();
    }
}
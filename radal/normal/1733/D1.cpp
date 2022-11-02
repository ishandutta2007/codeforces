#include <bits/stdc++.h>
//#pragma GCC target("sse,sse2")
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
constexpr int N = 1e5+15,mod = 1e9+7,inf = 1e9+10;
inline int mkay(int a,int b){
    if (a+b >= mod) return a+b-mod;
   // if (a+b < 0) return a+b+mod;
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
int a[N];
void solve(){
    int n,x,y;
    cin >> n >> x >> y;
    string s,t;
    cin >> s >> t;
    int cnt = 0;
    rep(i,0,n) if (s[i] != t[i]) cnt++;
    if (cnt%2){
        cout << -1 << endl;
        return;
    }
    if (cnt != 2){
        cout << 1ll*cnt/2*y << endl;
        return;
    }
    bool fl = 0;
    rep(i,1,n){
        if ((s[i] != t[i]) && (s[i-1] != t[i-1]))
            fl = 1;
    }
    if (!fl){
        cout << y << endl;
        return;
    }
    if (2*y >= x || n <= 3 || (n == 4 && s[1] != t[1] && s[2] != t[2])){
        cout << x << endl;
        return;
    }
    cout << 2*y << endl;
}

int main(){
    ios :: sync_with_stdio(0); cin.tie(0);
    int T = 1;
    cin >> T;
    while (T--){
        solve();
    }
    return 0;
}
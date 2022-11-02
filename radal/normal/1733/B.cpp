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
constexpr int N = 1e2+15,mod = 1e9+7,inf = 1e9+10;
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
void solve(){
    int n,x,y;
    cin >> n >> x >> y;
    if (x > y) swap(x,y);
    if (x >= 1 || !y || ((n-1)%y)){
        cout << -1 << endl;
        return;
    }
    int t = ((n-1)/y);
    int w = 1,cur = 2;
    rep(j,0,t){
        rep(i,0,y){
            cout << w << ' ';
            cur++;
        }
        w = cur;
    }
    cout << endl;
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
#include <bits/stdc++.h>
//#pragma GCC target("sse,sse2,avx2")
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
constexpr int N = 2e5+15,mod = 1e9+7,inf = 1e9+10;
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
    int c[3],r[3],n;
    cin >> n;
    rep(i,0,3) cin >> r[i] >> c[i];
    if ((r[0]+c[0])%2 != (r[1]+c[1])%2){
        if ((r[0]+c[0])%2 == (r[2]+c[2])%2){
            swap(r[1],r[2]);
            swap(c[1],c[2]);
        }
        else{
            swap(r[0],r[2]);
            swap(c[0],c[2]);
        }
    }
    int x,y;
    cin >> x >> y;
    if (x == r[2] || y == c[2]){
        cout << "YES" << endl;
        return;
    }
    if ((r[2] == 1 || r[2] == n) && (c[2] == 1 || c[2] == n)){
        cout << "NO" << endl;
        return;
    }
    if ((x+y)%2 == (r[0]+c[0])%2){
        cout << "YES" << endl;
        return;
    }
    cout << ((x%2 == r[2]%2) ? "YES" : "NO") << endl;
}

int main(){
    ios_base :: sync_with_stdio(0); cin.tie(0); 
    int T = 1;
    cin >> T;
    while (T--){
        solve();
    }
    return 0;
}